#include "UnitTest.h"
#include "OX88Board.h"
#include <assert.h>
#include <iostream>
#include <chrono>


UnitTest::UnitTest()
{

}

UnitTest::~UnitTest()
{

}

void UnitTest::Run()
{
    auto start = std::chrono::steady_clock::now();

    check_empty();
    fen_load_1();
    fen_load_2();
    fen_load_3();

    auto end = std::chrono::steady_clock::now();

    std::cout<<"test done. " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout<<" ms.\n";
}
void UnitTest::fen_load_1()
{
    OX88Board board;
    board.LoadFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    assert(board.SanityCheck());

    assert(board.At(A1)==WHITE|ROOK);
    assert(board.At(B1)==WHITE|KNIGHT);
    assert(board.At(C1)==WHITE|BISHOP);
    assert(board.At(D1)==WHITE|QUEEN);
    assert(board.At(E1)==WHITE|KING);
    assert(board.At(F1)==WHITE|BISHOP);
    assert(board.At(G1)==WHITE|KNIGHT);
    assert(board.At(H1)==WHITE|ROOK);
    assert(board.At(A2)==WHITE|ROOK);
    assert(board.At(B2)==WHITE|PAWN);
    assert(board.At(C2)==WHITE|PAWN);
    assert(board.At(D2)==WHITE|PAWN);
    assert(board.At(E2)==WHITE|PAWN);
    assert(board.At(F2)==WHITE|PAWN);
    assert(board.At(G2)==WHITE|PAWN);
    assert(board.At(H2)==WHITE|PAWN);

    assert(board.At(A3)==EMPTY);
    assert(board.At(B3)==EMPTY);
    assert(board.At(C3)==EMPTY);
    assert(board.At(D3)==EMPTY);
    assert(board.At(E3)==EMPTY);
    assert(board.At(F3)==EMPTY);
    assert(board.At(G3)==EMPTY);
    assert(board.At(H3)==EMPTY);

    assert(board.At(A4)==EMPTY);
    assert(board.At(B4)==EMPTY);
    assert(board.At(C4)==EMPTY);
    assert(board.At(D4)==EMPTY);
    assert(board.At(E4)==EMPTY);
    assert(board.At(F4)==EMPTY);
    assert(board.At(G4)==EMPTY);
    assert(board.At(H4)==EMPTY);

    assert(board.At(A5)==EMPTY);
    assert(board.At(B5)==EMPTY);
    assert(board.At(C5)==EMPTY);
    assert(board.At(D5)==EMPTY);
    assert(board.At(E5)==EMPTY);
    assert(board.At(F5)==EMPTY);
    assert(board.At(G5)==EMPTY);
    assert(board.At(H5)==EMPTY);

    assert(board.At(A6)==EMPTY);
    assert(board.At(B6)==EMPTY);
    assert(board.At(C6)==EMPTY);
    assert(board.At(D6)==EMPTY);
    assert(board.At(E6)==EMPTY);
    assert(board.At(F6)==EMPTY);
    assert(board.At(G6)==EMPTY);
    assert(board.At(H6)==EMPTY);

    assert(board.At(A8)==BLACK|ROOK);
    assert(board.At(B8)==BLACK|KNIGHT);
    assert(board.At(C8)==BLACK|BISHOP);
    assert(board.At(D8)==BLACK|QUEEN);
    assert(board.At(E8)==BLACK|KING);
    assert(board.At(F8)==BLACK|BISHOP);
    assert(board.At(G8)==BLACK|KNIGHT);
    assert(board.At(H8)==BLACK|ROOK);
    assert(board.At(A7)==BLACK|ROOK);
    assert(board.At(B7)==BLACK|PAWN);
    assert(board.At(C7)==BLACK|PAWN);
    assert(board.At(D7)==BLACK|PAWN);
    assert(board.At(E7)==BLACK|PAWN);
    assert(board.At(F7)==BLACK|PAWN);
    assert(board.At(G7)==BLACK|PAWN);
    assert(board.At(H7)==BLACK|PAWN);

    int count;

    auto w_pawns = board.WhitePawns(count);
    assert(count==8);
    assert(w_pawns[0] == A2);
    assert(w_pawns[1] == B2);
    assert(w_pawns[2] == C2);
    assert(w_pawns[3] == D2);
    assert(w_pawns[4] == E2);
    assert(w_pawns[5] == F2);
    assert(w_pawns[6] == G2);
    assert(w_pawns[7] == H2);

    auto b_pawns = board.BlackPawns(count);
    assert(count==8);
    assert(b_pawns[0] == A7);
    assert(b_pawns[1] == B7);
    assert(b_pawns[2] == C7);
    assert(b_pawns[3] == D7);
    assert(b_pawns[4] == E7);
    assert(b_pawns[5] == F7);
    assert(b_pawns[6] == G7);
    assert(b_pawns[7] == H7);

    auto w_rooks = board.WhiteRooks(count);
    assert(count==2);
    assert(w_rooks[0] == A1);
    assert(w_rooks[1] == H1);

    auto b_rooks = board.BlackRooks(count);
    assert(count==2);
    assert(b_rooks[0] == A8);
    assert(b_rooks[1] == H8);

    auto w_bishops = board.WhiteBishops(count);
    assert(count==2);
    assert(w_bishops[0] == C1);
    assert(w_bishops[1] == F1);

    auto b_bishops = board.BlackBishops(count);
    assert(count==2);
    assert(b_bishops[0] == C8);
    assert(b_bishops[1] == F8);

    auto w_knights = board.WhiteKnights(count);
    assert(count==2);
    assert(w_knights[0] == B1);
    assert(w_knights[1] == G1);

    auto b_knights = board.BlackKnights(count);
    assert(count==2);
    assert(b_knights[0] == B8);
    assert(b_knights[1] == G8);

    auto w_queens = board.WhiteQueens(count);
    assert(count==1);
    assert(w_queens[0] == D1);

    auto b_queens = board.BlackQueens(count);
    assert(count==1);
    assert(b_queens[0] == D8);

    assert(board.WhiteKing()==E1);
    assert(board.BlackKing()==E8);

    assert(board.EpSquare()==0);
    assert(board.CastlingAvailability()==W_CAN_CASTLE_LONG|W_CAN_CASTLE_SHORT|B_CAN_CASTLE_LONG|B_CAN_CASTLE_SHORT);
    assert(board.HalfMoveClock()==0);
    assert(board.FullMoveCount()==1);

}

