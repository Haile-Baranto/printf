#include "main.h"
/**
 * find_precision - Calculates the precision for printing
 * @format: pointer to the formatted string
 * @index: pointer to the address of format string
 * @args: arguments list.
 * Return: Precision.
 */
int find_precision(const char *format, int *index, va_list args)
{
	int i = *index + 1;
	int precision = -1;

	if (format[i] != '.')
		return (precision);
	precision = 0;

	for (i += 1; format[i] != '\0'; i++)
	{
		if (0 <= format[i] && 9 >= format[i])
		{
			precision *= 10;
			precision += format[i] - '0';
		}
		else if (format[i] == '*')
		{
			i++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*index = i - 1;

	return (precision);
}
