#include "main.h"
/**
 * find_width - Calculates the width for printing
 * @traverse: A pointer to const char.
 * @index: pointer to address of traverse index.
 * @args: list of arguments.
 * Return: width.
 */
int find_width(const char *traverse, int *index, va_list args)
{
	int i;
	int width = 0;

	i = *index + 1;
	while (traverse[i] != '\0')
	{
		if (traverse[i] >= 0 && traverse[i] <= 9)
		{
			width *= 10;
			width += traverse[i] - '0';
		}
		else if (traverse[i] == '*')
		{
			i++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
		i++;
	}
	*index = i - 1;
	return (width);
}