void UnitTest::fen_load_2()
{
    OX88Board board;
    board.LoadFen("rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1");

    assert(board.SanityCheck());

    assert(board.At(A1)==WHITE|ROOK);
    assert(board.At(B1)==WHITE|KNIGHT);
    assert(board.At(C1)==WHITE|BISHOP);
    assert(board.At(D1)==WHITE|QUEEN);
    assert(board.At(E1)==WHITE|KING);
    assert(board.At(F1)==WHITE|BISHOP);
    assert(board.At(G1)==WHITE|KNIGHT);
    assert(board.At(H1)==WHITE|ROOK);
    assert(board.At(A2)==WHITE|ROOK);
    assert(board.At(B2)==WHITE|PAWN);
    assert(board.At(C2)==WHITE|PAWN);
    assert(board.At(D2)==WHITE|PAWN);
    assert(board.At(E2)==EMPTY);
    assert(board.At(F2)==WHITE|PAWN);
    assert(board.At(G2)==WHITE|PAWN);
    assert(board.At(H2)==WHITE|PAWN);

    assert(board.At(A3)==EMPTY);
    assert(board.At(B3)==EMPTY);
    assert(board.At(C3)==EMPTY);
    assert(board.At(D3)==EMPTY);
    assert(board.At(E3)==EMPTY);
    assert(board.At(F3)==EMPTY);
    assert(board.At(G3)==EMPTY);
    assert(board.At(H3)==EMPTY);

    assert(board.At(A4)==EMPTY);
    assert(board.At(B4)==EMPTY);
    assert(board.At(C4)==EMPTY);
    assert(board.At(D4)==EMPTY);
    assert(board.At(E4)==WHITE|PAWN);
    assert(board.At(F4)==EMPTY);
    assert(board.At(G4)==EMPTY);
    assert(board.At(H4)==EMPTY);

    assert(board.At(A5)==EMPTY);
    assert(board.At(B5)==EMPTY);
    assert(board.At(C5)==EMPTY);
    assert(board.At(D5)==EMPTY);
    assert(board.At(E5)==EMPTY);
    assert(board.At(F5)==EMPTY);
    assert(board.At(G5)==EMPTY);
    assert(board.At(H5)==EMPTY);

    assert(board.At(A6)==EMPTY);
    assert(board.At(B6)==EMPTY);
    assert(board.At(C6)==EMPTY);
    assert(board.At(D6)==EMPTY);
    assert(board.At(E6)==EMPTY);
    assert(board.At(F6)==EMPTY);
    assert(board.At(G6)==EMPTY);
    assert(board.At(H6)==EMPTY);

    assert(board.At(A8)==BLACK|ROOK);
    assert(board.At(B8)==BLACK|KNIGHT);
    assert(board.At(C8)==BLACK|BISHOP);
    assert(board.At(D8)==BLACK|QUEEN);
    assert(board.At(E8)==BLACK|KING);
    assert(board.At(F8)==BLACK|BISHOP);
    assert(board.At(G8)==BLACK|KNIGHT);
    assert(board.At(H8)==BLACK|ROOK);
    assert(board.At(A7)==BLACK|ROOK);
    assert(board.At(B7)==BLACK|PAWN);
    assert(board.At(C7)==BLACK|PAWN);
    assert(board.At(D7)==BLACK|PAWN);
    assert(board.At(E7)==BLACK|PAWN);
    assert(board.At(F7)==BLACK|PAWN);
    assert(board.At(G7)==BLACK|PAWN);
    assert(board.At(H7)==BLACK|PAWN);

    int count;

    auto w_pawns = board.WhitePawns(count);
    assert(count==8);
    assert(w_pawns[0] == E4);
    assert(w_pawns[1] == A2);
    assert(w_pawns[2] == B2);
    assert(w_pawns[3] == C2);
    assert(w_pawns[5] == F2);
    assert(w_pawns[6] == G2);
    assert(w_pawns[7] == H2);

    auto b_pawns = board.BlackPawns(count);
    assert(count==8);
    assert(b_pawns[0] == A7);
    assert(b_pawns[1] == B7);
    assert(b_pawns[2] == C7);
    assert(b_pawns[3] == D7);
    assert(b_pawns[4] == E7);
    assert(b_pawns[5] == F7);
    assert(b_pawns[6] == G7);
    assert(b_pawns[7] == H7);

    auto w_rooks = board.WhiteRooks(count);
    assert(count==2);
    assert(w_rooks[0] == A1);
    assert(w_rooks[1] == H1);

    auto b_rooks = board.BlackRooks(count);
    assert(count==2);
    assert(b_rooks[0] == A8);
    assert(b_rooks[1] == H8);

    auto w_bishops = board.WhiteBishops(count);
    assert(count==2);
    assert(w_bishops[0] == C1);
    assert(w_bishops[1] == F1);

    auto b_bishops = board.BlackBishops(count);
    assert(count==2);
    assert(b_bishops[0] == C8);
    assert(b_bishops[1] == F8);

    auto w_knights = board.WhiteKnights(count);
    assert(count==2);
    assert(w_knights[0] == B1);
    assert(w_knights[1] == G1);

    auto b_knights = board.BlackKnights(count);
    assert(count==2);
    assert(b_knights[0] == B8);
    assert(b_knights[1] == G8);

    auto w_queens = board.WhiteQueens(count);
    assert(count==1);
    assert(w_queens[0] == D1);

    auto b_queens = board.BlackQueens(count);
    assert(count==1);
    assert(b_queens[0] == D8);

    assert(board.WhiteKing()==E1);
    assert(board.BlackKing()==E8);

    assert(board.EpSquare()==E3);
    assert(board.CastlingAvailability()==W_CAN_CASTLE_LONG|W_CAN_CASTLE_SHORT|B_CAN_CASTLE_LONG|B_CAN_CASTLE_SHORT);
    assert(board.HalfMoveClock()==0);
    assert(board.FullMoveCount()==1);

}

