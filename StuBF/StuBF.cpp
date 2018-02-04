/*
StuBF: a small Brainf*ck interpreter
According to the language specification at http://www.muppetlabs.com/~breadbox/bf/
*/

#include "stdafx.h"

using namespace std;

const int MEM_SIZE = 30000;

typedef struct {
	char memory[MEM_SIZE] = {};
	int pc = 0;
	int mc = 0;
} Interpreter;

// Gets the matching closing parenthesis for the current position
int getMatchingClosingJumpBracket(const Interpreter *i, const string *program) {
	int nOpeningBrackets = 1;
	int currentPosition = i->pc;
	do {
		currentPosition++;
		if (currentPosition >= MEM_SIZE) {
			return -1; // We only look forward
		}
		if ((*program)[currentPosition] == ']') {
			nOpeningBrackets--;
		}
		else if ((*program)[currentPosition] == '[') {
			nOpeningBrackets++;
		}
	} while (nOpeningBrackets != 0);
	return currentPosition;
}

// Gets the matching opening parenthesis for the current position
int getMatchingOpeningJumpBracket(const Interpreter *i, const string *program) {
	int nClosingBrackets = 1;
	int currentPosition = i->pc;
	do {
		currentPosition--;
		if (currentPosition < 0) {
			return -1; // We only look backwards
		}
		if ((*program)[currentPosition] == '[') {
			nClosingBrackets--;
		}
		else if ((*program)[currentPosition] == ']') {
			nClosingBrackets++;
		}
	} while (nClosingBrackets != 0);
	return currentPosition;
}

// Reads a whole text file into a string
string readWholeFile(string filePath) {
	ifstream t(filePath);
	stringstream buffer;
	buffer << t.rdbuf();
	return buffer.str();
}

int main(int argc, char *argv[]) {

	Interpreter machine;

	if (argc != 2) {
		cout << "Usage: StuBF.exe program.bf" << endl;
		return -1;
	}

	string program = readWholeFile(argv[1]);

	int nextPC; // For jumps
	char currentCommand;
	int maxPC = program.length();

	while (machine.pc != maxPC) {
		currentCommand = program[machine.pc];
		switch (currentCommand) {
		case '>':
			machine.mc++;
			if (machine.mc >= MEM_SIZE) {
				cout << "ERROR at command " << machine.pc << ": Memory index out of bounds when executing '>'.";
				return -1;
			}
			break;
		case '<':
			machine.mc--;
			if (machine.mc < 0) {
				cout << "ERROR at command " << machine.pc << ": Memory index out of bounds when executing '<'.";
				return -1;
			}
			break;
		case '+':
			machine.memory[machine.mc]++;
			break;
		case '-':
			machine.memory[machine.mc]--;
			break;
		case '.':
			cout << (char)machine.memory[machine.mc];
			break;
		case ',':
			cin >> machine.memory[machine.mc];
			break;
		case '[':
			if (machine.memory[machine.mc] == 0) {
				nextPC = getMatchingClosingJumpBracket(&machine, &program);
				if (nextPC == -1) {
					cout << "ERROR at command " << machine.pc << ": Unmatched opening jump bracket.";
					return -1;
				}
				else {
					machine.pc = nextPC;
				}
			}
			break;
		case ']':
			if (machine.memory[machine.mc] != 0) {
				nextPC = getMatchingOpeningJumpBracket(&machine, &program);
				if (nextPC == -1) {
					cout << "ERROR at command " << machine.pc << ": Unmatched closing jump bracket.";
					return -1;
				}
				else {
					machine.pc = nextPC;
				}
			}
			break;
		}
		machine.pc++;
	}

	return 0;
}

