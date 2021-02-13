#include "UnitTest.h"
#include "OX88Board.h"
#include <assert.h>
UnitTest::UnitTest()
{

}

UnitTest::~UnitTest()
{

}

void UnitTest::Run()
{
    check_empty();
    fen_load_1();
}
void UnitTest::fen_load_1()
{

}
void UnitTest::check_empty()
{
    OX88Board board;
    board.At(A1);
    assert(board.At(A1)==EMPTY);
    assert(board.At(A2)==EMPTY);
    assert(board.At(A3)==EMPTY);
    assert(board.At(A4)==EMPTY);
    assert(board.At(A5)==EMPTY);
    assert(board.At(A6)==EMPTY);
    assert(board.At(A7)==EMPTY);

    assert(board.At(B1)==EMPTY);
    assert(board.At(B2)==EMPTY);
    assert(board.At(B3)==EMPTY);
    assert(board.At(B4)==EMPTY);
    assert(board.At(B5)==EMPTY);
    assert(board.At(B6)==EMPTY);
    assert(board.At(B7)==EMPTY);
}
