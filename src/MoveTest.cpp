#include "OX88Board.h"
#include <assert.h>
#include <iostream>
#include "def.h"

#include <gtest/gtest.h>

TEST (MoveTest,e2e4_properly_converted)
{
    MOVE m = OX88Board::FromAlgebraic("e2e4");
    EXPECT_EQ(FROM(m),E2);
    EXPECT_EQ(TO(m),E4);
}
TEST (MoveTest,e2e4_properly_done)
{
    OX88Board board;
    board.Init();

    MOVE m = OX88Board::FromAlgebraic("e2e4");
    board.Move(m);
    EXPECT_EQ(board.Fen(),"rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1");
    EXPECT_TRUE(board.SanityCheck());
}
TEST (MoveTest,e2e4_properly_undone)
{
    OX88Board board;
    board.Init();

    MOVE m = OX88Board::FromAlgebraic("e2e4");
    board.Move(m);
    board.UnMove(m);
    EXPECT_EQ(board.Fen(),"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    EXPECT_TRUE(board.SanityCheck());
}

