#include "OX88Board.h"
#include <memory.h>

OX88Board::OX88Board()
{
    memset(board,0,128*sizeof(CELL_CONTENT));
}

OX88Board::~OX88Board()
{
    //dtor
}
void OX88Board::LoadFen(std::string fen)
{
    int rank = 7;//start with last rank
    int file=0;
    for( auto i=fen.begin();i!=fen.end();++i)
    {
        if(rank!=0 && file<8)
        {
            if(*i=='\\')
            {
                rank--; file=0;
            }
            else if(isdigit(*i))
            {
                file+=(int)(*i-0x30);
            }
            else
            {
                switch(*i)
                {
                case 'p':
                    board[TO_OX88(rank,file)]=(BLACK|PAWN);
                    break;
                case 'P':
                    board[TO_OX88(rank,file)]=(WHITE|PAWN);
                    break;
                case 'n':
                    board[TO_OX88(rank,file)]=(BLACK|KNIGHT);
                    break;
                case 'N':
                    board[TO_OX88(rank,file)]=(WHITE|KNIGHT);
                    break;
                case 'b':
                    board[TO_OX88(rank,file)]=(BLACK|BISHOP);
                    break;
                case 'B':
                    board[TO_OX88(rank,file)]=(WHITE|BISHOP);
                    break;
                case 'r':
                    board[TO_OX88(rank,file)]=(BLACK|ROOK);
                    break;
                case 'R':
                    board[TO_OX88(rank,file)]=(WHITE|ROOK);
                    break;
                case 'q':
                    board[TO_OX88(rank,file)]=(BLACK|PAWN);
                    break;
                case 'Q':
                    board[TO_OX88(rank,file)]=(WHITE|QUEEN);
                    break;
                case 'k':
                    board[TO_OX88(rank,file)]=(BLACK|KING);
                    break;
                case 'K':
                    board[TO_OX88(rank,file)]=(WHITE|KING);
                    break;
                }
                file++;
            }
        }
    }

}
CELL_CONTENT OX88Board::At(OX88 where)
{
    return board[where];
}
