/*

Moffitt's Bogus Architecture
By Michael Moffitt

*/

#include "Marc.h"
#include "instructions.h"

Mbarc::Mbarc(unsigned char* mem)
{
	this->memory = mem;
}

unsigned char Mbarc::peek(unsigned int addr)
{
	return memory[addr];
}

void Mbarc::poke(unsigned int addr, unsigned char val)
{
	memory[addr] = val;
}

void Mbarc::act(unsigned char instr, unsigned char param1, unsigned char param2)
{
	switch (instr)
	{
	case NOP:
		break;
	case INC:

	}
}