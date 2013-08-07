/*

Moffitt's Bogus Architecture
By Michael Moffitt

*/

#include "Marc.h"
#include "instructions.h"

Marc::Marc(unsigned char* mem)
{
	this->memory = mem;
}

unsigned char Marc::peek(unsigned int addr)
{
	return memory[addr];
}

void Marc::poke(unsigned int addr, unsigned char val)
{
	memory[addr] = val;
}

void Marc::act(unsigned char instr, unsigned char param1, unsigned char param2)
{
	switch (instr)
	{
	case NOP:
		break;
	}
}