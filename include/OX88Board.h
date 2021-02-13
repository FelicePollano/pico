#ifndef OX88BOARD_H
#define OX88BOARD_H

#include "def.h"
#include <vector>

class OX88Board
{
    public:
        OX88Board();
        virtual ~OX88Board();

    protected:

    private:

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
};

#endif // OX88BOARD_H
