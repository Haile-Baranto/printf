#include "main.h"
/**
 * make_print - Prints out its to standard output based on thier types
 * @format: pointer to the format string to be printed
 * @args: pointer to va_list type arguemet.
 * @index: pointer to the index of formated string arquement if _printf.
 * @buffer: An array strings from which we print out to stdout.
 * @flags: determine  flags if it exists
 * @width: determine width if it exists.
 * @precision: determine Precision requirements
 * @size: determine Size descripters
 * Return: 1 or 2;
 */
int make_print(const char *format, int *index, va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, length = 0, printed_chars = -1;
	format_struct format_types[] = {
		{'c', printChar}, {'s', printString}, {'%', printPercent},
		{'i', printInt}, {'d', printInt}, {'b', printBinary},
		{'u', printUnsigned}, {'o', printOctal}, {'x', printHexa},
		{'X', printHexaUpper}, {'p', printPointer}, {'S', printNonPrintable},
		{'r', printReverse}, {'R', printRot13string}, {'\0', NULL}
	};
	for (i = 0; format_types[i].fmt != '\0'; i++)
		if (format[*index] == format_types[i].fmt)
			return (format_types[i].func(args, buffer, flags, width, precision, size));
	if (format_types[i].fmt == '\0')
	{
		if (format[*index] == '\0')
			return (-1);
		length += write(1, "%%", 1);
		if (format[*index - 1] == ' ')
			length += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (format[*index] != ' ' && format[*index] != '%')
				--(*index);
			if (format[*index] == ' ')
				--(*index);
			return (1);
		}
		length += write(1, &format[*index], 1);
		return (length);
	}
	return (printed_chars);
}
