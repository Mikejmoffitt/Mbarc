#include "MBarc.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <string>
#include "instructions.h"

int main(int argc, char **argv)
{
	Mbarc core = Mbarc();
	std::vector<unsigned char> mems;
	std::string file = "";
	std::string progContents;
	if (argc > 1)
	{
		file = argv[1];
		std::cout << "Loading from " << file << "." << std::endl;
		std::ifstream loadMe(file.c_str());
		getline(loadMe,progContents);
	}
	else
	{
		std::cout << "No file specified, running mindless program..." << std::endl;
		core.poke(0x64,0x2F);
		core.poke(0x63,0x3A);
		core.poke(0x0,LSL);
		core.poke(0x1,0x64);
		core.poke(0x2,ZFC);
		core.poke(0x3,NCP);
		core.poke(0x4,0);
		core.poke(0x5,0x64);
		core.poke(0x6,BNE);
		core.poke(0x7,0x00);
		core.poke(0x8,INC);
		core.poke(0x9,0x63);
		core.poke(0xA,MOV);
		core.poke(0xB,0x63);
		core.poke(0xC,0x64);
		core.poke(0xD,ZFC);
		core.poke(0xE,BRA);
		core.poke(0xF,0x00);
	}

	for (unsigned int i = 0; i < progContents.size(); i++)
	{
		core.poke(i,progContents[i]);
	}
	// Print info on initial state
	core.spill(true);
	bool runForever = false;
	while (!core.isOver())
	{
		// ONE MILLION NEWLINES
		std::cout << std::string( 100, '\n' );
		core.run();
		core.spill(true);
		char input = 'x';
		if (!runForever)
		{
			while (input != 's' && input != 'q' && input != 'f')
			{
				std::cout << " Enter s to step, q to quit, or f to run without waiting (may run forever).";
				std::cout << std::endl << ">>";
				std::cin >> input;
			}
			if (input == 'f')
			{
				runForever = true;
			}
			else if (input == 'q')
			{
				break;
			}
		}
	}
	std::cout << "The program has ended successfully." << std::endl;
}