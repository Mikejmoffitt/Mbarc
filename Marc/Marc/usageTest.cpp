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
	std::vector<unsigned short> mems;
	std::string file = "";
	std::string progContents = "";
	if (argc > 1)
	{
		file = argv[1];
		std::cout << "Loading from " << file << "." << std::endl;
		std::ifstream loadMe(file.c_str());
		getline(loadMe,progContents);
	}
	else
	{
		std::cout << "No file specified... " << std::endl;
	}
	unsigned short twoBytes = 0;
	for (unsigned int i = 0; i < progContents.size(); i++)
	{
		// Fixes the fact that getine wants to treat everything as signed chars - trust me it needs it
		progContents[i] = progContents[i] - 0x80;
		if (i%2 == 0)
		{
			twoBytes += (((progContents[i])+0x80) << 8);
		}
		if (i%2 == 1)
		{
			twoBytes += (progContents[i]+0x80);
			core.poke(i/2,twoBytes);
			twoBytes = 0;
		}
	}
	// Print info on initial state
	bool runForever = false;
	std::cout << "Loaded." << std::endl;
		char input = 'x';
	while (!core.isOver())
	{
		// ONE MILLION NEWLINES
		//std::cout << std::string( 100, '\n' );
		if (input == 's')
		{
			//core.spill(0x0);
		}
		core.run();
		if (!runForever)
		{
			while (input != 's' && input != 'q' && input != 'a' && input != 'f')
			{
				std::cout << " Enter a to step, s to spill, q to quit, or f to run without waiting (may run forever).";
				std::cout << std::endl << ">>";
				std::cin >> input;
			}
			if (input == 'f')
			{
				//runForever = true;
			}
			else if (input == 'q')
			{
				break;
			}
		}
	}
	std::cout << "The program has ended successfully." << std::endl;
}