#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define NOTUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* for flag assignments (e.g -, +, so on) */
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

/* size modifiers long and short for numbers */
#define LONG_SIZE 2
#define SHORT_SIZE 1

/**
 * struct format - Struct
 *
 * @fmt: The format.
 * @func: A pointer to a function.
 */
struct format
{
	char fmt;
	int (*func)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct format format_struct - Struct
 *
 * @format: The format.
 * @format_struct: structer of type struct format.
 */
typedef struct format format_struct;

int _printf(const char *format, ...);
int make_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/
/* Funcion to print memory address */
int printPointer(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int find_flags(const char *format, int *i);
int find_width(const char *format, int *i, va_list list);
int find_precision(const char *format, int *i, va_list list);
int find_size(const char *format, int *i);

/*Function to print string in reverse*/
int printReverse(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/*Function to print a string in rot 13*/
int printRot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Funtions to print chars and strings */
int printChar(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int printString(va_list types, char buffer[],
		int flags, int width, int precision, int size);
int printPercent(va_list types, char buffer[],
		int flags, int width, int precision, int size);

/* Functions to print numbers */
int printInt(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printBinary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printUnsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printOctal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printHexa(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printHexaUpper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function to print non printable characters */
int printNonPrintable(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILITIES ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* HEADER_FILE */
