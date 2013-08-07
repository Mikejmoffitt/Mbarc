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

class Mbarc
{
public:
	Mbarc(unsigned char* memory);
	unsigned char peek(unsigned int addr);
	void poke(unsigned int addr, unsigned char val);
	unsigned char getInstr(std::string friendlyName);
	void act(unsigned char instr, unsigned char param1, unsigned char param2);
private:
	unsigned char *memory;
	unsigned int pc; // Program counter
	unsigned bool zeroFlag;
};

#endif MBARC_H