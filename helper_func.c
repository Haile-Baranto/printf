#include "main.h"

/************************* print char *************************/

/**
 * printChar - Prints a char to stdout
 * @types: List a of arguments type va_list
 * @buffer: Buffer array from where we print out
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision requirment
 * @size: Size modifier
 * Return: Number of chars printed out to stdout oput
 */
int printChar(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* print string *************************/
/**
 * print_string - Prints a string of charachters
 * @types: List a of arguments of type va_list
 * @buffer: Buffer array from where we print out t stdout
 * @flags:  determine active flags
 * @width: determine  width specification.
 * @precision: Precision requirment
 * @size: Size modifier
 * Return: Number of chars printed
 */
int printString(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	NOTUSED(buffer);
	NOTUSED(flags);
	NOTUSED(width);
	NOTUSED(precision);
	NOTUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & FLAG_MINUS)
		{
			write(1, &str[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign(%)
 * @types: List a of arguments of type va_list
 * @buffer: Buffer array from where we print out t stdout
 * @flags:  determine active flags
 * @width: determine  width specification.
 * @precision: Precision requirment
 * @size: Size modifier
 * Return: Number of chars printed
 */
int printPercent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	NOTUSED(types);
	NOTUSED(buffer);
	NOTUSED(flags);
	NOTUSED(width);
	NOTUSED(precision);
	NOTUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print Integer type
 * @types: List a of arguments of type va_list
 * @buffer: Buffer array from where we print out t stdout
 * @flags:  determine active flags
 * @width: determine  width specification.
 * @precision: Precision requirment
 * @size: Size modifier
 * Return: Number of chars printed
 */
int printInt(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 *@types: List a of arguments of type va_list
 * @buffer: Buffer array from where we print out t stdout
 * @flags:  determine active flags
 * @width: determine  width specification.
 * @precision: Precision requirment
 * @size: Size modifier
 * Return: Number of chars printed
 */

int printBinary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	NOTUSED(buffer);
	NOTUSED(flags);
	NOTUSED(width);
	NOTUSED(precision);
	NOTUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
