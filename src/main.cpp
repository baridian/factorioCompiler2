#include "Ref.h"

typedef enum BlockType { switchBlock, ifElseBlock, whileBlock} BlockType;

typedef enum ElementType { literalType, operatorType, variableType } ElementType;

struct ExpressionElement
{
	Ref<ExpressionElement> leftChild;
	Ref<ExpressionElement> rightChild;
	Ref<ExpressionElement> parent;
	ElementType type;
	union data
	{
		int literal;
		char operatorValue[2];
		Ref<char> variableName;
	};
};

typedef struct Block Block;

struct Statement
{
	int numExpressions;
	Ref<ExpressionElement> roots;
	int numExitPoints;
	Ref<Block> exitPoints;
};

typedef struct Function Function;

struct Block
{
	Ref<Function> parentFunction;
	BlockType type;
	Statement comparator;
	Statement ifSuccess;
	Statement ifFailure;
};

typedef struct Program Program;

struct Function
{
	int numVariables;
	Ref<Ref<char>> variableDeclarations;
	Block entryPoint;
	Ref<Program> parentProgram;
};

struct Program
{
	int numSupportingFunctions;
	Ref<Function> supportingFunctions;
	Function main;
};

int countFunctions(FILE *source)
{

}

Program frontEnd(FILE *source)
{
	Program toReturn;

}

Ref<char> backEnd(Program abstractSyntaxTree)
{

}

int main2(int argc, char *argv[])
{
	FILE *sourceFile;
	if(argc > 2)
	{
		fprintf(stderr, "ERROR: must declare source file location\n");
		exit(1);
	}
	else
	{
		sourceFile = fopen(argv[1],"r");
		printf("%s",backEnd(frontEnd(sourceFile)));

	}
	return 0;
}