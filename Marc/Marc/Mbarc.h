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

// 640k should be enough for anybody.
#define MEM_AMT ((USHRT_MAX+1) * 5)

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
	signed int comparison;
	bool overFlow;
	unsigned int sp; // Stack pointer
	unsigned short remainder; // For doing mod stuff
};

#endif MBARC_H