#include <stdint.h>


typedef enum {
	ADD,
	DIV,
	MULT,
	PRINT_BASIC,
	SET,
	SUB,
	BasicCommandCount
} BasicCommandEnum;

typedef struct {
	BasicCommandEnum commandNum;
	char * string;
} Command;

Command instructionSet[CommandCount] = {
	{ADD, "add"},
	{DIV, "div"},
	{MULT, "mult"},
	{PRINT_BASIC, "print"},
	{SET, "set"},
	{SUB, "sub"}
};

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

	PRINT,

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
	EightBit,
	SixteenBit,
	ThirtyTwoBit,
	SixtyFourBit,
	OneTwentyEightBit,
	TwoFiftySixBit
} RegisterType;

typedef enum {
	// (E)ight bit registers
	e0,
	e1,
	e2,
	e3,
	e4,
	e5,
	e6,
	e7,
	e8,
	e9,
	e10,
	e11,
	e12,
	e13,
	e14,
	e15,

	// (S)ixteen bit registers
	s0,
	s1,
	s2,
	s3,
	s4,
	s5,
	s6,
	s7,

	// (E)ight bit subregister of 
	// (S)ixteen bit register
	se0_0,
	se0_1,
	se1_0,
	se1_1,
	se2_0,
	se2_1,
	se3_0,
	se3_1,
	se4_0,
	se4_1,
	se5_0,
	se5_1,
	se6_0,
	se6_1,
	se7_0,
	se7_1,

	// (T)hirty-two bit registers
	t0,
	t1,
	t2,
	t3,
	t4,
	t5,
	t6,
	t7,

	// (S)ixteen bit subregister of 
	// (T)hirty-two bit register
	ts0_0,
	ts0_1,
	ts1_0,
	ts1_1,
	ts2_0,
	ts2_1,
	ts3_0,
	ts3_1,
	ts4_0,
	ts4_1,
	ts5_0,
	ts5_1,
	ts6_0,
	ts6_1,
	ts7_0,
	ts7_1,

	// (E)ight bit subregister of 
	// (T)hirty-two bit register
	te0_0,
	te0_1,
	te0_2,
	te0_3,
	te1_0,
	te1_1,
	te1_2,
	te1_3,
	te2_0,
	te2_1,
	te2_2,
	te2_3,
	te3_0,
	te3_1,
	te3_2,
	te3_3,
	te4_0,
	te4_1,
	te4_2,
	te4_3,
	te5_0,
	te5_1,
	te5_2,
	te5_3,
	te6_0,
	te6_1,
	te6_2,
	te6_3,
	te7_0,
	te7_1,
	te7_2,
	te7_3,

	// Sixty-(F)our bit registers
	f0,
	f1,
	f2,
	f3,

	// (T)hirty-two bit subregister of 
	// Sixty-(F)our bit register
	ft0_0,
	ft0_1,
	ft1_0,
	ft1_1,
	ft2_0,
	ft2_1,
	ft3_0,
	ft3_1,

	// (S)ixteen bit subregister of 
	// Sixty-(F)our bit register
	fs0_0,
	fs0_1,
	fs0_2,
	fs0_3,
	fs1_0,
	fs1_1,
	fs1_2,
	fs1_3,
	fs2_0,
	fs2_1,
	fs2_2,
	fs2_3,
	fs3_0,
	fs3_1,
	fs3_2,
	fs3_3,

	// (E)ight bit subregister of 
	// Sixty-(F)our bit register
	fe0_0,
	fe0_1,
	fe0_2,
	fe0_3,
	fe0_4,
	fe0_5,
	fe0_6,
	fe0_7,
	fe1_0,
	fe1_1,
	fe1_2,
	fe1_3,
	fe1_4,
	fe1_5,
	fe1_6,
	fe1_7,
	fe2_0,
	fe2_1,
	fe2_2,
	fe2_3,
	fe2_4,
	fe2_5,
	fe2_6,
	fe2_7,
	fe3_0,
	fe3_1,
	fe3_2,
	fe3_3,
	fe3_4,
	fe3_5,
	fe3_6,
	fe3_7,

	// (O)ne Hundred Twenty-Six bit registers
	o0,
	o1,

	// Sixty-(F)our bit subregister of 
	// (O)ne Hundred Twenty-Six bit register
	of0_0,
	of0_1,
	of1_0,
	of1_1,

	// (T)hirty-two bit subregister of 
	// (O)ne Hundred Twenty-Six bit register
	ot0_0,
	ot0_1,
	ot0_2,
	ot0_3,
	ot1_0,
	ot1_1,
	ot1_2,
	ot1_3,

	// (S)ixteen bit subregister of 
	// (O)ne Hundred Twenty-Six bit register
	os0_0,
	os0_1,
	os0_2,
	os0_3,
	os0_4,
	os0_5,
	os0_6,
	os0_7,
	os1_0,
	os1_1,
	os1_2,
	os1_3,
	os1_4,
	os1_5,
	os1_6,
	os1_7,

	// (E)ight bit subregister of 
	// (O)ne Hundred Twenty-Six bit register
	oe0_0,
	oe0_1,
	oe0_2,
	oe0_3,
	oe0_4,
	oe0_5,
	oe0_6,
	oe0_7,
	oe0_8,
	oe0_9,
	oe0_10,
	oe0_11,
	oe0_12,
	oe0_13,
	oe0_14,
	oe0_15,
	oe1_0,
	oe1_1,
	oe1_2,
	oe1_3,
	oe1_4,
	oe1_5,
	oe1_6,
	oe1_7,
	oe1_8,
	oe1_9,
	oe1_10,
	oe1_11,
	oe1_12,
	oe1_13,
	oe1_14,
	oe1_15,

	// T(w)o Hundred Sixty-Four bit registers
	w0,
	w1,

	// (O)ne Hundred Twenty-Six bit subregister of 
	// T(w)o Hundred Sixty-Four bit register
	wo0_0,
	wo0_1,
	wo1_0,
	wo1_1,

	// Sixty-(F)our bit subregister of 
	// T(w)o Hundred Sixty-Four bit register
	wf0_0,
	wf0_1,
	wf0_2,
	wf0_3,
	wf1_0,
	wf1_1,
	wf1_2,
	wf1_3,

	// (T)hirty-two bit subregister of 
	// T(w)o Hundred Sixty-Four bit register
	wt0_0,
	wt0_1,
	wt0_2,
	wt0_3,
	wt0_4,
	wt0_5,
	wt0_6,
	wt0_7,
	wt1_0,
	wt1_1,
	wt1_2,
	wt1_3,
	wt1_4,
	wt1_5,
	wt1_6,
	wt1_7,

	// (S)ixteen bit subregister of 
	// T(w)o Hundred Sixty-Four bit register
	ws0_0,
	ws0_1,
	ws0_2,
	ws0_3,
	ws0_4,
	ws0_5,
	ws0_6,
	ws0_7,
	ws0_8,
	ws0_9,
	ws0_10,
	ws0_11,
	ws0_12,
	ws0_13,
	ws0_14,
	ws0_15,
	ws1_0,
	ws1_1,
	ws1_2,
	ws1_3,
	ws1_4,
	ws1_5,
	ws1_6,
	ws1_7,
	ws1_8,
	ws1_9,
	ws1_10,
	ws1_11,
	ws1_12,
	ws1_13,
	ws1_14,
	ws1_15,

	// (E)ight bit subregister of 
	// T(w)o Hundred Sixty-Four bit register
	we0_0,
	we0_1,
	we0_2,
	we0_3,
	we0_4,
	we0_5,
	we0_6,
	we0_7,
	we0_8,
	we0_9,
	we0_10,
	we0_11,
	we0_12,
	we0_13,
	we0_14,
	we0_15,
	we0_16,
	we0_17,
	we0_18,
	we0_19,
	we0_20,
	we0_21,
	we0_22,
	we0_23,
	we0_24,
	we0_25,
	we0_26,
	we0_27,
	we0_28,
	we0_29,
	we0_30,
	we0_31,
	we1_0,
	we1_1,
	we1_2,
	we1_3,
	we1_4,
	we1_5,
	we1_6,
	we1_7,
	we1_8,
	we1_9,
	we1_10,
	we1_11,
	we1_12,
	we1_13,
	we1_14,
	we1_15,
	we1_16,
	we1_17,
	we1_18,
	we1_19,
	we1_20,
	we1_21,
	we1_22,
	we1_23,
	we1_24,
	we1_25,
	we1_26,
	we1_27,
	we1_28,
	we1_29,
	we1_30,
	we1_31,

	REGISTERCOUNT
} RegisterNum;

