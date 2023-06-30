#include "main.h"

/**
 * binary_to_uint -  a function that converts a
 * binary number to an unsigned int.
 * @b: pointer to a string of 0 and 1 chars
 * Return: the converted number
 * or 0 if there is one or more chars in the string b that is not 0 or 1
 * b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i = 0;

	if (!b)
		return (0);
	while (*b)
	{
		if (*b != '1' && *b != '0')
			return (0);

		i = (*b++ - '0') + i * 2;
	}
	return (i);
}
