#include "commands.h"
#include "error_codes.h"
#include "instruction_structs.h"

int parseLine(char * line) {
	BasicCommandEnum command = BasicCommandCount;

	for(BasicCommandEnum i = 0; i < BasicCommandCount; i++) {
		int j;

		for(j = 0; instructionSet[i].string[j] != '\0'; j++) {
			if(line[j] != instructionSet[i].string[j]) {
				j = -1;
				break;
			}
		}

		if(j != -1) {
			command = i;
			break;
		}
	}

	if(command == BasicCommandCount) {
		return UNKNOWN_COMMAND_ERROR;
	}

	return 0;
}
