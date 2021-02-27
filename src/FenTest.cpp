
#include "OX88Board.h"
#include <assert.h>
#include <iostream>
#include <chrono>

#include <gtest/gtest.h>
TEST (FenTest,init_loads_start_position)
{
    OX88Board board;
    board.Init();
    EXPECT_EQ(board.Fen(),"rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
}
TEST (FenTest,fen_load_1)
{
    OX88Board board;
    board.LoadFen("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    EXPECT_TRUE(board.SanityCheck());

    EXPECT_TRUE(board.At(A1)==(WHITE|ROOK));
    EXPECT_TRUE(board.At(B1)==(WHITE|KNIGHT));
    EXPECT_TRUE(board.At(C1)==(WHITE|BISHOP));
    EXPECT_TRUE(board.At(D1)==(WHITE|QUEEN));
    EXPECT_TRUE(board.At(E1)==(WHITE|KING));
    EXPECT_TRUE(board.At(F1)==(WHITE|BISHOP));
    EXPECT_TRUE(board.At(G1)==(WHITE|KNIGHT));
    EXPECT_TRUE(board.At(H1)==(WHITE|ROOK));
    EXPECT_TRUE(board.At(A2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(B2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(C2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(D2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(E2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(F2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(G2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(H2)==(WHITE|PAWN));

    EXPECT_TRUE(board.At(A3)==EMPTY);
    EXPECT_TRUE(board.At(B3)==EMPTY);
    EXPECT_TRUE(board.At(C3)==EMPTY);
    EXPECT_TRUE(board.At(D3)==EMPTY);
    EXPECT_TRUE(board.At(E3)==EMPTY);
    EXPECT_TRUE(board.At(F3)==EMPTY);
    EXPECT_TRUE(board.At(G3)==EMPTY);
    EXPECT_TRUE(board.At(H3)==EMPTY);

    EXPECT_TRUE(board.At(A4)==EMPTY);
    EXPECT_TRUE(board.At(B4)==EMPTY);
    EXPECT_TRUE(board.At(C4)==EMPTY);
    EXPECT_TRUE(board.At(D4)==EMPTY);
    EXPECT_TRUE(board.At(E4)==EMPTY);
    EXPECT_TRUE(board.At(F4)==EMPTY);
    EXPECT_TRUE(board.At(G4)==EMPTY);
    EXPECT_TRUE(board.At(H4)==EMPTY);

    EXPECT_TRUE(board.At(A5)==EMPTY);
    EXPECT_TRUE(board.At(B5)==EMPTY);
    EXPECT_TRUE(board.At(C5)==EMPTY);
    EXPECT_TRUE(board.At(D5)==EMPTY);
    EXPECT_TRUE(board.At(E5)==EMPTY);
    EXPECT_TRUE(board.At(F5)==EMPTY);
    EXPECT_TRUE(board.At(G5)==EMPTY);
    EXPECT_TRUE(board.At(H5)==EMPTY);

    EXPECT_TRUE(board.At(A6)==EMPTY);
    EXPECT_TRUE(board.At(B6)==EMPTY);
    EXPECT_TRUE(board.At(C6)==EMPTY);
    EXPECT_TRUE(board.At(D6)==EMPTY);
    EXPECT_TRUE(board.At(E6)==EMPTY);
    EXPECT_TRUE(board.At(F6)==EMPTY);
    EXPECT_TRUE(board.At(G6)==EMPTY);
    EXPECT_TRUE(board.At(H6)==EMPTY);

    EXPECT_TRUE(board.At(A8)==(BLACK|ROOK));
    EXPECT_TRUE(board.At(B8)==(BLACK|KNIGHT));
    EXPECT_TRUE(board.At(C8)==(BLACK|BISHOP));
    EXPECT_TRUE(board.At(D8)==(BLACK|QUEEN));
    EXPECT_TRUE(board.At(E8)==(BLACK|KING));
    EXPECT_TRUE(board.At(F8)==(BLACK|BISHOP));
    EXPECT_TRUE(board.At(G8)==(BLACK|KNIGHT));
    EXPECT_TRUE(board.At(H8)==(BLACK|ROOK));
    EXPECT_TRUE(board.At(A7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(B7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(C7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(D7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(E7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(F7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(G7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(H7)==(BLACK|PAWN));

    int count;

    auto w_pawns = board.WhitePawns(count);
    EXPECT_TRUE(count==8);
    EXPECT_TRUE(w_pawns[0] == A2);
    EXPECT_TRUE(w_pawns[1] == B2);
    EXPECT_TRUE(w_pawns[2] == C2);
    EXPECT_TRUE(w_pawns[3] == D2);
    EXPECT_TRUE(w_pawns[4] == E2);
    EXPECT_TRUE(w_pawns[5] == F2);
    EXPECT_TRUE(w_pawns[6] == G2);
    EXPECT_TRUE(w_pawns[7] == H2);

    auto b_pawns = board.BlackPawns(count);
    EXPECT_TRUE(count==8);
    EXPECT_TRUE(b_pawns[0] == A7);
    EXPECT_TRUE(b_pawns[1] == B7);
    EXPECT_TRUE(b_pawns[2] == C7);
    EXPECT_TRUE(b_pawns[3] == D7);
    EXPECT_TRUE(b_pawns[4] == E7);
    EXPECT_TRUE(b_pawns[5] == F7);
    EXPECT_TRUE(b_pawns[6] == G7);
    EXPECT_TRUE(b_pawns[7] == H7);

    auto w_rooks = board.WhiteRooks(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(w_rooks[0] == A1);
    EXPECT_TRUE(w_rooks[1] == H1);

    auto b_rooks = board.BlackRooks(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(b_rooks[0] == A8);
    EXPECT_TRUE(b_rooks[1] == H8);

    auto w_bishops = board.WhiteBishops(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(w_bishops[0] == C1);
    EXPECT_TRUE(w_bishops[1] == F1);

    auto b_bishops = board.BlackBishops(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(b_bishops[0] == C8);
    EXPECT_TRUE(b_bishops[1] == F8);

    auto w_knights = board.WhiteKnights(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(w_knights[0] == B1);
    EXPECT_TRUE(w_knights[1] == G1);

    auto b_knights = board.BlackKnights(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(b_knights[0] == B8);
    EXPECT_TRUE(b_knights[1] == G8);

    auto w_queens = board.WhiteQueens(count);
    EXPECT_TRUE(count==1);
    EXPECT_TRUE(w_queens[0] == D1);

    auto b_queens = board.BlackQueens(count);
    EXPECT_TRUE(count==1);
    EXPECT_TRUE(b_queens[0] == D8);

    EXPECT_TRUE(board.WhiteKing()==E1);
    EXPECT_TRUE(board.BlackKing()==E8);

    EXPECT_TRUE(board.EpSquare()==0);
    EXPECT_TRUE(board.CastlingAvailability()==W_CAN_CASTLE_LONG|W_CAN_CASTLE_SHORT|B_CAN_CASTLE_LONG|B_CAN_CASTLE_SHORT);
    EXPECT_TRUE(board.HalfMoveClock()==0);
    EXPECT_TRUE(board.FullMoveCount()==1);

}

TEST (FenTest,fen_load_2)
{
    OX88Board board;
    board.LoadFen("rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1");

    EXPECT_TRUE(board.SanityCheck());

    EXPECT_TRUE(board.ToMove() == BLACK);

    EXPECT_TRUE(board.At(A1)==(WHITE|ROOK));
    EXPECT_TRUE(board.At(B1)==(WHITE|KNIGHT));
    EXPECT_TRUE(board.At(C1)==(WHITE|BISHOP));
    EXPECT_TRUE(board.At(D1)==(WHITE|QUEEN));
    EXPECT_TRUE(board.At(E1)==(WHITE|KING));
    EXPECT_TRUE(board.At(F1)==(WHITE|BISHOP));
    EXPECT_TRUE(board.At(G1)==(WHITE|KNIGHT));
    EXPECT_TRUE(board.At(H1)==(WHITE|ROOK));
    EXPECT_TRUE(board.At(A2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(B2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(C2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(D2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(E2)==EMPTY);
    EXPECT_TRUE(board.At(F2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(G2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(H2)==(WHITE|PAWN));

    EXPECT_TRUE(board.At(A3)==EMPTY);
    EXPECT_TRUE(board.At(B3)==EMPTY);
    EXPECT_TRUE(board.At(C3)==EMPTY);
    EXPECT_TRUE(board.At(D3)==EMPTY);
    EXPECT_TRUE(board.At(E3)==EMPTY);
    EXPECT_TRUE(board.At(F3)==EMPTY);
    EXPECT_TRUE(board.At(G3)==EMPTY);
    EXPECT_TRUE(board.At(H3)==EMPTY);

    EXPECT_TRUE(board.At(A4)==EMPTY);
    EXPECT_TRUE(board.At(B4)==EMPTY);
    EXPECT_TRUE(board.At(C4)==EMPTY);
    EXPECT_TRUE(board.At(D4)==EMPTY);
    EXPECT_TRUE(board.At(E4)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(F4)==EMPTY);
    EXPECT_TRUE(board.At(G4)==EMPTY);
    EXPECT_TRUE(board.At(H4)==EMPTY);

    EXPECT_TRUE(board.At(A5)==EMPTY);
    EXPECT_TRUE(board.At(B5)==EMPTY);
    EXPECT_TRUE(board.At(C5)==EMPTY);
    EXPECT_TRUE(board.At(D5)==EMPTY);
    EXPECT_TRUE(board.At(E5)==EMPTY);
    EXPECT_TRUE(board.At(F5)==EMPTY);
    EXPECT_TRUE(board.At(G5)==EMPTY);
    EXPECT_TRUE(board.At(H5)==EMPTY);

    EXPECT_TRUE(board.At(A6)==EMPTY);
    EXPECT_TRUE(board.At(B6)==EMPTY);
    EXPECT_TRUE(board.At(C6)==EMPTY);
    EXPECT_TRUE(board.At(D6)==EMPTY);
    EXPECT_TRUE(board.At(E6)==EMPTY);
    EXPECT_TRUE(board.At(F6)==EMPTY);
    EXPECT_TRUE(board.At(G6)==EMPTY);
    EXPECT_TRUE(board.At(H6)==EMPTY);

    EXPECT_TRUE(board.At(A8)==(BLACK|ROOK));
    EXPECT_TRUE(board.At(B8)==(BLACK|KNIGHT));
    EXPECT_TRUE(board.At(C8)==(BLACK|BISHOP));
    EXPECT_TRUE(board.At(D8)==(BLACK|QUEEN));
    EXPECT_TRUE(board.At(E8)==(BLACK|KING));
    EXPECT_TRUE(board.At(F8)==(BLACK|BISHOP));
    EXPECT_TRUE(board.At(G8)==(BLACK|KNIGHT));
    EXPECT_TRUE(board.At(H8)==(BLACK|ROOK));
    EXPECT_TRUE(board.At(A7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(B7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(C7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(D7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(E7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(F7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(G7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(H7)==(BLACK|PAWN));

    int count;

    auto w_pawns = board.WhitePawns(count);
    EXPECT_TRUE(count==8);
    EXPECT_TRUE(w_pawns[0] == E4);
    EXPECT_TRUE(w_pawns[1] == A2);
    EXPECT_TRUE(w_pawns[2] == B2);
    EXPECT_TRUE(w_pawns[3] == C2);
    EXPECT_TRUE(w_pawns[5] == F2);
    EXPECT_TRUE(w_pawns[6] == G2);
    EXPECT_TRUE(w_pawns[7] == H2);

    auto b_pawns = board.BlackPawns(count);
    EXPECT_TRUE(count==8);
    EXPECT_TRUE(b_pawns[0] == A7);
    EXPECT_TRUE(b_pawns[1] == B7);
    EXPECT_TRUE(b_pawns[2] == C7);
    EXPECT_TRUE(b_pawns[3] == D7);
    EXPECT_TRUE(b_pawns[4] == E7);
    EXPECT_TRUE(b_pawns[5] == F7);
    EXPECT_TRUE(b_pawns[6] == G7);
    EXPECT_TRUE(b_pawns[7] == H7);

    auto w_rooks = board.WhiteRooks(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(w_rooks[0] == A1);
    EXPECT_TRUE(w_rooks[1] == H1);

    auto b_rooks = board.BlackRooks(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(b_rooks[0] == A8);
    EXPECT_TRUE(b_rooks[1] == H8);

    auto w_bishops = board.WhiteBishops(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(w_bishops[0] == C1);
    EXPECT_TRUE(w_bishops[1] == F1);

    auto b_bishops = board.BlackBishops(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(b_bishops[0] == C8);
    EXPECT_TRUE(b_bishops[1] == F8);

    auto w_knights = board.WhiteKnights(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(w_knights[0] == B1);
    EXPECT_TRUE(w_knights[1] == G1);

    auto b_knights = board.BlackKnights(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(b_knights[0] == B8);
    EXPECT_TRUE(b_knights[1] == G8);

    auto w_queens = board.WhiteQueens(count);
    EXPECT_TRUE(count==1);
    EXPECT_TRUE(w_queens[0] == D1);

    auto b_queens = board.BlackQueens(count);
    EXPECT_TRUE(count==1);
    EXPECT_TRUE(b_queens[0] == D8);

    EXPECT_TRUE(board.WhiteKing()==E1);
    EXPECT_TRUE(board.BlackKing()==E8);

    EXPECT_TRUE(board.EpSquare()==E3);
    EXPECT_TRUE(board.CastlingAvailability()==W_CAN_CASTLE_LONG|W_CAN_CASTLE_SHORT|B_CAN_CASTLE_LONG|B_CAN_CASTLE_SHORT);
    EXPECT_TRUE(board.HalfMoveClock()==0);
    EXPECT_TRUE(board.FullMoveCount()==1);

}

TEST(FenTest,fen_load_3)
{
    OX88Board board;
    board.LoadFen("rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2");

    EXPECT_TRUE(board.SanityCheck());

    EXPECT_TRUE(board.ToMove() == WHITE);

    EXPECT_TRUE(board.At(A1)==(WHITE|ROOK));
    EXPECT_TRUE(board.At(B1)==(WHITE|KNIGHT));
    EXPECT_TRUE(board.At(C1)==(WHITE|BISHOP));
    EXPECT_TRUE(board.At(D1)==(WHITE|QUEEN));
    EXPECT_TRUE(board.At(E1)==(WHITE|KING));
    EXPECT_TRUE(board.At(F1)==(WHITE|BISHOP));
    EXPECT_TRUE(board.At(G1)==(WHITE|KNIGHT));
    EXPECT_TRUE(board.At(H1)==(WHITE|ROOK));
    EXPECT_TRUE(board.At(A2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(B2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(C2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(D2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(E2)==EMPTY);
    EXPECT_TRUE(board.At(F2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(G2)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(H2)==(WHITE|PAWN));

    EXPECT_TRUE(board.At(A3)==EMPTY);
    EXPECT_TRUE(board.At(B3)==EMPTY);
    EXPECT_TRUE(board.At(C3)==EMPTY);
    EXPECT_TRUE(board.At(D3)==EMPTY);
    EXPECT_TRUE(board.At(E3)==EMPTY);
    EXPECT_TRUE(board.At(F3)==EMPTY);
    EXPECT_TRUE(board.At(G3)==EMPTY);
    EXPECT_TRUE(board.At(H3)==EMPTY);

    EXPECT_TRUE(board.At(A4)==EMPTY);
    EXPECT_TRUE(board.At(B4)==EMPTY);
    EXPECT_TRUE(board.At(C4)==EMPTY);
    EXPECT_TRUE(board.At(D4)==EMPTY);
    EXPECT_TRUE(board.At(E4)==(WHITE|PAWN));
    EXPECT_TRUE(board.At(F4)==EMPTY);
    EXPECT_TRUE(board.At(G4)==EMPTY);
    EXPECT_TRUE(board.At(H4)==EMPTY);

    EXPECT_TRUE(board.At(A5)==EMPTY);
    EXPECT_TRUE(board.At(B5)==EMPTY);
    EXPECT_TRUE(board.At(C5)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(D5)==EMPTY);
    EXPECT_TRUE(board.At(E5)==EMPTY);
    EXPECT_TRUE(board.At(F5)==EMPTY);
    EXPECT_TRUE(board.At(G5)==EMPTY);
    EXPECT_TRUE(board.At(H5)==EMPTY);

    EXPECT_TRUE(board.At(A6)==EMPTY);
    EXPECT_TRUE(board.At(B6)==EMPTY);
    EXPECT_TRUE(board.At(C6)==EMPTY);
    EXPECT_TRUE(board.At(D6)==EMPTY);
    EXPECT_TRUE(board.At(E6)==EMPTY);
    EXPECT_TRUE(board.At(F6)==EMPTY);
    EXPECT_TRUE(board.At(G6)==EMPTY);
    EXPECT_TRUE(board.At(H6)==EMPTY);

    EXPECT_TRUE(board.At(A8)==(BLACK|ROOK));
    EXPECT_TRUE(board.At(B8)==(BLACK|KNIGHT));
    EXPECT_TRUE(board.At(C8)==(BLACK|BISHOP));
    EXPECT_TRUE(board.At(D8)==(BLACK|QUEEN));
    EXPECT_TRUE(board.At(E8)==(BLACK|KING));
    EXPECT_TRUE(board.At(F8)==(BLACK|BISHOP));
    EXPECT_TRUE(board.At(G8)==(BLACK|KNIGHT));
    EXPECT_TRUE(board.At(H8)==(BLACK|ROOK));
    EXPECT_TRUE(board.At(A7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(B7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(C7)==EMPTY);
    EXPECT_TRUE(board.At(D7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(E7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(F7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(G7)==(BLACK|PAWN));
    EXPECT_TRUE(board.At(H7)==(BLACK|PAWN));

    int count;

    auto w_pawns = board.WhitePawns(count);
    EXPECT_TRUE(count==8);
    EXPECT_TRUE(w_pawns[0] == E4);
    EXPECT_TRUE(w_pawns[1] == A2);
    EXPECT_TRUE(w_pawns[2] == B2);
    EXPECT_TRUE(w_pawns[3] == C2);
    EXPECT_TRUE(w_pawns[5] == F2);
    EXPECT_TRUE(w_pawns[6] == G2);
    EXPECT_TRUE(w_pawns[7] == H2);

    auto b_pawns = board.BlackPawns(count);
    EXPECT_TRUE(count==8);
    EXPECT_TRUE(b_pawns[0] == A7);
    EXPECT_TRUE(b_pawns[1] == B7);
    EXPECT_TRUE(b_pawns[2] == D7);
    EXPECT_TRUE(b_pawns[3] == E7);
    EXPECT_TRUE(b_pawns[4] == F7);
    EXPECT_TRUE(b_pawns[5] == G7);
    EXPECT_TRUE(b_pawns[6] == H7);
    EXPECT_TRUE(b_pawns[7] == C5);

    auto w_rooks = board.WhiteRooks(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(w_rooks[0] == A1);
    EXPECT_TRUE(w_rooks[1] == H1);

    auto b_rooks = board.BlackRooks(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(b_rooks[0] == A8);
    EXPECT_TRUE(b_rooks[1] == H8);

    auto w_bishops = board.WhiteBishops(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(w_bishops[0] == C1);
    EXPECT_TRUE(w_bishops[1] == F1);

    auto b_bishops = board.BlackBishops(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(b_bishops[0] == C8);
    EXPECT_TRUE(b_bishops[1] == F8);

    auto w_knights = board.WhiteKnights(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(w_knights[0] == B1);
    EXPECT_TRUE(w_knights[1] == G1);

    auto b_knights = board.BlackKnights(count);
    EXPECT_TRUE(count==2);
    EXPECT_TRUE(b_knights[0] == B8);
    EXPECT_TRUE(b_knights[1] == G8);

    auto w_queens = board.WhiteQueens(count);
    EXPECT_TRUE(count==1);
    EXPECT_TRUE(w_queens[0] == D1);

    auto b_queens = board.BlackQueens(count);
    EXPECT_TRUE(count==1);
    EXPECT_TRUE(b_queens[0] == D8);

    EXPECT_TRUE(board.WhiteKing()==E1);
    EXPECT_TRUE(board.BlackKing()==E8);

    EXPECT_TRUE(board.EpSquare()==C6);
    EXPECT_TRUE(board.CastlingAvailability()==W_CAN_CASTLE_LONG|W_CAN_CASTLE_SHORT|B_CAN_CASTLE_LONG|B_CAN_CASTLE_SHORT);
    EXPECT_TRUE(board.HalfMoveClock()==0);
    EXPECT_TRUE(board.FullMoveCount()==2);

}

TEST( FenTest,fen_load_4)
{
    OX88Board board;
    board.LoadFen("4k3/8/8/8/8/8/4P3/4K3 w - - 5 39");

    EXPECT_TRUE(board.SanityCheck());
    EXPECT_TRUE(board.FullMoveCount()==39);
    EXPECT_TRUE(board.HalfMoveClock()==5);
    EXPECT_TRUE(board.ToMove() == WHITE);
    EXPECT_TRUE(board.CastlingAvailability()==0);
}

TEST( FenTest,fen_load_5)
{
    OX88Board board;
    board.LoadFen("4k3/8/8/8/8/8/4P3/4K3 w - - 12 39");

    EXPECT_TRUE(board.SanityCheck());
    EXPECT_TRUE(board.FullMoveCount()==39);
    EXPECT_TRUE(board.HalfMoveClock()==12);
    EXPECT_TRUE(board.ToMove() == WHITE);
    EXPECT_TRUE(board.CastlingAvailability()==0);
}

TEST( FenTest,check_empty)
{
    OX88Board board;

    board.SanityCheck();

    EXPECT_TRUE(board.At(A1)==EMPTY);
    EXPECT_TRUE(board.At(A2)==EMPTY);
    EXPECT_TRUE(board.At(A3)==EMPTY);
    EXPECT_TRUE(board.At(A4)==EMPTY);
    EXPECT_TRUE(board.At(A5)==EMPTY);
    EXPECT_TRUE(board.At(A6)==EMPTY);
    EXPECT_TRUE(board.At(A7)==EMPTY);

    EXPECT_TRUE(board.At(B1)==EMPTY);
    EXPECT_TRUE(board.At(B2)==EMPTY);
    EXPECT_TRUE(board.At(B3)==EMPTY);
    EXPECT_TRUE(board.At(B4)==EMPTY);
    EXPECT_TRUE(board.At(B5)==EMPTY);
    EXPECT_TRUE(board.At(B6)==EMPTY);
    EXPECT_TRUE(board.At(B7)==EMPTY);

    EXPECT_TRUE(board.At(C1)==EMPTY);
    EXPECT_TRUE(board.At(C2)==EMPTY);
    EXPECT_TRUE(board.At(C3)==EMPTY);
    EXPECT_TRUE(board.At(C4)==EMPTY);
    EXPECT_TRUE(board.At(C5)==EMPTY);
    EXPECT_TRUE(board.At(C6)==EMPTY);
    EXPECT_TRUE(board.At(C7)==EMPTY);

    EXPECT_TRUE(board.At(D1)==EMPTY);
    EXPECT_TRUE(board.At(D2)==EMPTY);
    EXPECT_TRUE(board.At(D3)==EMPTY);
    EXPECT_TRUE(board.At(D4)==EMPTY);
    EXPECT_TRUE(board.At(D5)==EMPTY);
    EXPECT_TRUE(board.At(D6)==EMPTY);
    EXPECT_TRUE(board.At(D7)==EMPTY);

    EXPECT_TRUE(board.At(E1)==EMPTY);
    EXPECT_TRUE(board.At(E2)==EMPTY);
    EXPECT_TRUE(board.At(E3)==EMPTY);
    EXPECT_TRUE(board.At(E4)==EMPTY);
    EXPECT_TRUE(board.At(E5)==EMPTY);
    EXPECT_TRUE(board.At(E6)==EMPTY);
    EXPECT_TRUE(board.At(E7)==EMPTY);

    EXPECT_TRUE(board.At(F1)==EMPTY);
    EXPECT_TRUE(board.At(F2)==EMPTY);
    EXPECT_TRUE(board.At(F3)==EMPTY);
    EXPECT_TRUE(board.At(F4)==EMPTY);
    EXPECT_TRUE(board.At(F5)==EMPTY);
    EXPECT_TRUE(board.At(F6)==EMPTY);
    EXPECT_TRUE(board.At(F7)==EMPTY);

    EXPECT_TRUE(board.At(G1)==EMPTY);
    EXPECT_TRUE(board.At(G2)==EMPTY);
    EXPECT_TRUE(board.At(G3)==EMPTY);
    EXPECT_TRUE(board.At(G4)==EMPTY);
    EXPECT_TRUE(board.At(G5)==EMPTY);
    EXPECT_TRUE(board.At(G6)==EMPTY);
    EXPECT_TRUE(board.At(G7)==EMPTY);

    EXPECT_TRUE(board.At(H1)==EMPTY);
    EXPECT_TRUE(board.At(H2)==EMPTY);
    EXPECT_TRUE(board.At(H3)==EMPTY);
    EXPECT_TRUE(board.At(H4)==EMPTY);
    EXPECT_TRUE(board.At(H5)==EMPTY);
    EXPECT_TRUE(board.At(H6)==EMPTY);
    EXPECT_TRUE(board.At(H7)==EMPTY);

}

TEST( FenTest,fen_output_1)
{
    OX88Board board;
    std::string fen="rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    board.LoadFen(fen);
    std::string out = board.Fen();
    EXPECT_TRUE(fen==out);

}
TEST( FenTest,fen_output_2)
{
    OX88Board board;
    std::string fen="rnbqkbnr/pp1ppppp/8/2p5/4P3/8/PPPP1PPP/RNBQKBNR w KQkq c6 0 2";
    board.LoadFen(fen);
    std::string out = board.Fen();
    EXPECT_TRUE(fen==out);

}
TEST( FenTest,fen_output_3)
{
    OX88Board board;
    std::string fen="4k3/8/8/8/8/8/4P3/4K3 w - - 12 39";
    board.LoadFen(fen);
    std::string out = board.Fen();
    EXPECT_TRUE(fen==out);
}
TEST( FenTest,fen_output_4)
{
    OX88Board board;
    std::string fen="rnbqkbnr/pppppppp/8/8/4P3/8/PPPP1PPP/RNBQKBNR b KQkq e3 0 1";
    board.LoadFen(fen);
    std::string out = board.Fen();
    EXPECT_TRUE(fen==out);
}

