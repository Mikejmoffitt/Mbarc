#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

// If two addresses are given, the second one is the one that takes effect

#define NOP 0x00 // 1 byte; Do nothing
#define INC 0x01 // 2 bytes; Increment address given by 1
#define DEC 0x02 // 2 bytes; Decrement address given by 1
#define ADD 0x03 // 3 bytes; Add address 1 to address 2
#define SUB 0x04 // 3 bytes; Subtract address 1 from address 2
#define MLT 0x05 // 3 bytes; Multiply address 2 by address 1 WARNING: does not yet trip overflow
#define DIV 0x06 // 3 bytes; Divide address 2 by address 1 WARNING: does not yet trip overflow
#define CMP 0x07 // 3 bytes; Compare address 2 and 1; set zero flag if they are equal.
#define SET 0x08 // 3 bytes; Put value 1 into address 2
#define AND 0x09 // 3 bytes; Logical AND address 1 to address 2 
#define OR  0x0A // 3 bytes; Logical OR address 1 to address 2
#define BNE 0x0B // 2 bytes; Branch if !zeroFlag to address 1
#define BEQ 0x0C // 2 bytes; Branch if zeroFlag to address 1
#define JNE 0x0D // 2 bytes; Jump if !zeroFlag to relative address 1
#define JEQ 0x0E // 2 bytes; Jump if zeroFlag to relative address 2
#define LSL 0x0F // 2 bytes; Logical shift left for address 1
#define LSR 0x10 // 2 bytes; Logical shift right for address 1
#define ZFC 0x11 // 1 bytes; Clear zero flag.
#define ZFS 0x12 // 1 bytes; Set zero flag.
#define OFC 0x13 // 1 bytes; Clear overflow flag.
#define OFS 0x14 // 1 bytes; Set overflow flag
#define BRA 0x15 // 2 bytes; Branches to address 1
#define JMP 0x16 // 2 bytes; Jumps to relativeaddress 1
#define NCP 0x17 // 3 bytes; compare constant number 1 to address 2

#endif INSTRUCTIONS_H