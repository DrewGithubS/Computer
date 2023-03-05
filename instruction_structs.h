#ifndef INSTRUCTION_STRUCTS_H
#define INSTRUCTION_STRUCTS_H

#include "instruction_enums.h"
#include "register_structs.h"

typedef struct {
	BasicCommandEnum commandNum;
	char * string;
} Command;

Command instructionSet[BasicCommandCount] = {
	{ADD, "add"},
	{DIV, "div"},
	{MULT, "mult"},
	{PRINT, "print"},
	{SET, "set"},
	{SUB, "sub"}
};

typedef struct {
	CommandEnum command;
	RegisterNum reg1;
	RegisterNum reg2;
	RegisterNum reg3;
	RegisterNum reg4;
} Instruction;

#endif