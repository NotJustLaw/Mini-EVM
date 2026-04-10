#include "main.h"

void	run_evm(t_evm *evm)
{
	uint8_t	opcode;
	t_op_func table[256];

	init_dispatch_table(table);
	while(evm->pc < evm->bc->size)
	{
		opcode = evm->bc->code[evm->pc];

		if (table[opcode] == NULL)
			break;
		table[opcode](evm);
	}
}

void	op_stop(t_evm *evm)
{
	evm->pc = evm->bc->size;
}

void	op_add(t_evm *evm)
{
	evm->pc += 1;
}

void	op_push1(t_evm *evm)
{
	evm->pc += 2;
}

void init_dispatch_table(t_op_func *table)
{
	int i = 0;
	while(i < 256)
		table[i++] = NULL;
	
	table[0x00] = op_stop;
	table[0x01] = op_add;
	table[0x60] = op_push1;
}