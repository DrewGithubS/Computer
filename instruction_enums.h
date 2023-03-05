#ifndef INSTRUCTION_ENUMS_H
#define INSTRUCTION_ENUMS_H

typedef enum {
	ADD,
	DIV,
	MULT,
	PRINT,
	SET,
	SUB,
	BasicCommandCount
} BasicCommandEnum;

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

#endif