#include "OX88Board.h"
#include <assert.h>
#include <iostream>
#include "def.h"

#include <gtest/gtest.h>

TEST (MoveTest,e2e4properlyconverted)
{
    MOVE m = OX88Board::FromAlgebraic("e2e4");
    EXPECT_EQ(FROM(m),E2);
    EXPECT_EQ(TO(m),E4);

}
