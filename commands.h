#include "instruction.h"

typedef struct {
	BasicCommandEnum commandNum;
	char * string;
} Command;

void parseLine(char * line);

Command instructionSet[CommandCount] = {
	{ADD, "add"},
	{DIV, "div"},
	{MULT, "mult"},
	{PRINT_BASIC, "print"},
	{SET, "set"},
	{SUB, "sub"}
};