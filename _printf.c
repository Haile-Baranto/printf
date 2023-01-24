#include "main.h"

void write_buffer(char *buffer, int *nbytes);

/**
 * _printf -  variadic function that prints formated string to
 * standard output
 * @format: pointer to constat char which is format specifier
 * Return: total length of charachters printed out
 */
int _printf(const char *format, ...)
{
	int j = 0, printed = 0, length = 0;
	int flags, width, precision, size;
	int buffer_index = 0;
	va_list args;
	char buffer[BUFF_SIZE];
	const char *traverse = format;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	while (traverse && traverse[j] != '\0')
	{
		if (traverse[j] != '%')
		{
			buffer[buffer_index++] = traverse[j];
			if (buffer_index == BUFF_SIZE)
				write_buffer(buffer, &buffer_index);
			length++;
		}
		else
		{
			write_buffer(buffer, &buffer_index);
			flags = find_flags(traverse, &j);
			width = find_width(traverse, &j, args);
			precision = find_precision(traverse, &j, args);
			size = find_size(traverse, &j);
			++j;
			printed = make_print(traverse, &j, args, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			length += printed;
		}
		j++;
	}

	write_buffer(buffer, &buffer_index);
	va_end(args);
	return (length);
}

/**
 * write_buffer - Prints the contents of the buffer if nbytes > 0;
 * @buffer: A pointer to a buffer where the data is stored
 * @nbytes: The number of bytes to write from the buffer
 */
void write_buffer(char *buffer, int *nbytes)
{
	if (*nbytes > 0)
		write(1, &buffer[0], *nbytes);

	*nbytes = 0;
}
