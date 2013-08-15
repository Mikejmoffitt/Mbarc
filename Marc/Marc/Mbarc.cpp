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
	comparison = 0;
	sp = 0;
	remainder = 0;
	spill(false);
}

#define NUM_PER_LINE 8
#define NUM_LINES 15

void Mbarc::spill(unsigned int start)
{
	std::cout << std::endl << "[Status]" << std::endl;
	std::cout << "  " << "PC:\t\t " << "$" << std::hex << (int)pc << std::endl;
	std::cout << "  " << "SP:\t\t " << "$" << std::hex << (int)sp << std::endl;
	std::cout << "  " << "Overflow:\t " << overFlow << std::endl;
	std::cout << "  " << "Comparison:\t\t " << std::dec << comparison << std::endl;
	std::stringstream lineStr;
	std::cout << std::endl << "[From $" << std::hex << start << "]" << std::endl << std::endl;
	for (int i = 0; i < NUM_LINES; i++)
	{
		lineStr << "[ $" << std::hex << start + (i*NUM_PER_LINE) << "\t]\t";
		for (int j = i*NUM_PER_LINE; j < (i*NUM_PER_LINE) + NUM_PER_LINE; j++)
		{
			if (pc == j+start)
			{
				lineStr << "*" << int(memory[j+start]);
			}
			else
			{
				lineStr << " " << int(memory[j+start]);
			}
			if (j != (i*NUM_PER_LINE) + NUM_PER_LINE - 1)
			{
				lineStr << "\t";
			}
				
		}
		lineStr << std::endl;
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

void Mbarc::act(unsigned short instrct, unsigned short param1, unsigned short param2)
{
	unsigned char param80 = param1%256; // Lower 8 bits of param1
	unsigned char param81 = param1/256; // Upper 8 bits of param1
	unsigned char param82 = param2%256; // Lower 8 bits of param2
	unsigned char param83 = param2/256; // Upper 8 bits of param2
	unsigned short input = 0;
	unsigned short prev;
		std::stringstream outStr;
	std::string outMsg = "";
	unsigned short pcinc = 1;
	switch (instrct)
	{
		//  Basic arithmatic
	case i_add:
		prev = memory[param2];
		memory[param2] += memory[param1];
		overFlow = (prev > memory[param2]);
		pcinc = 3;
		break;
	case i_addi:
		prev = memory[param2];
		memory[param2] += param1;
		overFlow = (prev > memory[param2]);
		pcinc = 3;
		break;
	case i_sub:
		prev = memory[param2];
		memory[param2] -= memory[param1];
		overFlow = (prev < memory[param2]);
		pcinc = 3;
		break;
	case i_subi:
		prev = memory[param2];
		memory[param2] -= param1;
		overFlow = (prev < memory[param2]);
		pcinc = 3;
		break;
	case i_mlt:
		memory[param2] = memory[param2] * memory[param1];
		pcinc = 3;
		break;
	case i_mlti:
		memory[param2] = memory[param2] * param1;
		pcinc = 3;
		break;
	case i_div:
		remainder = memory[param2]%memory[param1];
		memory[param2] = memory[param2] / memory[param1];
		pcinc = 3;
		break;
	case i_divi:
		remainder = memory[param2]%param1;
		memory[param2] = memory[param2] / param1;
		pcinc = 3;
		break;
	case i_cmp:
		comparison = 0;
		if (memory[param2] > memory[param1])
		{
			comparison = 1;
		}
		else if (memory[param2] < memory[param1])
		{
			comparison = -1;
		}
		pcinc = 3;
		break;
	case i_cmpi:
		comparison = 0;
		if (memory[param2] > param1)
		{
			comparison = 1;
		}
		else if (memory[param2] < param1)
		{
			comparison = -1;
		}
		pcinc = 3;
		break;
	case i_clear:
		comparison = 0;
		break;
	case i_mov:
		memory[param2] = memory[param1];
		pcinc = 3;
		break;
	case i_movi:
		memory[param2] = param1;
		pcinc = 3;
		break;
	case i_bra:
		memory[sp] = pc;
		sp++;
		pc = param1;
		pcinc = 0;
		break;
	case i_bne:
		memory[sp] = pc;
		sp++;
		pc = (comparison==0) ? pc+2 : param1;
		pcinc = 0;
		break;
	case i_beq:
		memory[sp] = pc;
		sp++;
		pc = (comparison!=0) ? pc+2 : param1;
		pcinc = 0;
		break;
	case i_bgt:
		memory[sp] = pc;
		sp++;
		pc = (comparison<0) ? param1 : pc+2;
		pcinc = 0;
		break;
	case i_blt:
		memory[sp] = pc;
		sp++;
		pc = (comparison>0) ? param1 : pc+2;
		pcinc = 0;
		break;
	case i_bge:
		memory[sp] = pc;
		sp++;
		pc = (comparison<=0) ? param1 : pc+2;
		pcinc = 0;
		break;
	case i_ble:
		memory[sp] = pc;
		sp++;
		pc = (comparison>=0) ? param1 : pc+2;
		pcinc = 0;
		break;

		
	case i_jra:
		pc = param1;
		pcinc = 0;
		break;
	case i_jne:
		pc = (comparison==0) ? pc+2 : param1;
		pcinc = 0;
		break;
	case i_jeq:
		pc = (comparison!=0) ? pc+2 : param1;
		pcinc = 0;
		break;
	case i_jgt:
		pc = (comparison<0) ? param1 : pc+2;
		pcinc = 0;
		break;
	case i_jlt:
		pc = (comparison>0) ? param1 : pc+2;
		pcinc = 0;
		break;
	case i_jge:
		pc = (comparison<=0) ? param1 : pc+2;
		pcinc = 0;
		break;
	case i_jle:
		pc = (comparison>=0) ? param1 : pc+2;
		pcinc = 0;
		break;

	case i_pushi:
		memory[sp] = param1;
		sp++;
		pcinc = 2;
		break;
	case i_push:
		memory[sp] = memory[param1];
		sp++;
		pcinc = 2;
		break;
	case i_pop:
		sp--;
		memory[param1] = memory[sp];
		pcinc = 2;
		break;
	case i_speek:
		sp--;
		memory[param1] = memory[sp];
		sp++;
		pcinc = 2;
		break;
	case i_setsp:
		sp = param1;
		pcinc = 2;
		break;
	case i_spill:
		spill(param1);
		pcinc = 2;
		break;
	case i_print:
		while(memory[input] != 0xDEAD)
		{
			outStr << char(memory[input]%256);
			outStr << char((memory[input] >> 2)%256);
			input += 1;
		}
		std::cout << outStr.str();
		pcinc = 2;
		break;
	case i_inint:
		std::cin >> input;
		memory[param1] = input;
		pcinc = 2;
		break;
	case i_instr:
		std::cout << "not yet lol" << std::endl;
		pcinc = 2;
		break;
	case i_and:
		memory[param2] = memory[param2] & memory[param1];
		pcinc = 3;
		break;
	case i_andi:
		memory[param2] = memory[param2] & param1;
		pcinc = 3;
		break;
	case i_or:
		memory[param2] = memory[param2] | memory[param1];
		pcinc = 3;
		break;
	case i_ori:
		memory[param2] = memory[param2] | param1;
		pcinc = 3;
		break;
	case i_lsl:
		memory[param2] = memory[param2] << param1;
		pcinc = 3;
		break;
	case i_lsr:
		memory[param2] = memory[param2] >> param1;
		pcinc = 3;
		break;
	}
	pc += pcinc;
}