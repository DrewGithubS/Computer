#include "commands.h"
#include "error_codes.h"
#include "instruction_enums.h"
#include "instruction_structs.h"

int readRegisters(
					char * line,
					int currOffset,
					RegisterNum * regNum,
					int * regCount) {

	int k;
	RegisterNum j;

	for(int i = 0; i < MAX_REG_PER_INSTRUCTION; i++) {

		regNum[*regCount] = RegisterCount;

		while(line[currOffset] == ' ' && line[currOffset] != '\n') {
			currOffset++;
		}

		if(line[currOffset] != '\n') { break; }

		for(j = 0; j < RegisterCount; j++) {

			for(k = 0; registers[j].string[k] != '\0'; k++) {

				if(line[currOffset + k] != registers[j].string[k]) {
					k = -1;
					break;
				}
			}

			if(k != -1) {
				regNum[*regCount] = j;
				(*regCount)++;
				break;
			}

			if(line[currOffset + k] == '\n') { break; }

		}

		if(line[currOffset + k] != '\n') { break; }
	}

	for(int i = 0; i < MAX_REG_PER_INSTRUCTION; i++) {
		if(regNum[i] == RegisterCount) {
			return UNKNOWN_REGISTER_ERROR;
		}
	}

	return 0;
}

int parseLine(char * line, FullInstruction * instruction) {
	BasicCommandEnum command = BasicCommandCount;
	RegisterNum regNum[MAX_REG_PER_INSTRUCTION] = {NOREG};
	int regCount = 0;
	int currOffset = 0;


	for(BasicCommandEnum i = 0; i < BasicCommandCount; i++) {
		int j;

		for(j = 0; instructionSet[i].string[j] != '\0'; j++) {
			if(line[currOffset + j] != instructionSet[i].string[j]) {
				j = -1;
				break;
			}
		}

		if(j != -1) {
			command = i;
			currOffset = j;
			break;
		}
	}

	if(command == BasicCommandCount) {
		return UNKNOWN_COMMAND_ERROR;
	}

	if(readRegisters(line, currOffset, regNum, &regCount)) {
		return UNKNOWN_REGISTER_ERROR;
	}



	for(int i = 0; i < MAX_REG_PER_INSTRUCTION; i++) {
		if(regNum[0] != regNum[i]) {
			return REGISTER_TYPES_MATCHING;
		}
	}

	// BasicCommandsEnum are based on 8bit.
	// Adding register type to it will create a CommandEnum
	instruction->command = (CommandEnum) (command + regNum[0]);


	for(int i = 0; i < MAX_REG_PER_INSTRUCTION; i++) {
		instruction->regs[i] = regNum[i];
	}

	return 0;
}
