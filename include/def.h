#ifndef DEF_H_INCLUDED
#define DEF_H_INCLUDED

#include <inttypes.h>

#define OX88 int8_t
#define CELL_CONTENT int16_t
#define FLAGS int8_t


/*
   MACROS TO HANDLE CELL CONTENT EXTRACTING PIECE AND REVERSE INDEX
   IE THE INDEX ON THE CORRESPONDING PART ARRAY.
   PART IS THE UPPER BYTE AND REVERSE INDEX THE LOWER
*/

#define PART(x) ((x))&0xFF
#define INDEX(x) ((x))>>8
#define TO_INDEX(x) ((x))<<8



#define EMPTY 0
#define W_CAN_CASTLE_SHORT 1
#define W_CAN_CASTLE_LONG 2
#define B_CAN_CASTLE_SHORT 4
#define B_CAN_CASTLE_LONG 8


// bitwise supporting constants
#define WHITE   0x1
#define BLACK   0x2
#define PAWN    0x4
#define KNIGHT  0x8
#define BISHOP  0x10
#define ROOK    0x20
#define QUEEN   0x40
#define KING    0x80

#define A1  0x0
#define A2  0x10
#define A3  0x20
#define A4  0x30
#define A5  0x40
#define A6  0x50
#define A7  0x60
#define A8  0x70

#define B1  0x01
#define B2  0x11
#define B3  0x21
#define B4  0x31
#define B5  0x41
#define B6  0x51
#define B7  0x61
#define B8  0x71

#define C1  0x02
#define C2  0x12
#define C3  0x22
#define C4  0x32
#define C5  0x42
#define C6  0x52
#define C7  0x62
#define C8  0x72

#define D1  0x03
#define D2  0x13
#define D3  0x23
#define D4  0x33
#define D5  0x43
#define D6  0x53
#define D7  0x63
#define D8  0x73

#define E1  0x04
#define E2  0x14
#define E3  0x24
#define E4  0x34
#define E5  0x44
#define E6  0x54
#define E7  0x64
#define E8  0x74

#define F1  0x05
#define F2  0x15
#define F3  0x25
#define F4  0x35
#define F5  0x45
#define F6  0x55
#define F7  0x65
#define F8  0x75

#define G1  0x06
#define G2  0x16
#define G3  0x26
#define G4  0x36
#define G5  0x46
#define G6  0x56
#define G7  0x66
#define G8  0x76

#define H1  0x07
#define H2  0x17
#define H3  0x27
#define H4  0x37
#define H5  0x47
#define H6  0x57
#define H7  0x67
#define H8  0x77

#define TO_OX88(r,f)  16 * ((r)) + ((f))

#endif // DEF_H_INCLUDED
