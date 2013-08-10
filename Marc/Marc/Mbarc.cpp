/*

Moffitt's Bogus Architecture
By Michael Moffitt

*/

#include "Mbarc.h"
Mbarc::Mbarc()
{
	for (int i = 0; i < USHRT_MAX+1; i++)
	{
		memory[i] = 0;
	}
	pc = 0x0000;
	overFlow = false;
	zeroFlag = false;
	spill(false);
}

#define NUM_PER_LINE 8

void Mbarc::spill(bool verbose)
{
	std::cout << std::endl << "[Status]" << ":" << std::endl;
	std::cout << "  " << "PC:\t\t " << "$" << std::hex << (int)pc << std::endl;
	std::cout << "  " << "Overflow:\t " << overFlow << std::endl;
	std::cout << "  " << "Zero:\t\t " << zeroFlag << std::endl;
	std::stringstream lineStr;
	if (verbose)
	{
		std::cout << std::endl << "[First page]" << ":" << std::endl << std::endl;
		for (int i = 0; i < (UCHAR_MAX/NUM_PER_LINE)+1; i++)
		{
			for (int j = i*NUM_PER_LINE; j < (i*NUM_PER_LINE) + NUM_PER_LINE; j++)
			{
				if (pc == j)
				{
					lineStr << "*" << std::hex << int(memory[j]) << std::nouppercase << std::dec << "\t";
				}
				else
				{
					lineStr << " " << std::hex << int(memory[j]) << std::nouppercase << std::dec << "\t";
				}
				
			}
			lineStr << std::endl;
		}
	}
	std::cout << lineStr.str() << std::endl;
}

unsigned short Mbarc::peek(unsigned int addr)
{
	return memory[addr];
}

void Mbarc::poke(unsigned int addr, unsigned short val)
{
	memory[addr] = val;
}

void Mbarc::run()
{
	act(memory[pc], memory[(pc+1)], memory[(pc+2)]);
}

bool Mbarc::isOver()
{
	return (memory[pc] == 0xFFFF);
}

void Mbarc::act(unsigned short instr, unsigned short param1, unsigned short param2)
{
	unsigned char param80 = param1%256; // Lower 8 bits of param1
	unsigned char param81 = param1/256; // Upper 8 bits of param1
	unsigned char param82 = param2%256; // Lower 8 bits of param2
	unsigned char param83 = param2/256; // Upper 8 bits of param2
	unsigned short prev;
	std::string outMsg = "";
	switch (instr)
	{
	case END:
		break;
	case NOP:
		pc++;
		break;
	case INC:
		memory[param1] += 1;
		overFlow = (memory[param1] == 0);
		pc++;
		pc++;
		break;
	case DEC:
		memory[param1] -= 1;
		overFlow = (memory[param1] == USHRT_MAX);
		pc++;
		pc++;
		break;
	case ADD:
		prev = memory[param2];
		memory[param2] += param1;
		overFlow = (memory[param2] < prev);
		pc++;
		pc++;
		pc++;
		break;
	case SUB:
		prev = memory[param2];
		memory[param2] -= param1;
		overFlow = (memory[param2] > prev);
		pc++;
		pc++;
		pc++;
		break;
	case MLT:
		memory[param2] = memory[param2] * param1;
		pc++;
		pc++;
		pc++;
		break;
	case DIV:
		memory[param2] = memory[param2] / param1;
		pc++;
		pc++;
		pc++;
		break;
	case CMP:
		zeroFlag = (memory[param2] == memory[param1]);
		pc++;
		pc++;
		pc++;
		break;
	case NCP:
		zeroFlag = (memory[param2] == param1);
		pc++;
		pc++;
		pc++;
		break;
	case MOV:
		memory[param2] = param1;
		pc++;
		pc++;
		pc++;
		break;
	case AND:
		memory[param2] = memory[param2] & param1;
		pc++;
		pc++;
		pc++;
		break;
	case OR:
		memory[param2] = memory[param2] | param1;
		pc++;
		pc++;
		pc++;
		break;
	case BNE:
		pc = zeroFlag ? pc+2 : param1;
		break;
	case BEQ:
		pc = zeroFlag ? param1 : pc+2;
		break;
	case JNE:
		pc = zeroFlag ? pc+2 : (pc + param1);
		break;
	case JEQ:
		pc = zeroFlag ? (pc + param1) : pc+2;
		break;
	case LSL:
		// Todo: use carry flag to capture the bit shifted out
		memory[param1] = memory[param1] << 1;
		pc++;
		pc++;
		break;
	case LSR:
		// Todo: use carry flag to capture the bit shifted out
		memory[param1] = memory[param1] >> 1;
		pc++;
		pc++;
		break;
	case ZFC:
		zeroFlag = false;
		pc++;
		break;
	case ZFS:
		zeroFlag = true;
		pc++;
		break;
	case OFC:
		overFlow = false;
		pc++;
		break;
	case OFS:
		overFlow = true;
		pc++;
		break;
	case BRA:
		pc = param1;
		break;
	case JMP:
		pc += param1;
		break;
	}
}