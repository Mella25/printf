#include "main.h"

/**
 * handle_print - Handles printing an argument based on its type and flags.
 * @fmt: Formatted string in which to print the arguments.
 * @list: List of arguments to be printed.
 * @ind: Pointer to the current index in the format string.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates active flags.
 * @width: Width specifier.
 * @precision: Precision specification.
 * @size: Size specifier.
 *
 * Return: The number of characters printed or -1 on error.
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
		 int flags, int width, int precision, int size)
{
	int i, printed_chars = -1;

	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};

	/* Check for flag characters */
	if (fmt[*ind] == '+')
	{
		flags |= F_PLUS;
		(*ind)++;
	}
	else if (fmt[*ind] == ' ')
	{
		flags |= F_SPACE;
		(*ind)++;
	}
	else if (fmt[*ind] == '#')
	{
		flags |= F_HASH;
		(*ind)++;
	}

	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
	}

	/* Rest of the code remains unchanged */
	/* ... */

	return (printed_chars);
}

