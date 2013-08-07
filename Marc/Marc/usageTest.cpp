#include "Marc.h"
#include <iostream>
#include <Windows.h>

int main(int argc, char **argv)
{
	unsigned short mem[0x65535];
	Marc core = Marc(mem);
	for (int i = 0x0; i < 0x65535; i++)
	{
		mem[i] = 0;
	}
	std::cout << "Memory zeroed out." << std::endl;
	for (int i = 0x0; i < 0x8; i++)
	{
		std::cout << "Memory at address 0x" << i << " is " << (core.memory[i]) << std::endl;
	}
	system("pause");
}