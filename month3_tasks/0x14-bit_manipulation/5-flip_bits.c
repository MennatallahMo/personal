#include "main.h"

/**
 * flip_bits - a function that returns the number of bits
 * you would need to flip to get from one number to another.
 * @n: first no
 * @m: 2nd no
 * Return: bits no
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int sum = 0;
	unsigned long int flip = n ^ m;

	while (flip)
	{
		if (flip & 1ul)
			sum++;
		sum = sum >> 1;
	}
	return (sum);
}

