#include <stdio.h>

#define EIGHTBITREGS (16)
#define SIXTEENBITREGS (8)
#define THIRTYTWOBITREGS (8)
#define SIXTYFOURBITREGS (4)
#define ONETWOEIGHTBITREGS (2)
#define TWOFIVESIXBITREGS (2)

#define REGTYPES (6)

char repChars[REGTYPES] = {'e', 's', 't', 'f', 'o', 'w'};
char * regType[] = {
	"EightBit",
	"SixteenBit",
	"ThirtyTwoBit",
	"SixtyFourBit",
	"OneTwentyEightBit",
	"TwoFiftySixBit"};

char * repComment[] = {
	"(E)ight bit",
	"(S)ixteen bit",
	"(T)hirty-two bit",
	"Sixty-(F)our bit",
	"(O)ne Hundred Twenty-Six bit",
	"T(w)o Hundred Sixty-Four bit"
};

int regCounts[REGTYPES] = {
	EIGHTBITREGS,
	SIXTEENBITREGS,
	THIRTYTWOBITREGS,
	SIXTYFOURBITREGS,
	ONETWOEIGHTBITREGS,
	TWOFIVESIXBITREGS,
};

int main() {
	printf("typedef enum {\n");

	// For each type reg
	for(int i = 0; i < REGTYPES; i++) {
		// Comment specifying reg type
		printf("\t// %s registers\n", repComment[i]);

		// For each register of the type
		for(int j = 0; j < regCounts[i]; j++) {
			// print out enum
			printf("\t%c%d,\n", repChars[i], j);
		}

		// For each of the subregister types
		for(int j = i - 1; j >= 0; j--) {
			int subregCount = 1 << (i - j);
			printf("\n");
			printf("\t// %s subregister of \n", repComment[j]);
			printf("\t// %s register\n", repComment[i]);
			for(int k = 0; k < regCounts[i]; k++) {
				// for each subreg in the reg
				for(int l = 0; l < subregCount; l++) {
					printf("\t%c%c%d_%d,\n", repChars[i], repChars[j], k, l);
				}
			}
		}

		printf("\n");
	}

	printf("\tREGISTERCOUNT\n} RegisterNum;\n\n\n");

	printf("Register registers[] = {\n");

	for(int i = 0; i < REGTYPES; i++) {
		// For each register of the type
		for(int j = 0; j < regCounts[i]; j++) {
			// print out enum
			printf("\t{%c%d, %s, \"%c%d\"},\n",
				repChars[i],
				j,
				regType[i],
				repChars[i],
				j);
		}

		// For each of the subregister types
		for(int j = i - 1; j >= 0; j--) {
			int subregCount = 1 << (i - j);
			printf("\n");
			for(int k = 0; k < regCounts[i]; k++) {
				// for each subreg in the reg
				for(int l = 0; l < subregCount; l++) {
					printf("\t{%c%c%d_%d, %s, \"%c%c%d_%d\"},\n",
						repChars[i],
						repChars[j],
						k,
						l,
						regType[j],
						repChars[i],
						repChars[j],
						k,
						l);
				}
			}
		}
	}
	printf("};\n");
}