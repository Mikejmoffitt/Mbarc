#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#define i_nop   0x0000 //		{op}			// Do nothing, waste some cycles
#define i_addi  0x0001 //		{op}[A][B]		// Add value A to address B
#define i_add   0x0002 //		{op}[A][B]		// Add value at A to address B
#define i_subi  0x0003 //		{op}[A][B]		// Sub value A from address B
#define i_sub   0x0004 //		{op}[A][B]		// Sub value at A to address B
#define i_mlti  0x0005 //		{op}[A][B]		// Multiply value A with adress B's value
#define i_mlt   0x0006 //		{op}[A][B]		// Multiply value at A with adress B's value
#define i_divi  0x0007 //		{op}[A][B]		// Divide value at address B by value A
#define i_div   0x0008 //		{op}[A][B]		// Divide value at address B by value at address A
#define i_cmpi  0x0009 //		{op}[A][B]		// Compare value A with value at address B
#define i_cmp   0x000A //		{op}[A][B]		// Compare values at A and B
#define i_clear 0x000B //		{op}			// Clear comparison
#define i_movi  0x000C //		{op}[A][B]		// Put value A into address B
#define i_mov   0x000D //		{op}[A][B]		// put value at A into address B
#define i_bra   0x000E //		{op}[A]			// Push PC to stack, go to address A
#define i_beq   0x000F //		{op}[A]			// Go to address A if B was equal to A
#define i_bne   0x0010 //		{op}[A]			// Go to address A if B was not equal to A
#define i_bgt   0x0011 //		{op}[A]			// Go to address A if B was greater than A
#define i_blt   0x0012 //		{op}[A]			// Go to address A if B was less than A
#define i_bge   0x0013 //		{op}[A]			// Go to address A if B was greater / equal to A
#define i_ble   0x0014 //		{op}[A]			// Go to address A if B was less / equal to A
#define i_pushi 0x0015 //		{op}[A]			// Push value A onto stack
#define i_push  0x0016 //		{op}[A]			// Push value at A onto stack
#define i_pop	0x0017 //		{op}[A]			// Pop stack value onto address A
#define i_speek 0x0018 //		{op}[A]			// Put top of stack at A, don't pop it off
#define i_setsp 0x0019 //		{op}[A]			// Set stack pointer to address A
#define i_spill 0x001A //		{op}[A}			// brings up memory viewer from A
#define i_print 0x001B //		{op}[A]			// Print from address A onwards until 0xDEAD (aligned to even byte)
#define i_inint 0x001C //		{op}[A]			// Prompt for user input, store integer at A
#define i_instr 0x001D //		{op}[A]			// Prompt for user input, store string starting at A
#define i_and   0x001E //	    {op}[A][B]		// AND value at B with value at A
#define i_andi  0x001F //		{op}[A][B]		// AND value at B with A
#define i_or    0x0020 //       {op}[A][B]		// OR value at B with value at A
#define i_ori   0x0021 //		{op}[A][B]		// OR value at B with A
#define i_lsl   0x0022 //       {op}[A][B]		// shift A times address B left
#define i_lsr   0x0023 //		{op}[A][B]		// shift A times address B right
#define rts		0x0024 //		{op}			// PC = stack pop
#define i_jra   0x002E //		{op}[A]			// DON'T PUSH PC to stack, go to address A
#define i_jeq   0x002F //		{op}[A]			// Go to address A if A was equal to B
#define i_jne   0x0030 //		{op}[A]			// Go to address A if A was not equal to B
#define i_jgt   0x0031 //		{op}[A]			// Go to address A if A was greater than B
#define i_jlt   0x0032 //		{op}[A]			// Go to address A if A was less than B
#define i_jge   0x0033 //		{op}[A]			// Go to address A if A was greater / equal to B
#define i_jle   0x0034 //		{op}[A]			// Go to address A if A was less / equal to B

#endif INSTRUCTIONS_H