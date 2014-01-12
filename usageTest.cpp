#include "Mbarc.h"
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
	// TODO: replace this looney-tunes file loader
	if (argc > 1)
	{
		file = argv[1];
		std::cout << "Loading from " << file << "... ";
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
		// Signed to unsigned fix...
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
	std::cout << "ok." << std::endl;
	core.spill(false);
	char input = '\0';
	while (!core.isOver())
	{
		// ONE MILLION NEWLINES BECAUSE THERE IS NO CROSS PLATFORM "CLEAR" COMMAND
		//std::cout << std::string( 100, '\n' );
		if (input == 's')
		{
			core.spill(0x0);
		}
		core.run();
		input = '\0';
		if (!runForever)
		{
			while (input != 's' && input != 'q' && input != 'a' && input != 'f')
			{
				std::cout << " Enter s to step, a to step (no output), q to quit, or f to run without waiting (may run forever).";
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
