#include "OX88Board.h"
#include <memory.h>
#include <sstream>
#include <regex>
#include "def.h"

OX88Board::OX88Board()
{
    Clear();
}

void OX88Board::Clear()
{
    memset(board,0,128*sizeof(CELL_CONTENT));
    castling_ability=0;
    ep_square.push(0);
    tomove=WHITE;
    full_move_count=1;
    half_move_clock=0;
}

OX88Board::~OX88Board()
{
    //dtor
}

/*
     Returns the algebraic name of a square by its 0x88 index.
*/
std::string OX88Board::CellName(OX88 square)
{
    char tmp[3];
    // 97 is lowercase a
    sprintf(tmp,"%c%d",(char)(97+FILE_OF(square)),RANK_OF(square)+1);
    return std::string(tmp);
}


/*
    Obtain the FEN string representing current board.
    FEN (Forsyth–Edwards Notation)  string is defined (for instance ) here: https://www.chessprogramming.org/Forsyth-Edwards_Notation
*/

std::string OX88Board::Fen()
{
    std::stringstream stream("");
    int bcount=0;
    for(int rank=7;rank>=0;rank--)
    {
        for(int file=0;file<8;file++)
        {
            auto p = At(TO_OX88(rank,file));
            if(p!=EMPTY && bcount)
            {
                stream.put(0x30+bcount);
                bcount = 0;
            }
            switch(p)
            {
            case WHITE|PAWN:
                stream<<"P";
                break;
            case BLACK|PAWN:
                stream<<"p";
                break;
             case WHITE|KNIGHT:
                stream<<"N";
                break;
            case BLACK|KNIGHT:
                stream<<"n";
                break;
            case WHITE|BISHOP:
                stream<<"B";
                break;
            case BLACK|BISHOP:
                stream<<"b";
                break;
            case WHITE|ROOK:
                stream<<"R";
                break;
            case BLACK|ROOK:
                stream<<"r";
                break;
            case WHITE|QUEEN:
                stream<<"Q";
                break;
            case BLACK|QUEEN:
                stream<<"q";
                break;
             case WHITE|KING:
                stream<<"K";
                break;
            case BLACK|KING:
                stream<<"k";
                break;
            default:
                bcount++;
            }
        }
        if(bcount)
        {
            stream.put(0x30+bcount);
            bcount = 0;
        }
        if( rank>0 )
            stream<<"/";
    }
    stream<<" ";
    // --side to move
    if(tomove==WHITE)
        stream<<"w";
    else
        stream<<"b";
    stream<<" ";
    // --castling ability
    if( castling_ability == 0)
        stream<<"-";
    else
    {
        if(castling_ability&W_CAN_CASTLE_SHORT)
            stream<<"K";
        if(castling_ability&W_CAN_CASTLE_LONG)
            stream<<"Q";

        if(castling_ability&B_CAN_CASTLE_SHORT)
            stream<<"k";
        if(castling_ability&B_CAN_CASTLE_LONG)
            stream<<"q";
    }
    stream<<" ";
    // --en passant square
    if(ep_square.top() == 0)
        stream <<"-";
    else
        stream<<CellName(ep_square.top());
    stream<<" ";
    // --half move clock
    stream<<half_move_clock;
    stream<<" ";
    // --full move count
    stream<<full_move_count;
    return stream.str();
}
/*
* performs a move specified in internal format
* no validity check but programmatically ones ( ie something to move in the location from exists )
* are done here. We expect game rules applied before coming at this point
*/
void OX88Board::Move(MOVE m)
{

    auto start = FROM(m);
    auto end   = TO(m);
    auto part = (board[start]);
    auto index = INDEX(board[start]); //where the part is in his own array?
    switch(PART_ONLY(part))
    {
    case PAWN:

        if(RANK_OF(start)==1 && tomove==WHITE && RANK_OF(end)==3 || RANK_OF(start)==6 && RANK_OF(end)==4 && tomove==BLACK )
        {
            if(tomove==WHITE)
                ep_square.push(TO_OX88(RANK_OF(start)+1,FILE_OF(start)));
            else
                ep_square.push(TO_OX88(RANK_OF(start)-1,FILE_OF(start)));
        }
        else
        {
            ep_square.push(0);
        }
        if(tomove==WHITE)
            w_pawns[index]=end;
        else
            b_pawns[index]=end;
        break;
    }
    board[start]=0; //remove original piece
    board[end]=part|TO_INDEX(index); //piece goes in new location
    if(tomove==WHITE)
        tomove=BLACK;
    else
    {
        tomove=WHITE;
        full_move_count++;
    }

}
/*
* this undo the move, keeping the board in the exact previous state
*/
void OX88Board::UnMove(MOVE m)
{
    ep_square.pop();
    auto start = TO(m);
    auto end   = FROM(m);
    auto part = PART(board[start]);
    auto index = INDEX(board[start]); //where the part is in his own array?
    switch(PART_ONLY(part))
    {
        case PAWN:
            if(tomove==BLACK)
                w_pawns[index]=end;
            else
                b_pawns[index]=end;
            break;
    }
    board[start]=0; //remove original piece
    board[end]=part|TO_INDEX(index); //piece goes in new location
    if(tomove==WHITE)
    {
        tomove=BLACK;
        full_move_count--;
    }
    else
        tomove=WHITE;
}
/*
* convert a move from various algebraic notations to a move in
* internal format.
*/
MOVE OX88Board::FromAlgebraic(std::string move)
{
    //long algebraic notation
    if(std::regex_match(move,std::regex("[abcdefgh][12345678][abcdefgh][12345678]")))
    {
        MOVE res = 0;
        res = TO_OX88(move[1]-49,move[0]-97);
        res |= (TO_OX88(move[3]-49,move[2]-97)<<8);
        return res;
    }
    else
    {
        throw "not supported move format (yet)";
    }
}
/*
* load the board with the default position
*/
void OX88Board::Init()
{
    LoadFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}

