#ifndef OX88BOARD_H
#define OX88BOARD_H

#include "def.h"
#include <vector>
#include <string>
class OX88Board
{
    public:
        OX88Board();
        virtual ~OX88Board();
        void Move(MOVE m);
        void UnMove();
        void LoadFen(std::string fen);
        std::string Fen();
        bool SanityCheck();
        FLAGS At(OX88 where);
        OX88 IndexAt(OX88 where);
        FLAGS ToMove(){ return tomove;}
        void Clear();
        std::string CellName(OX88 square);
        OX88 WhiteKing(){ return w_king; }
        OX88 EpSquare(){ return ep_square; }
        OX88 BlackKing(){ return b_king; }
        int HalfMoveClock(){ return half_move_clock; }
        int FullMoveCount(){ return full_move_count; }
        FLAGS CastlingAvailability() { return castling_ability; }
        OX88* WhitePawns(int &count) { count=w_pawns.size(); return &w_pawns[0];}
        OX88* WhiteBishops(int &count) { count=w_bishops.size(); return &w_bishops[0];}
        OX88* WhiteKnights(int &count) { count=w_knights.size(); return &w_knights[0];}
        OX88* WhiteRooks(int &count) { count=w_rooks.size(); return &w_rooks[0];}
        OX88* WhiteQueens(int &count) { count=w_queens.size(); return &w_queens[0];}
        OX88* BlackPawns(int &count) { count=b_pawns.size(); return &b_pawns[0];}
        OX88* BlackBishops(int &count) { count=b_bishops.size(); return &b_bishops[0];}
        OX88* BlackKnights(int &count) { count=b_knights.size(); return &b_knights[0];}
        OX88* BlackRooks(int &count) { count=b_rooks.size(); return &b_rooks[0];}
        OX88* BlackQueens(int &count) { count=b_queens.size(); return &b_queens[0];}
    protected:

    private:
        //board array
        CELL_CONTENT board[128];
        //pieces locations
        std::vector<OX88> w_pawns;
        std::vector<OX88> b_pawns;
        std::vector<OX88> w_knights;
        std::vector<OX88> b_knights;
        std::vector<OX88> w_bishops;
        std::vector<OX88> b_bishops;
        std::vector<OX88> w_rooks;
        std::vector<OX88> b_rooks;
        std::vector<OX88> w_queens;
        std::vector<OX88> b_queens;
        OX88 w_king;
        OX88 b_king;
        FLAGS castling_ability;
        FLAGS tomove;
        OX88 ep_square;
        int half_move_clock;
        int full_move_count;
};

#endif // OX88BOARD_H
