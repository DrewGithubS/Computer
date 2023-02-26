typedef enum {
	ADD,
	DIV,
	MULT,
	PRINT,
	SET,
	SUB,
	CommandCount
} CommandNums;

typedef struct {
	CommandNums commandNum;
	char * string;
} Command;

void parseLine(char * line);