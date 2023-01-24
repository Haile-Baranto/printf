#include "main.h"
/**
 * find_size - determines size to cast the arguments passed
 * @traverse: pointer to the formatted string
 * @index: List of arguments to be printed.
 * Return: Precision.
 */
int find_size(const char *traverse, int *index)
{
	int i = *index + 1;
	int size = 0;

	if (traverse[i] == 'l')
		size = LONG_SIZE;
	else if (traverse[i] == 'h')
		size = SHORT_SIZE;
	if (size == 0)
		*index = i - 1;
	else
		*index = i;

	return (size);
}
