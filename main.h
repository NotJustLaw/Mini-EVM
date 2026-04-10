#ifndef MAIN_H
# define MAIN_H

#include "parser/parser.h"

typedef struct	s_evm {
    t_bytecode  *bc;       // The ROM
    size_t      pc;        // Program Counter (Current index in the bytecode)
    // t_stack  *stack;    // TODO
    // size_t   gas;       // TODO
}				t_evm;

typedef void (*t_op_func)(t_evm *evm); //Blue print for the dispatch table

#endif