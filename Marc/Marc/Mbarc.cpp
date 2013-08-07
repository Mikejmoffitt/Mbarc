/*

Moffitt's Bogus Architecture
By Michael Moffitt

*/

#include "Mbarc.h"
#include "instructions.h"
#include <limits>

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
		memory[param1] += 1;
		overFlow = (memory[param1] == 0) ? true : false;
		break;
	case DEC:
		memory[param1] -= 1;
		overFlow = (memory[param1] == UCHAR_MAX) ? true : false;
		break;
	case ADD:
		unsigned char prev = memory[param2];
		memory[param2] += param1;
		overFlow = (memory[param2] < prev) ? true : false;
	case SUB:
		unsigned char prev = memory[param2];
		memory[param2] -= param1;
		overFlow = (memory[param2] > prev) ? true : false;
	case MLT:
		memory[param2] = memory[param2] * param1;
	case DIV:
		memory[param2] = memory[param2] / param1;
	case CMP:
		zeroFlag = (memory[param2] - param1) ? true : false;
	case SET:
		memory[param2] = param1;
	case AND:
		memory[param2] = memory[param2] & param1;
	case OR:
		memory[param2] = memory[param2] | param1;
	case BNE:
		pc = zeroFlag ? pc : param1;
	case BEQ:
		pc = zeroFlag ? param1 : pc;
	case JNE:
		pc = zeroFlag ? pc : (pc + param1);
	case JEQ:
		pc = zeroFlag ? (pc + param1) : pc;
	case LSL:
		// Todo: use carry flag to capture the bit shifted out
		memory[param1] = memory[param1] << 1;
	case LSR:
		// Todo: use carry flag to capture the bit shifted out
		memory[param1] = memory[param1] >> 1;
	case ZFC:
		zeroFlag = false;
	case ZFS:
		zeroFlag = true;
	case OFC:
		overFlow = false;
	case OFS:
		overFlow = true;
	}
	this->pc += 3;
}