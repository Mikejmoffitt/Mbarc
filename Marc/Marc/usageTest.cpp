#include "MBarc.h"
#include <iostream>
#include <Windows.h>
#include <limits>

#define MEMAMT UCHAR_MAX

int main(int argc, char **argv)
{
	unsigned char mem[MEMAMT];
	Mbarc core = Mbarc(mem);
	for (int i = 0x0; i < MEMAMT; i++)
	{
		mem[i] = 0;
	}
	std::cout << "Memory zeroed out." << std::endl;
	core.poke(0x32,0x80);
	for (int i = 0x0; i < MEMAMT/4; i++)
	{
		std::cout << "0x" << std::hex << std::uppercase << (i*4) << " == 0x" << int((core.peek((i*4)))) << std::nouppercase << std::dec << "\t";
		std::cout << "0x" << std::hex << std::uppercase << ((i*4)+1) << " == 0x" << int(core.peek((i*4)+1)) << std::nouppercase << std::dec << "\t";
		std::cout << "0x" << std::hex << std::uppercase << ((i*4)+2) << " == 0x" << int(core.peek((i*4)+2)) << std::nouppercase << std::dec << "\t";
		std::cout << "0x" << std::hex << std::uppercase << ((i*4)+3) << " == 0x" << int(core.peek((i*4)+3)) << std::nouppercase << std::dec << std::endl;
	}
	system("pause");
}