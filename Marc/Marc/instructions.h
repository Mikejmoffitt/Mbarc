#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

// If two addresses are given, the second one is the one that takes effect
// All instructions are three bytes, though not all are necissarily used

#define NOP 0x00 // Do nothing
#define INC 0x01 // Increment address given by 1
#define DEC 0x02 // Decrement address given by 1
#define ADD 0x03 // Add address 1 to address 2
#define SUB 0x04 // Subtract address 1 from address 2
#define MLT 0x05 // Multiply address 2 by address 1 WARNING: does not yet trip overflow
#define DIV 0x06 // Divide address 2 by address 1 WARNING: does not yet trip overflow
#define CMP 0x07 // Compare address 2 and 1; set zero flag if they are equal.
#define SET 0x08 // Put value 1 into address 2
#define AND 0x09 // Logical AND address 1 to address 2 
#define OR  0x0A // Logical OR address 1 to address 2
#define BNE 0x0B // Branch if !zeroFlag to address 1
#define BEQ 0x0C // Branch if zeroFlag to address 1
#define JNE 0x0D // Jump if !zeroFlag to relative address 1
#define JEQ 0x0E // Jump if zeroFlag to relative address 2
#define LSL 0x0F // Logical shift left for address 1
#define LSR 0x10 // Logical shift right for address 1
#define ZFC 0x11 // Clear zero flag.
#define ZFS 0x12 // Set zero flag.
#define OFC 0x13 // Clear overflow flag.
#define OFS 0x14 // Set overflow flag

#endif INSTRUCTIONS_H