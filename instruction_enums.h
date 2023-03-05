#ifndef INSTRUCTION_ENUMS_H
#define INSTRUCTION_ENUMS_H

#define MAX_REG_PER_INSTRUCTION (3)

typedef enum {
	ADD8,
	ADD16,
	ADD32,
	ADD64,
	ADD128,
	ADD256,

	DIV8,
	DIV16,
	DIV32,
	DIV64,
	DIV128,
	DIV256,

	MULT8,
	MULT16,
	MULT32,
	MULT64,
	MULT128,
	MULT256,

	PRINT8,
	PRINT16,
	PRINT32,
	PRINT64,
	PRINT128,
	PRINT256,

	SET8,
	SET16,
	SET32,
	SET64,
	SET128,
	SET256,

	SUB8,
	SUB16,
	SUB32,
	SUB64,
	SUB128,
	SUB256,

	CommandCount
} CommandEnum;

typedef enum {
	ADD = ADD8,
	DIV = DIV8,
	MULT = MULT8,
	PRINT = PRINT8,
	SET = SET8,
	SUB = SUB8,
	BasicCommandCount
} BasicCommandEnum;

#endif