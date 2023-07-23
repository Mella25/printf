#include "main.h"

/**
 * get_width - Calculates the width for printing
 * @format: The format string.
 * @i: Pointer to the current index in the format string.
 * @list: The va_list of arguments.
 *
 * Return: The width value.
 *
 * The do-while loop ensures that the loop will terminate even if the format
 *  string does not contain any digits. The break statement is used to break out
 *  of the loop when a non-digit character is encountered.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int width = 0;

	do {
		if (is_digit(format[curr_i]))
		{
			width = width * 10 + (format[curr_i] - '0');
			curr_i++;
		}
		else if (format[curr_i] == '*')
		{
			width = va_arg(list, int);
			curr_i++;
			break;
		}
		else
			break;
	} while (format[curr_i] != '\0');

	*i = curr_i - 1;

	return (width);
}
