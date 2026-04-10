// Created by NotJustLaw
#include "main.h"

int main()
{
	int			final_result;
	t_evm		*evm;
	t_bytecode	*bytecode;

	bytecode = bytecode_parser("600560010100");
	if (bytecode == NULL)
	{
		printf("[Error] Error while parsing the Hex String");
		exit(EXIT_FAILURE);
	}
	evm = malloc(sizeof(t_evm));
	if (!evm)
	{
		free(bytecode->code);
		free(bytecode);
		printf("[Error] Error while allocating EVM");
		exit(EXIT_FAILURE);
	}
	evm->stack = malloc(sizeof(t_stack));
	if (!evm->stack)
	{
		free(bytecode->code);
		free(bytecode);
   		free(evm);
		printf("[Error] Error while allocating EVM");
		exit(EXIT_FAILURE);
	}

	evm->bc = bytecode;
	evm->pc = 0;
	evm->stack->stack_pointer = 0;
	run_evm(evm);

	final_result = pop(evm->stack);
    
    printf("Bytecode executed successfully!\n");
    printf("The EVM calculated: %d\n", final_result);

    free(evm->stack);
    free(evm->bc->code);
    free(evm->bc);
    free(evm);
	return (0);
}