/*
    Initialize the board starting from a FEN string.
    FEN (Forsyth–Edwards Notation)  string is defined (for instance ) here: https://www.chessprogramming.org/Forsyth-Edwards_Notation
*/

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
    for( auto i=fen.begin();i!=fen.end();i++)
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
           break;
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
                    rank = *i-0x31;
                    if(rank<0 || rank > 7)
                        error = true;
                    else
                    {
                        ep_square.push(TO_OX88(rank,file));
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
                if(p&0x88)
                    throw "Invalid fen: cell location invalid.";
                switch(*i)
                {
                case 'p':
                    board[p]=(BLACK|PAWN);
                    b_pawns.push_back(p);
                    board[p]|=TO_INDEX(b_pawns.size()-1);
                    break;
                case 'P':
                    board[p]=(WHITE|PAWN);
                    w_pawns.push_back(p);
                    board[p]|=TO_INDEX(w_pawns.size()-1);
                    break;
                case 'n':
                    board[p]=(BLACK|KNIGHT);
                    b_knights.push_back(p);
                    board[p]|=TO_INDEX(b_knights.size()-1);
                    break;
                case 'N':
                    board[p]=(WHITE|KNIGHT);
                    w_knights.push_back(p);
                    board[p]|=TO_INDEX(w_knights.size()-1);
                    break;
                case 'b':
                    board[p]=(BLACK|BISHOP);
                    b_bishops.push_back(p);
                    board[p]|=TO_INDEX(b_bishops.size()-1);
                    break;
                case 'B':
                    board[p]=(WHITE|BISHOP);
                    w_bishops.push_back(p);
                    board[p]|=TO_INDEX(w_bishops.size()-1);
                    break;
                case 'r':
                    board[p]=(BLACK|ROOK);
                    b_rooks.push_back(p);
                    board[p]|=TO_INDEX(b_rooks.size()-1);
                    break;
                case 'R':
                    board[p]=(WHITE|ROOK);
                    w_rooks.push_back(p);
                    board[p]|=TO_INDEX(w_rooks.size()-1);
                    break;
                case 'q':
                    board[p]=(BLACK|QUEEN);
                    b_queens.push_back(p);
                    board[p]|=TO_INDEX(b_queens.size()-1);
                    break;
                case 'Q':
                    board[p]=(WHITE|QUEEN);
                    w_queens.push_back(p);
                    board[p]|=TO_INDEX(w_queens.size()-1);
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

/*
    Returns the piece at a location
*/
FLAGS OX88Board::At(OX88 where)
{
    return PART(board[where]);
}

/*
    Returns the reverse index of piece at a location
*/
OX88 OX88Board::IndexAt(OX88 where)
{
    return INDEX(board[where]);
}

/*
    Check if reverse indexing is consistent and
    the chessboard data are all consistent. Useful in unit testing
*/
bool OX88Board::SanityCheck()
{
    int w_pawns_count=0;
    int b_pawns_count=0;
    int w_knights_count=0;
    int b_knights_count=0;
    int w_bishops_count=0;
    int b_bishops_count=0;
    int w_rooks_count=0;
    int b_rooks_count=0;
    int w_queens_count=0;
    int b_queens_count=0;

    for(int rank=0;rank<8;rank++)
    {
        for(int file=0;file<8;file++)
        {
            auto part = At(TO_OX88(rank,file));
            OX88 rindex;
            switch(part)
            {
            case WHITE|PAWN:
                w_pawns_count++;
                rindex = IndexAt(TO_OX88(rank,file));

                if(w_pawns[rindex]!=TO_OX88(rank,file))
                {
                    fprintf(stderr,"inconsistency found at rank:%d file:%d - %d\n",rank,file,part);
                    return false;
                }
                break;
            case BLACK|PAWN:
                b_pawns_count++;
                rindex = IndexAt(TO_OX88(rank,file));

                if(b_pawns[rindex]!=TO_OX88(rank,file))
                {
                    fprintf(stderr,"inconsistency found at rank:%d file:%d - %d\n",rank,file,part);
                    return false;
                }
                break;

            case WHITE|KNIGHT:
                w_knights_count++;
                rindex = IndexAt(TO_OX88(rank,file));

                if(w_knights[rindex]!=TO_OX88(rank,file))
                {
                    fprintf(stderr,"inconsistency found at rank:%d file:%d - %d\n",rank,file,part);
                    return false;
                }
                break;
            case BLACK|KNIGHT:
                b_knights_count++;
                rindex = IndexAt(TO_OX88(rank,file));

                if(b_knights[rindex]!=TO_OX88(rank,file))
                {
                    fprintf(stderr,"inconsistency found at rank:%d file:%d - %d\n",rank,file,part);
                    return false;
                }
                break;
            case WHITE|BISHOP:
                w_bishops_count++;
                rindex = IndexAt(TO_OX88(rank,file));

                if(w_bishops[rindex]!=TO_OX88(rank,file))
                {
                    fprintf(stderr,"inconsistency found at rank:%d file:%d - %d\n",rank,file,part);
                    return false;
                }
                break;
            case BLACK|BISHOP:
                b_bishops_count++;
                rindex = IndexAt(TO_OX88(rank,file));

                if(b_bishops[rindex]!=TO_OX88(rank,file))
                {
                    fprintf(stderr,"inconsistency found at rank:%d file:%d - %d\n",rank,file,part);
                    return false;
                }
                break;
             case WHITE|ROOK:
                w_rooks_count++;
                rindex = IndexAt(TO_OX88(rank,file));

                if(w_rooks[rindex]!=TO_OX88(rank,file))
                {
                    fprintf(stderr,"inconsistency found at rank:%d file:%d - %d\n",rank,file,part);
                    return false;
                }
                break;
            case BLACK|ROOK:
                b_rooks_count++;
                rindex = IndexAt(TO_OX88(rank,file));

                if(b_rooks[rindex]!=TO_OX88(rank,file))
                {
                    fprintf(stderr,"inconsistency found at rank:%d file:%d - %d\n",rank,file,part);
                    return false;
                }
                break;
             case WHITE|QUEEN:
                w_queens_count++;
                rindex = IndexAt(TO_OX88(rank,file));

                if(w_queens[rindex]!=TO_OX88(rank,file))
                {
                    fprintf(stderr,"inconsistency found at rank:%d file:%d - %d\n",rank,file,part);
                    return false;
                }
                break;
            case BLACK|QUEEN:
                b_queens_count++;
                rindex = IndexAt(TO_OX88(rank,file));

                if(b_queens[rindex]!=TO_OX88(rank,file))
                {
                    fprintf(stderr,"inconsistency found at rank:%d file:%d - %d\n",rank,file,part);
                    return false;
                }
                break;

            }
        }
    }

    if(w_pawns_count!=w_pawns.size())
    {
        fprintf(stderr,"inconsistency: pawns found on board %d, pawns stored count %d\n",w_pawns_count,w_pawns.size());
        return false;
    }
    if(b_pawns_count!=b_pawns.size())
    {
        fprintf(stderr,"inconsistency: pawns found on board %d, pawns stored count %d\n",b_pawns_count,b_pawns.size());
        return false;
    }
    if(w_bishops_count!=w_bishops.size())
    {
        fprintf(stderr,"inconsistency: bishop found on board %d, bishops stored count %d\n",w_bishops_count,w_bishops.size());
        return false;
    }
    if(b_bishops_count!=b_bishops.size())
    {
        fprintf(stderr,"inconsistency: bishop found on board %d, bishops stored count %d\n",b_bishops_count,b_bishops.size());
        return false;
    }
    if(w_knights_count!=w_knights.size())
    {
        fprintf(stderr,"inconsistency: knights found on board %d, knights stored count %d\n",w_knights_count,w_knights.size());
        return false;
    }
    if(b_knights_count!=b_knights.size())
    {
        fprintf(stderr,"inconsistency: bishop found on board %d, bishops stored count %d\n",b_knights_count,b_knights.size());
        return false;
    }
    if(w_rooks_count!=w_rooks.size())
    {
        fprintf(stderr,"inconsistency: rooks found on board %d, rooks stored count %d\n",w_rooks_count,w_rooks.size());
        return false;
    }
    if(b_rooks_count!=b_rooks.size())
    {
        fprintf(stderr,"inconsistency: rooks found on board %d, rooks stored count %d\n",b_rooks_count,b_rooks.size());
        return false;
    }
    if(w_queens_count!=w_queens.size())
    {
        fprintf(stderr,"inconsistency: queens found on board %d, rooks stored count %d\n",w_queens_count,w_queens.size());
        return false;
    }
    if(b_queens_count!=b_queens.size())
    {
        fprintf(stderr,"inconsistency: queens found on board %d, rooks stored count %d\n",b_queens_count,b_queens.size());
        return false;
    }


    return true;
}
