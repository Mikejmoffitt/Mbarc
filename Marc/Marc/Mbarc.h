/*

Moffitt's Bogus Architecture
By Michael Moffitt

*/

#ifndef MBARC_H
#define MBARC_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <limits>

class Mbarc
{
public:
	Mbarc();
	unsigned char peek(unsigned int addr);
	void poke(unsigned int addr, unsigned char val);
	unsigned char getInstr(std::string friendlyName);
	void act(unsigned char instr, unsigned char param1, unsigned char param2);
	void spill(bool verbose); // Prints status info, verbose prints EVERYTHING
	void run();
private:
	unsigned char memory[UCHAR_MAX+1];
	unsigned char pc; // Program counter
	bool zeroFlag;
	bool overFlow;
};

#endif MBARC_H