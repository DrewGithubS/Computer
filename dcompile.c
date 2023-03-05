#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#include "commands.h"
#include "error_codes.h"

// The format of each instruction is below:
// <command> <argument1> <argument2> <argument3> ...

void compile(FILE * inFile, FILE * outFile, FILE * verbFile);

void printHelp() {
	printf("Usage: ./dcompile -i <input file> -o <output file>\n");
}

int main(int argc, char ** argv) {
	int opt;
	char * inputFile = 0;
	char * verboseFile = 0;
	char * outputFile = 0;
      
    // put ':' in the starting of the
    // string so that program can 
    // distinguish between '?' and ':' 
    while((opt = getopt(argc, argv, "i:o:")) != -1) { 
		switch(opt) { 
		case 'i':
			inputFile = optarg;
			break;
		case 'o':
			outputFile = optarg;
			break;
		case 'v':
			verboseFile = optarg;
			break;
		case ':': 
			printf("Option needs a value\n"); 
			break; 
		case '?': 
			printf("Unknown option: %c\n", optopt);
			break; 
		} 
	}

	if(inputFile == 0 || outputFile == 0) {
		printf("Missing options.\n");
		printHelp();
		return 1;
	}

	FILE * inFile = fopen(inputFile, "r");
	if(inFile == 0) {
		printf("Could not find input file: %s\n", inputFile);
		return 1;
	}

	FILE * outFile = fopen(outputFile, "wb");
	if(outFile == 0) {
		printf("Could not open output file: %s\n", outputFile);
		return 1;
	}

	FILE * verbFile = 0;
	if(verboseFile != 0) {
		verbFile = fopen(verboseFile, "w");
		if(verbFile == 0) {
			printf("Could not open verbose file: %s\n", verboseFile);
			return 1;
		}
	}

	compile(inFile, outFile, verbFile);
}

int handleError(int errorCode, int lineNumber) {
	switch(errorCode) {
	case UNKNOWN_COMMAND_ERROR:
		printf("Unknown command on line %d.\n", lineNumber);
		return 1;
	case UNKNOWN_REGISTER_ERROR:
		printf("Unknown register on line %d.\n", lineNumber);
		return 1;
	case REGISTER_TYPES_MATCHING:
		printf("Register types don't match on line %d.\n", lineNumber);
		return 1;
	default:
		return 0;
	}
}

#define MAXLINESIZE (500)
void compile(FILE * inFile, FILE * outFile, FILE * verboseFile) {
	char * line = (char *) malloc(MAXLINESIZE * sizeof(char));
	size_t len = MAXLINESIZE;
	uint32_t read;

	int lineNumber = 0;

	FullInstruction instruction;

	while((read = getline(&line, &len, inFile)) != -1) {
		lineNumber++;
		handleError(parseLine(line, &instruction), lineNumber);
		fwrite(&instruction, sizeof(FullInstruction), 1, outFile);
	}
}