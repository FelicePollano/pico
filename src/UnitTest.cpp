#include "UnitTest.h"
#include "OX88Board.h"
#include <assert.h>
#include <iostream>
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
    std::cout<<"test done.";
}
void UnitTest::fen_load_1()
{
    OX88Board board;
    board.LoadFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}
void UnitTest::check_empty()
{
    OX88Board board;

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

    assert(board.At(C1)==EMPTY);
    assert(board.At(C2)==EMPTY);
    assert(board.At(C3)==EMPTY);
    assert(board.At(C4)==EMPTY);
    assert(board.At(C5)==EMPTY);
    assert(board.At(C6)==EMPTY);
    assert(board.At(C7)==EMPTY);

    assert(board.At(D1)==EMPTY);
    assert(board.At(D2)==EMPTY);
    assert(board.At(D3)==EMPTY);
    assert(board.At(D4)==EMPTY);
    assert(board.At(D5)==EMPTY);
    assert(board.At(D6)==EMPTY);
    assert(board.At(D7)==EMPTY);

    assert(board.At(E1)==EMPTY);
    assert(board.At(E2)==EMPTY);
    assert(board.At(E3)==EMPTY);
    assert(board.At(E4)==EMPTY);
    assert(board.At(E5)==EMPTY);
    assert(board.At(E6)==EMPTY);
    assert(board.At(E7)==EMPTY);

    assert(board.At(F1)==EMPTY);
    assert(board.At(F2)==EMPTY);
    assert(board.At(F3)==EMPTY);
    assert(board.At(F4)==EMPTY);
    assert(board.At(F5)==EMPTY);
    assert(board.At(F6)==EMPTY);
    assert(board.At(F7)==EMPTY);

    assert(board.At(G1)==EMPTY);
    assert(board.At(G2)==EMPTY);
    assert(board.At(G3)==EMPTY);
    assert(board.At(G4)==EMPTY);
    assert(board.At(G5)==EMPTY);
    assert(board.At(G6)==EMPTY);
    assert(board.At(G7)==EMPTY);

    assert(board.At(H1)==EMPTY);
    assert(board.At(H2)==EMPTY);
    assert(board.At(H3)==EMPTY);
    assert(board.At(H4)==EMPTY);
    assert(board.At(H5)==EMPTY);
    assert(board.At(H6)==EMPTY);
    assert(board.At(H7)==EMPTY);

}
