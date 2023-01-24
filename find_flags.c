#include "main.h"
/**
 * find_flags - finds existing flags
 * @traverse: Ponter to formatted string
 * @index: pointer to current address of traverse.
 * Return: Flags:
 */

int find_flags(const char *traverse, int *index)
{
	int i, j;
	int flags = 0;
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_VALUE[] = {FLAG_MINUS, FLAG_PLUS, FLAG_ZERO,
		FLAG_HASH, FLAG_SPACE, 0};

	for (i = *index + 1; traverse[i] != '\0'; i++)
	{
		for (j = 0; FLAGS_CHAR[j] != '\0'; j++)
		{
			if (traverse[i] == FLAGS_CHAR[j])
			{
				flags |= FLAGS_VALUE[j];
				break;
			}
		}
		if (FLAGS_CHAR[j] == 0)
			break;
	}

	*index = i - 1;

	return (flags);
}