void UnitTest::fen_load_3()
{
    OX88Board board;
    board.LoadFen("rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2");

    assert(board.SanityCheck());

    assert(board.At(A1)==WHITE|ROOK);
    assert(board.At(B1)==WHITE|KNIGHT);
    assert(board.At(C1)==WHITE|BISHOP);
    assert(board.At(D1)==WHITE|QUEEN);
    assert(board.At(E1)==WHITE|KING);
    assert(board.At(F1)==WHITE|BISHOP);
    assert(board.At(G1)==WHITE|KNIGHT);
    assert(board.At(H1)==WHITE|ROOK);
    assert(board.At(A2)==WHITE|ROOK);
    assert(board.At(B2)==WHITE|PAWN);
    assert(board.At(C2)==WHITE|PAWN);
    assert(board.At(D2)==WHITE|PAWN);
    assert(board.At(E2)==EMPTY);
    assert(board.At(F2)==WHITE|PAWN);
    assert(board.At(G2)==WHITE|PAWN);
    assert(board.At(H2)==WHITE|PAWN);

    assert(board.At(A3)==EMPTY);
    assert(board.At(B3)==EMPTY);
    assert(board.At(C3)==EMPTY);
    assert(board.At(D3)==EMPTY);
    assert(board.At(E3)==EMPTY);
    assert(board.At(F3)==EMPTY);
    assert(board.At(G3)==EMPTY);
    assert(board.At(H3)==EMPTY);

    assert(board.At(A4)==EMPTY);
    assert(board.At(B4)==EMPTY);
    assert(board.At(C4)==EMPTY);
    assert(board.At(D4)==EMPTY);
    assert(board.At(E4)==WHITE|PAWN);
    assert(board.At(F4)==EMPTY);
    assert(board.At(G4)==EMPTY);
    assert(board.At(H4)==EMPTY);

    assert(board.At(A5)==EMPTY);
    assert(board.At(B5)==EMPTY);
    assert(board.At(C5)==BLACK|PAWN);
    assert(board.At(D5)==EMPTY);
    assert(board.At(E5)==EMPTY);
    assert(board.At(F5)==EMPTY);
    assert(board.At(G5)==EMPTY);
    assert(board.At(H5)==EMPTY);

    assert(board.At(A6)==EMPTY);
    assert(board.At(B6)==EMPTY);
    assert(board.At(C6)==EMPTY);
    assert(board.At(D6)==EMPTY);
    assert(board.At(E6)==EMPTY);
    assert(board.At(F6)==EMPTY);
    assert(board.At(G6)==EMPTY);
    assert(board.At(H6)==EMPTY);

    assert(board.At(A8)==BLACK|ROOK);
    assert(board.At(B8)==BLACK|KNIGHT);
    assert(board.At(C8)==BLACK|BISHOP);
    assert(board.At(D8)==BLACK|QUEEN);
    assert(board.At(E8)==BLACK|KING);
    assert(board.At(F8)==BLACK|BISHOP);
    assert(board.At(G8)==BLACK|KNIGHT);
    assert(board.At(H8)==BLACK|ROOK);
    assert(board.At(A7)==BLACK|ROOK);
    assert(board.At(B7)==BLACK|PAWN);
    assert(board.At(C7)==EMPTY);
    assert(board.At(D7)==BLACK|PAWN);
    assert(board.At(E7)==BLACK|PAWN);
    assert(board.At(F7)==BLACK|PAWN);
    assert(board.At(G7)==BLACK|PAWN);
    assert(board.At(H7)==BLACK|PAWN);

    int count;

    auto w_pawns = board.WhitePawns(count);
    assert(count==8);
    assert(w_pawns[0] == E4);
    assert(w_pawns[1] == A2);
    assert(w_pawns[2] == B2);
    assert(w_pawns[3] == C2);
    assert(w_pawns[5] == F2);
    assert(w_pawns[6] == G2);
    assert(w_pawns[7] == H2);

    auto b_pawns = board.BlackPawns(count);
    assert(count==8);
    assert(b_pawns[0] == A7);
    assert(b_pawns[1] == B7);
    assert(b_pawns[2] == D7);
    assert(b_pawns[3] == E7);
    assert(b_pawns[4] == F7);
    assert(b_pawns[5] == G7);
    assert(b_pawns[6] == H7);
    assert(b_pawns[7] == C5);

    auto w_rooks = board.WhiteRooks(count);
    assert(count==2);
    assert(w_rooks[0] == A1);
    assert(w_rooks[1] == H1);

    auto b_rooks = board.BlackRooks(count);
    assert(count==2);
    assert(b_rooks[0] == A8);
    assert(b_rooks[1] == H8);

    auto w_bishops = board.WhiteBishops(count);
    assert(count==2);
    assert(w_bishops[0] == C1);
    assert(w_bishops[1] == F1);

    auto b_bishops = board.BlackBishops(count);
    assert(count==2);
    assert(b_bishops[0] == C8);
    assert(b_bishops[1] == F8);

    auto w_knights = board.WhiteKnights(count);
    assert(count==2);
    assert(w_knights[0] == B1);
    assert(w_knights[1] == G1);

    auto b_knights = board.BlackKnights(count);
    assert(count==2);
    assert(b_knights[0] == B8);
    assert(b_knights[1] == G8);

    auto w_queens = board.WhiteQueens(count);
    assert(count==1);
    assert(w_queens[0] == D1);

    auto b_queens = board.BlackQueens(count);
    assert(count==1);
    assert(b_queens[0] == D8);

    assert(board.WhiteKing()==E1);
    assert(board.BlackKing()==E8);

    assert(board.EpSquare()==C6);
    assert(board.CastlingAvailability()==W_CAN_CASTLE_LONG|W_CAN_CASTLE_SHORT|B_CAN_CASTLE_LONG|B_CAN_CASTLE_SHORT);
    assert(board.HalfMoveClock()==0);
    assert(board.FullMoveCount()==2);

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
