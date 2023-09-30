#include <stdio.h>
#include "main.h"
#include <string.h>

/**
 *binary_to_unint - function that converts binary to unsigned int
 * @b: pointer to binary string
 * Return: decimal number, 0 or NULL
 */

unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int dec_val;
	dec_val = 0;

	if (!b)
		return (0);
	for (i = 0; b[i] !='\0'; i++)
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
	}

	for(i = 0; b[i] != '\0'; i++)
	{
		dec_val <<= 1;
		if (b[i] == '1')
			dec_val += 1;
	}
	return dec_val;
}
