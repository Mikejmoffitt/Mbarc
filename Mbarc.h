/*

Moffitt's Bogus Architecture
By Michael Moffitt

*/

#ifndef MBARC_H
#define MBARC_H
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <limits>
#include "instructions.h"
#include <limits>

#define MEM_AMT 4096

class Mbarc
{
public:
	Mbarc();
	unsigned short peek(unsigned int addr);
	void poke(unsigned int addr, unsigned short val);
	void act(unsigned short instrct, unsigned short param1, unsigned short param2);
	void spill(unsigned int start); // Prints status info, verbose prints EVERYTHING
	void run();
	bool isOver();
private:
	unsigned short memory[MEM_AMT];
	unsigned int pc; // Program counter
	short comparison;
	bool overFlow;
	unsigned int sp; // Stack pointer
	unsigned short remainder; // For doing mod stuff
};

#endif
