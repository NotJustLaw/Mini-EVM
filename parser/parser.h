#ifndef PARSER_H
# define PARSER_H

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct	s_bytecode
{
	uint8_t	*code;
	size_t	size;
}		t_bytecode;

t_bytecode*	bytecode_parser(const char* hexString);

//Helpers
int			get_hex_val(char c);

#endif