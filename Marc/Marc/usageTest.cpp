#include "MBarc.h"
#include <iostream>
#include <Windows.h>
#include <limits>
#include "instructions.h"

int main(int argc, char **argv)
{
	Mbarc core = Mbarc();


	// Build a really simple program that does not do much
	core.poke(0x0,NOP);
	core.poke(0x1,INC);
	core.poke(0x2,0x64);
	core.poke(0x3,INC);
	core.poke(0x4,0x64);
	core.poke(0x5,BRA);
	core.poke(0x6,0x0);

	int what = 0;
	while (what < 64)
	{
		core.run();
		core.spill(true);
		system("pause");
		what++;
	}
}