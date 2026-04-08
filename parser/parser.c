#include "parser.h"

/// @brief Takes a hexadecimal string as an argument and parses it into raw bytes
/// @param hexString 
/// @return 
t_bytecode*	bytecode_parser(const char* hexString)
{
	int			i;
	int			j;
	int			str_length;
	int			nb_bytes;
	int			high_value;
	int			low_value;
	t_bytecode* bc;
	
	bc = malloc(sizeof(t_bytecode));
	if (!bc)
		return (NULL);

	str_length = strlen(hexString);
	if (str_length % 2 != 0) 		//A bytecode string must always be an even number
		return (free(bc), NULL);
	nb_bytes = str_length / 2; 		//2 Hexadecimal character = 1 byte

	bc->code = malloc(nb_bytes * sizeof(uint8_t));
	if (!bc->code)
		return (free(bc), NULL);
	bc->size = nb_bytes;

	i = 0;
	j = 0;
	while (i < nb_bytes)
    {
        high_value = get_hex_val(hexString[j++]);
        low_value = get_hex_val(hexString[j++]);

        if (high_value == -1 || low_value == -1)
            return (free(bc->code), free(bc), NULL);

        bc->code[i] = (high_value << 4) | low_value;
        i++;
    }

	return bc;
}

int get_hex_val(char c)
{
    int h = -1;
    const char *lwr = "0123456789abcdef";
    const char *upr = "0123456789ABCDEF";

    while (lwr[++h])
        if (c == lwr[h] || c == upr[h])
            return (h);
    return (-1);
}