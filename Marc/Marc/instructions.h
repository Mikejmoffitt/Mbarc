#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

// If two addresses are given, the second one is the one that takes effect

#define NOP 0x0000 // 1 short ; Do nothing
#define INC 0x0001 // 2 shorts; Increment address given by 1
#define DEC 0x0002 // 2 shorts; Decrement address given by 1
#define ADD 0x0003 // 3 shorts; Add address 1 to address 2
#define SUB 0x0004 // 3 shorts; Subtract address 1 from address 2
#define MLT 0x0005 // 3 shorts; Multiply address 2 by address 1 WARNING: does not yet trip overflow
#define DIV 0x0006 // 3 shorts; Divide address 2 by address 1 WARNING: does not yet trip overflow
#define CMP 0x0007 // 3 shorts; Compare address 2 and 1; set zero flag if they are equal.
#define MOV 0x0008 // 3 shorts; Put value 1 into address 2
#define AND 0x0009 // 3 shorts; Logical AND address 1 to address 2 
#define OR  0x000A // 3 shorts; Logical OR address 1 to address 2
#define BNE 0x000B // 2 shorts; Branch if !zeroFlag to address 1
#define BEQ 0x000C // 2 shorts; Branch if zeroFlag to address 1
#define JNE 0x000D // 2 shorts; Jump if !zeroFlag to relative address 1
#define JEQ 0x000E // 2 shorts; Jump if zeroFlag to relative address 2
#define LSL 0x000F // 2 shorts; Logical shift left for address 1
#define LSR 0x0010 // 2 shorts; Logical shift right for address 1
#define ZFC 0x0011 // 1 shorts; Clear zero flag.
#define ZFS 0x0012 // 1 shorts; Set zero flag.
#define OFC 0x0013 // 1 shorts; Clear overflow flag.
#define OFS 0x0014 // 1 shorts; Set overflow flag
#define BRA 0x0015 // 2 shorts; Branches to address 1
#define JMP 0x0016 // 2 shorts; Jumps to relativeaddress 1
#define NCP 0x0017 // 3 shorts; compare constant number 1 to address 2
#define SSP 0x0018 // 2 shorts; set stack pointer to value 1
#define GSP 0x0019 // 2 shorts; load stack pointer into address 1
#define PRI 0x0020 // 2 shorts; do console output from adress 1 onward until character FFFF

#define END 0x00FF // 1 short; program is over.

#endif INSTRUCTIONS_H