#include "MBarc.h"
#include <iostream>
#include <Windows.h>
#include <limits>
#include <vector>
#include "instructions.h"

int main(int argc, char **argv)
{
	Mbarc core = Mbarc();
	std::vector<unsigned char> mems;
	
	// Build a really simple program that does not do much
	mems.push_back(NOP);
	mems.push_back(SET);
	mems.push_back(0x3); // Set number for $80 to count up to
	mems.push_back(0x81); // Store that number in $81
	mems.push_back(INC); 
	mems.push_back(0x80); // increment address $80 by 1
	mems.push_back(CMP);
	mems.push_back(0x80); // Compare $80 and $81
	mems.push_back(0x81);
	mems.push_back(BEQ); // If they are not yet equal, go back to 0x04
	mems.push_back(0x04);
	mems.push_back(ZFC);
	mems.push_back(SET); // Set $80 to zero
	mems.push_back(0x00);
	mems.push_back(0x80);
	mems.push_back(INC); // Increment the limit counter
	mems.push_back(0x81);
	mems.push_back(BRA); // Go back to 0x04
	mems.push_back(0x04);
	
	// Copy my example program into Marc's memory
	for (unsigned int i = 0; i < mems.size(); i++)
	{
		core.poke(i,mems[i]);
	}
	core.spill(true);
	int what = 0;
	system("pause");
	while (what < 64)
	{
		system("cls");
		core.run();
		core.spill(true);
		system("pause");
		what++;
	}
}