typedef struct {
	RegisterNum num;
	RegisterType type;
	char * string;
} Register;

typedef struct {
	CommandEnum command;
	RegisterNum reg1;
	RegisterNum reg2;
	RegisterNum reg3;
	RegisterNum reg4;
} Instruction;

Register registers[] = {
	{e0, EightBit, "e0"},
	{e1, EightBit, "e1"},
	{e2, EightBit, "e2"},
	{e3, EightBit, "e3"},
	{e4, EightBit, "e4"},
	{e5, EightBit, "e5"},
	{e6, EightBit, "e6"},
	{e7, EightBit, "e7"},
	{e8, EightBit, "e8"},
	{e9, EightBit, "e9"},
	{e10, EightBit, "e10"},
	{e11, EightBit, "e11"},
	{e12, EightBit, "e12"},
	{e13, EightBit, "e13"},
	{e14, EightBit, "e14"},
	{e15, EightBit, "e15"},
	{s0, SixteenBit, "s0"},
	{s1, SixteenBit, "s1"},
	{s2, SixteenBit, "s2"},
	{s3, SixteenBit, "s3"},
	{s4, SixteenBit, "s4"},
	{s5, SixteenBit, "s5"},
	{s6, SixteenBit, "s6"},
	{s7, SixteenBit, "s7"},

	{se0_0, SixteenBit, "se0_0"},
	{se0_1, SixteenBit, "se0_1"},
	{se1_0, SixteenBit, "se1_0"},
	{se1_1, SixteenBit, "se1_1"},
	{se2_0, SixteenBit, "se2_0"},
	{se2_1, SixteenBit, "se2_1"},
	{se3_0, SixteenBit, "se3_0"},
	{se3_1, SixteenBit, "se3_1"},
	{se4_0, SixteenBit, "se4_0"},
	{se4_1, SixteenBit, "se4_1"},
	{se5_0, SixteenBit, "se5_0"},
	{se5_1, SixteenBit, "se5_1"},
	{se6_0, SixteenBit, "se6_0"},
	{se6_1, SixteenBit, "se6_1"},
	{se7_0, SixteenBit, "se7_0"},
	{se7_1, SixteenBit, "se7_1"},
	{t0, ThirtyTwoBit, "t0"},
	{t1, ThirtyTwoBit, "t1"},
	{t2, ThirtyTwoBit, "t2"},
	{t3, ThirtyTwoBit, "t3"},
	{t4, ThirtyTwoBit, "t4"},
	{t5, ThirtyTwoBit, "t5"},
	{t6, ThirtyTwoBit, "t6"},
	{t7, ThirtyTwoBit, "t7"},

	{ts0_0, ThirtyTwoBit, "ts0_0"},
	{ts0_1, ThirtyTwoBit, "ts0_1"},
	{ts1_0, ThirtyTwoBit, "ts1_0"},
	{ts1_1, ThirtyTwoBit, "ts1_1"},
	{ts2_0, ThirtyTwoBit, "ts2_0"},
	{ts2_1, ThirtyTwoBit, "ts2_1"},
	{ts3_0, ThirtyTwoBit, "ts3_0"},
	{ts3_1, ThirtyTwoBit, "ts3_1"},
	{ts4_0, ThirtyTwoBit, "ts4_0"},
	{ts4_1, ThirtyTwoBit, "ts4_1"},
	{ts5_0, ThirtyTwoBit, "ts5_0"},
	{ts5_1, ThirtyTwoBit, "ts5_1"},
	{ts6_0, ThirtyTwoBit, "ts6_0"},
	{ts6_1, ThirtyTwoBit, "ts6_1"},
	{ts7_0, ThirtyTwoBit, "ts7_0"},
	{ts7_1, ThirtyTwoBit, "ts7_1"},

	{te0_0, ThirtyTwoBit, "te0_0"},
	{te0_1, ThirtyTwoBit, "te0_1"},
	{te0_2, ThirtyTwoBit, "te0_2"},
	{te0_3, ThirtyTwoBit, "te0_3"},
	{te1_0, ThirtyTwoBit, "te1_0"},
	{te1_1, ThirtyTwoBit, "te1_1"},
	{te1_2, ThirtyTwoBit, "te1_2"},
	{te1_3, ThirtyTwoBit, "te1_3"},
	{te2_0, ThirtyTwoBit, "te2_0"},
	{te2_1, ThirtyTwoBit, "te2_1"},
	{te2_2, ThirtyTwoBit, "te2_2"},
	{te2_3, ThirtyTwoBit, "te2_3"},
	{te3_0, ThirtyTwoBit, "te3_0"},
	{te3_1, ThirtyTwoBit, "te3_1"},
	{te3_2, ThirtyTwoBit, "te3_2"},
	{te3_3, ThirtyTwoBit, "te3_3"},
	{te4_0, ThirtyTwoBit, "te4_0"},
	{te4_1, ThirtyTwoBit, "te4_1"},
	{te4_2, ThirtyTwoBit, "te4_2"},
	{te4_3, ThirtyTwoBit, "te4_3"},
	{te5_0, ThirtyTwoBit, "te5_0"},
	{te5_1, ThirtyTwoBit, "te5_1"},
	{te5_2, ThirtyTwoBit, "te5_2"},
	{te5_3, ThirtyTwoBit, "te5_3"},
	{te6_0, ThirtyTwoBit, "te6_0"},
	{te6_1, ThirtyTwoBit, "te6_1"},
	{te6_2, ThirtyTwoBit, "te6_2"},
	{te6_3, ThirtyTwoBit, "te6_3"},
	{te7_0, ThirtyTwoBit, "te7_0"},
	{te7_1, ThirtyTwoBit, "te7_1"},
	{te7_2, ThirtyTwoBit, "te7_2"},
	{te7_3, ThirtyTwoBit, "te7_3"},
	{f0, SixtyFourBit, "f0"},
	{f1, SixtyFourBit, "f1"},
	{f2, SixtyFourBit, "f2"},
	{f3, SixtyFourBit, "f3"},

	{ft0_0, SixtyFourBit, "ft0_0"},
	{ft0_1, SixtyFourBit, "ft0_1"},
	{ft1_0, SixtyFourBit, "ft1_0"},
	{ft1_1, SixtyFourBit, "ft1_1"},
	{ft2_0, SixtyFourBit, "ft2_0"},
	{ft2_1, SixtyFourBit, "ft2_1"},
	{ft3_0, SixtyFourBit, "ft3_0"},
	{ft3_1, SixtyFourBit, "ft3_1"},

	{fs0_0, SixtyFourBit, "fs0_0"},
	{fs0_1, SixtyFourBit, "fs0_1"},
	{fs0_2, SixtyFourBit, "fs0_2"},
	{fs0_3, SixtyFourBit, "fs0_3"},
	{fs1_0, SixtyFourBit, "fs1_0"},
	{fs1_1, SixtyFourBit, "fs1_1"},
	{fs1_2, SixtyFourBit, "fs1_2"},
	{fs1_3, SixtyFourBit, "fs1_3"},
	{fs2_0, SixtyFourBit, "fs2_0"},
	{fs2_1, SixtyFourBit, "fs2_1"},
	{fs2_2, SixtyFourBit, "fs2_2"},
	{fs2_3, SixtyFourBit, "fs2_3"},
	{fs3_0, SixtyFourBit, "fs3_0"},
	{fs3_1, SixtyFourBit, "fs3_1"},
	{fs3_2, SixtyFourBit, "fs3_2"},
	{fs3_3, SixtyFourBit, "fs3_3"},

	{fe0_0, SixtyFourBit, "fe0_0"},
	{fe0_1, SixtyFourBit, "fe0_1"},
	{fe0_2, SixtyFourBit, "fe0_2"},
	{fe0_3, SixtyFourBit, "fe0_3"},
	{fe0_4, SixtyFourBit, "fe0_4"},
	{fe0_5, SixtyFourBit, "fe0_5"},
	{fe0_6, SixtyFourBit, "fe0_6"},
	{fe0_7, SixtyFourBit, "fe0_7"},
	{fe1_0, SixtyFourBit, "fe1_0"},
	{fe1_1, SixtyFourBit, "fe1_1"},
	{fe1_2, SixtyFourBit, "fe1_2"},
	{fe1_3, SixtyFourBit, "fe1_3"},
	{fe1_4, SixtyFourBit, "fe1_4"},
	{fe1_5, SixtyFourBit, "fe1_5"},
	{fe1_6, SixtyFourBit, "fe1_6"},
	{fe1_7, SixtyFourBit, "fe1_7"},
	{fe2_0, SixtyFourBit, "fe2_0"},
	{fe2_1, SixtyFourBit, "fe2_1"},
	{fe2_2, SixtyFourBit, "fe2_2"},
	{fe2_3, SixtyFourBit, "fe2_3"},
	{fe2_4, SixtyFourBit, "fe2_4"},
	{fe2_5, SixtyFourBit, "fe2_5"},
	{fe2_6, SixtyFourBit, "fe2_6"},
	{fe2_7, SixtyFourBit, "fe2_7"},
	{fe3_0, SixtyFourBit, "fe3_0"},
	{fe3_1, SixtyFourBit, "fe3_1"},
	{fe3_2, SixtyFourBit, "fe3_2"},
	{fe3_3, SixtyFourBit, "fe3_3"},
	{fe3_4, SixtyFourBit, "fe3_4"},
	{fe3_5, SixtyFourBit, "fe3_5"},
	{fe3_6, SixtyFourBit, "fe3_6"},
	{fe3_7, SixtyFourBit, "fe3_7"},
	{o0, OneTwentyEightBit, "o0"},
	{o1, OneTwentyEightBit, "o1"},

	{of0_0, OneTwentyEightBit, "of0_0"},
	{of0_1, OneTwentyEightBit, "of0_1"},
	{of1_0, OneTwentyEightBit, "of1_0"},
	{of1_1, OneTwentyEightBit, "of1_1"},

	{ot0_0, OneTwentyEightBit, "ot0_0"},
	{ot0_1, OneTwentyEightBit, "ot0_1"},
	{ot0_2, OneTwentyEightBit, "ot0_2"},
	{ot0_3, OneTwentyEightBit, "ot0_3"},
	{ot1_0, OneTwentyEightBit, "ot1_0"},
	{ot1_1, OneTwentyEightBit, "ot1_1"},
	{ot1_2, OneTwentyEightBit, "ot1_2"},
	{ot1_3, OneTwentyEightBit, "ot1_3"},

	{os0_0, OneTwentyEightBit, "os0_0"},
	{os0_1, OneTwentyEightBit, "os0_1"},
	{os0_2, OneTwentyEightBit, "os0_2"},
	{os0_3, OneTwentyEightBit, "os0_3"},
	{os0_4, OneTwentyEightBit, "os0_4"},
	{os0_5, OneTwentyEightBit, "os0_5"},
	{os0_6, OneTwentyEightBit, "os0_6"},
	{os0_7, OneTwentyEightBit, "os0_7"},
	{os1_0, OneTwentyEightBit, "os1_0"},
	{os1_1, OneTwentyEightBit, "os1_1"},
	{os1_2, OneTwentyEightBit, "os1_2"},
	{os1_3, OneTwentyEightBit, "os1_3"},
	{os1_4, OneTwentyEightBit, "os1_4"},
	{os1_5, OneTwentyEightBit, "os1_5"},
	{os1_6, OneTwentyEightBit, "os1_6"},
	{os1_7, OneTwentyEightBit, "os1_7"},

	{oe0_0, OneTwentyEightBit, "oe0_0"},
	{oe0_1, OneTwentyEightBit, "oe0_1"},
	{oe0_2, OneTwentyEightBit, "oe0_2"},
	{oe0_3, OneTwentyEightBit, "oe0_3"},
	{oe0_4, OneTwentyEightBit, "oe0_4"},
	{oe0_5, OneTwentyEightBit, "oe0_5"},
	{oe0_6, OneTwentyEightBit, "oe0_6"},
	{oe0_7, OneTwentyEightBit, "oe0_7"},
	{oe0_8, OneTwentyEightBit, "oe0_8"},
	{oe0_9, OneTwentyEightBit, "oe0_9"},
	{oe0_10, OneTwentyEightBit, "oe0_10"},
	{oe0_11, OneTwentyEightBit, "oe0_11"},
	{oe0_12, OneTwentyEightBit, "oe0_12"},
	{oe0_13, OneTwentyEightBit, "oe0_13"},
	{oe0_14, OneTwentyEightBit, "oe0_14"},
	{oe0_15, OneTwentyEightBit, "oe0_15"},
	{oe1_0, OneTwentyEightBit, "oe1_0"},
	{oe1_1, OneTwentyEightBit, "oe1_1"},
	{oe1_2, OneTwentyEightBit, "oe1_2"},
	{oe1_3, OneTwentyEightBit, "oe1_3"},
	{oe1_4, OneTwentyEightBit, "oe1_4"},
	{oe1_5, OneTwentyEightBit, "oe1_5"},
	{oe1_6, OneTwentyEightBit, "oe1_6"},
	{oe1_7, OneTwentyEightBit, "oe1_7"},
	{oe1_8, OneTwentyEightBit, "oe1_8"},
	{oe1_9, OneTwentyEightBit, "oe1_9"},
	{oe1_10, OneTwentyEightBit, "oe1_10"},
	{oe1_11, OneTwentyEightBit, "oe1_11"},
	{oe1_12, OneTwentyEightBit, "oe1_12"},
	{oe1_13, OneTwentyEightBit, "oe1_13"},
	{oe1_14, OneTwentyEightBit, "oe1_14"},
	{oe1_15, OneTwentyEightBit, "oe1_15"},
	{w0, TwoFiftySixBit, "w0"},
	{w1, TwoFiftySixBit, "w1"},

	{wo0_0, TwoFiftySixBit, "wo0_0"},
	{wo0_1, TwoFiftySixBit, "wo0_1"},
	{wo1_0, TwoFiftySixBit, "wo1_0"},
	{wo1_1, TwoFiftySixBit, "wo1_1"},

	{wf0_0, TwoFiftySixBit, "wf0_0"},
	{wf0_1, TwoFiftySixBit, "wf0_1"},
	{wf0_2, TwoFiftySixBit, "wf0_2"},
	{wf0_3, TwoFiftySixBit, "wf0_3"},
	{wf1_0, TwoFiftySixBit, "wf1_0"},
	{wf1_1, TwoFiftySixBit, "wf1_1"},
	{wf1_2, TwoFiftySixBit, "wf1_2"},
	{wf1_3, TwoFiftySixBit, "wf1_3"},

	{wt0_0, TwoFiftySixBit, "wt0_0"},
	{wt0_1, TwoFiftySixBit, "wt0_1"},
	{wt0_2, TwoFiftySixBit, "wt0_2"},
	{wt0_3, TwoFiftySixBit, "wt0_3"},
	{wt0_4, TwoFiftySixBit, "wt0_4"},
	{wt0_5, TwoFiftySixBit, "wt0_5"},
	{wt0_6, TwoFiftySixBit, "wt0_6"},
	{wt0_7, TwoFiftySixBit, "wt0_7"},
	{wt1_0, TwoFiftySixBit, "wt1_0"},
	{wt1_1, TwoFiftySixBit, "wt1_1"},
	{wt1_2, TwoFiftySixBit, "wt1_2"},
	{wt1_3, TwoFiftySixBit, "wt1_3"},
	{wt1_4, TwoFiftySixBit, "wt1_4"},
	{wt1_5, TwoFiftySixBit, "wt1_5"},
	{wt1_6, TwoFiftySixBit, "wt1_6"},
	{wt1_7, TwoFiftySixBit, "wt1_7"},

	{ws0_0, TwoFiftySixBit, "ws0_0"},
	{ws0_1, TwoFiftySixBit, "ws0_1"},
	{ws0_2, TwoFiftySixBit, "ws0_2"},
	{ws0_3, TwoFiftySixBit, "ws0_3"},
	{ws0_4, TwoFiftySixBit, "ws0_4"},
	{ws0_5, TwoFiftySixBit, "ws0_5"},
	{ws0_6, TwoFiftySixBit, "ws0_6"},
	{ws0_7, TwoFiftySixBit, "ws0_7"},
	{ws0_8, TwoFiftySixBit, "ws0_8"},
	{ws0_9, TwoFiftySixBit, "ws0_9"},
	{ws0_10, TwoFiftySixBit, "ws0_10"},
	{ws0_11, TwoFiftySixBit, "ws0_11"},
	{ws0_12, TwoFiftySixBit, "ws0_12"},
	{ws0_13, TwoFiftySixBit, "ws0_13"},
	{ws0_14, TwoFiftySixBit, "ws0_14"},
	{ws0_15, TwoFiftySixBit, "ws0_15"},
	{ws1_0, TwoFiftySixBit, "ws1_0"},
	{ws1_1, TwoFiftySixBit, "ws1_1"},
	{ws1_2, TwoFiftySixBit, "ws1_2"},
	{ws1_3, TwoFiftySixBit, "ws1_3"},
	{ws1_4, TwoFiftySixBit, "ws1_4"},
	{ws1_5, TwoFiftySixBit, "ws1_5"},
	{ws1_6, TwoFiftySixBit, "ws1_6"},
	{ws1_7, TwoFiftySixBit, "ws1_7"},
	{ws1_8, TwoFiftySixBit, "ws1_8"},
	{ws1_9, TwoFiftySixBit, "ws1_9"},
	{ws1_10, TwoFiftySixBit, "ws1_10"},
	{ws1_11, TwoFiftySixBit, "ws1_11"},
	{ws1_12, TwoFiftySixBit, "ws1_12"},
	{ws1_13, TwoFiftySixBit, "ws1_13"},
	{ws1_14, TwoFiftySixBit, "ws1_14"},
	{ws1_15, TwoFiftySixBit, "ws1_15"},

	{we0_0, TwoFiftySixBit, "we0_0"},
	{we0_1, TwoFiftySixBit, "we0_1"},
	{we0_2, TwoFiftySixBit, "we0_2"},
	{we0_3, TwoFiftySixBit, "we0_3"},
	{we0_4, TwoFiftySixBit, "we0_4"},
	{we0_5, TwoFiftySixBit, "we0_5"},
	{we0_6, TwoFiftySixBit, "we0_6"},
	{we0_7, TwoFiftySixBit, "we0_7"},
	{we0_8, TwoFiftySixBit, "we0_8"},
	{we0_9, TwoFiftySixBit, "we0_9"},
	{we0_10, TwoFiftySixBit, "we0_10"},
	{we0_11, TwoFiftySixBit, "we0_11"},
	{we0_12, TwoFiftySixBit, "we0_12"},
	{we0_13, TwoFiftySixBit, "we0_13"},
	{we0_14, TwoFiftySixBit, "we0_14"},
	{we0_15, TwoFiftySixBit, "we0_15"},
	{we0_16, TwoFiftySixBit, "we0_16"},
	{we0_17, TwoFiftySixBit, "we0_17"},
	{we0_18, TwoFiftySixBit, "we0_18"},
	{we0_19, TwoFiftySixBit, "we0_19"},
	{we0_20, TwoFiftySixBit, "we0_20"},
	{we0_21, TwoFiftySixBit, "we0_21"},
	{we0_22, TwoFiftySixBit, "we0_22"},
	{we0_23, TwoFiftySixBit, "we0_23"},
	{we0_24, TwoFiftySixBit, "we0_24"},
	{we0_25, TwoFiftySixBit, "we0_25"},
	{we0_26, TwoFiftySixBit, "we0_26"},
	{we0_27, TwoFiftySixBit, "we0_27"},
	{we0_28, TwoFiftySixBit, "we0_28"},
	{we0_29, TwoFiftySixBit, "we0_29"},
	{we0_30, TwoFiftySixBit, "we0_30"},
	{we0_31, TwoFiftySixBit, "we0_31"},
	{we1_0, TwoFiftySixBit, "we1_0"},
	{we1_1, TwoFiftySixBit, "we1_1"},
	{we1_2, TwoFiftySixBit, "we1_2"},
	{we1_3, TwoFiftySixBit, "we1_3"},
	{we1_4, TwoFiftySixBit, "we1_4"},
	{we1_5, TwoFiftySixBit, "we1_5"},
	{we1_6, TwoFiftySixBit, "we1_6"},
	{we1_7, TwoFiftySixBit, "we1_7"},
	{we1_8, TwoFiftySixBit, "we1_8"},
	{we1_9, TwoFiftySixBit, "we1_9"},
	{we1_10, TwoFiftySixBit, "we1_10"},
	{we1_11, TwoFiftySixBit, "we1_11"},
	{we1_12, TwoFiftySixBit, "we1_12"},
	{we1_13, TwoFiftySixBit, "we1_13"},
	{we1_14, TwoFiftySixBit, "we1_14"},
	{we1_15, TwoFiftySixBit, "we1_15"},
	{we1_16, TwoFiftySixBit, "we1_16"},
	{we1_17, TwoFiftySixBit, "we1_17"},
	{we1_18, TwoFiftySixBit, "we1_18"},
	{we1_19, TwoFiftySixBit, "we1_19"},
	{we1_20, TwoFiftySixBit, "we1_20"},
	{we1_21, TwoFiftySixBit, "we1_21"},
	{we1_22, TwoFiftySixBit, "we1_22"},
	{we1_23, TwoFiftySixBit, "we1_23"},
	{we1_24, TwoFiftySixBit, "we1_24"},
	{we1_25, TwoFiftySixBit, "we1_25"},
	{we1_26, TwoFiftySixBit, "we1_26"},
	{we1_27, TwoFiftySixBit, "we1_27"},
	{we1_28, TwoFiftySixBit, "we1_28"},
	{we1_29, TwoFiftySixBit, "we1_29"},
	{we1_30, TwoFiftySixBit, "we1_30"},
	{we1_31, TwoFiftySixBit, "we1_31"}
};