#include "OX88Board.h"
#include <memory.h>

OX88Board::OX88Board()
{
    Clear();
}

void OX88Board::Clear()
{
    memset(board,0,128*sizeof(CELL_CONTENT));
    castling_ability=0;
    ep_square =0;
    tomove=WHITE;
    full_move_count=1;
    half_move_clock=0;
}

OX88Board::~OX88Board()
{
    //dtor
}



void OX88Board::LoadFen(std::string fen)
{
    const int PIECES=0;
    const int SIDE_TO_MOVE=1;
    const int CASTLING_ABILITY=2;
    const int EN_PASSANT_SQUARE=3;
    const int HALF_MOVE_CLOCK=4;
    const int FULL_MOVES=5;


    int rank = 7;//start with last rank
    int file=0;
    int topic = 0;
    for( auto i=fen.begin();i!=fen.end();++i)
    {
        if(*i==' ') // next chunk
        {
            topic++;
            continue;
        }
        if(topic==SIDE_TO_MOVE)
        {
            switch(*i)
            {
            case 'w':
                tomove=WHITE;
                break;
            case 'b':
                tomove=BLACK;
                break;
            default:
                throw "Invalid fen: side to move not valid.";
            }
        }
        if(topic==FULL_MOVES)
        {
           std::string str = std::string(i,fen.end());
           if(str.empty())
                throw "Invalid fen: full moves count not valid";
           full_move_count=std::stoi(str);
        }
        if(topic==HALF_MOVE_CLOCK)
        {
           auto space = std::string(i,fen.end()).find(' ');
           std::string str = std::string(i,i+space);
           if(str.empty())
                throw  "Invalid fen: half move clock not valid";
           half_move_clock=std::stoi(str);
           i+=space;
           topic++;
        }
        if(topic==EN_PASSANT_SQUARE)
        {
            bool error=false;

            if(*i!='-')
            {
                int file = *i-97; //lowercase a
                ++i;

                if(i==fen.end() || file>7 || file < 0 )
                    error = true;
                if(!error)
                {
                    rank = *i-0x30;
                    if(rank<0 || rank > 7)
                        error = true;
                    else
                    {
                        ep_square=TO_OX88(rank,file);
                    }
            }
            if(error)
                throw "Invalid fen: en passant square not valid";
            }
        }
        if(topic == CASTLING_ABILITY)
        {
            do{
                switch(*i)
                {
                case 'k':
                    castling_ability|=B_CAN_CASTLE_SHORT;
                    break;
                case 'K':
                    castling_ability|=W_CAN_CASTLE_SHORT;
                    break;
                case 'q':
                    castling_ability|=B_CAN_CASTLE_LONG;
                    break;
                case 'Q':
                    castling_ability|=W_CAN_CASTLE_LONG;
                    break;
                case '-':
                    break;
                default:
                    throw "Invalid fen: castling specification not valid";
                }
                i++;
            }
            while(i!=fen.end() && *i!=' ');
            topic++; //next chunk
        }
        if(topic == PIECES)
        {
            if(*i=='/')
            {
                rank--; file=0;
            }
            else if(isdigit(*i))
            {
                if(*i=='0'||*i=='9')
                {
                    throw "Invalid fen: skip digit 0 or greater than 8";
                }
                file+=(int)(*i-0x30);
            }
            else
            {
                OX88 p = TO_OX88(rank,file);
                switch(*i)
                {
                case 'p':
                    board[p]=(BLACK|PAWN);
                    b_pawns.push_back(p);
                    break;
                case 'P':
                    board[p]=(WHITE|PAWN);
                    w_pawns.push_back(p);
                    break;
                case 'n':
                    board[p]=(BLACK|KNIGHT);
                    b_knights.push_back(p);
                    break;
                case 'N':
                    board[p]=(WHITE|KNIGHT);
                    w_knights.push_back(p);
                    break;
                case 'b':
                    board[p]=(BLACK|BISHOP);
                    b_bishops.push_back(p);
                    break;
                case 'B':
                    board[p]=(WHITE|BISHOP);
                    w_bishops.push_back(p);
                    break;
                case 'r':
                    board[p]=(BLACK|ROOK);
                    b_rooks.push_back(p);
                    break;
                case 'R':
                    board[p]=(WHITE|ROOK);
                    w_rooks.push_back(p);
                    break;
                case 'q':
                    board[p]=(BLACK|PAWN);
                    b_queens.push_back(p);
                    break;
                case 'Q':
                    board[p]=(WHITE|QUEEN);
                    w_queens.push_back(p);
                    break;
                case 'k':
                    board[p]=(BLACK|KING);
                    b_king=p;
                    break;
                case 'K':
                    board[p]=(WHITE|KING);
                    w_king=p;
                    break;
                default:
                    throw "Invalid fen: piece positioning not valid";
                }
                file++;
            }
        }
    }
    if(topic!=FULL_MOVES)
        throw "Invalid fen: part missing.";
    if(full_move_count<=0)
        throw "Invalid fen: full move count not valid.";
     if(half_move_clock<0)
        throw "Invalid fen: half move clock not valid.";
}
CELL_CONTENT OX88Board::At(OX88 where)
{
    return board[where];
}
