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
        void LoadFen(std::string fen);
        CELL_CONTENT At(OX88 where);
        void Clear();

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
