#include "main.h"

/**
 * print_buffer - Prints the contents of the buffer if it's not empty
 * @buffer: The character buffer.
 * @buff_ind: Pointer to the buffer index.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
	}

	*buff_ind = 0;
}

/**
 * handle_unknown - Handles unknown conversion specifier
 * @format_char: The unknown format character.
 * @buffer: The character buffer.
 * @buff_ind: Pointer to the buffer index.
 *
 * Return: Number of characters added to the buffer.
 */
int handle_unknown(char format_char, char buffer[], int *buff_ind)
{
	buffer[(*buff_ind)++] = '%';  /* Add the '%' character to the buffer */
	buffer[(*buff_ind)++] = format_char;  /* Add the unknown character to the buffer */
	return (2);  /* Return the number of characters added to the buffer (2: '%' and the unknown character) */
}

/**
 * _printf - Custom printf function
 * @format: The format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
			}
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(format, &i);
			width = get_width(format, &i, list);
			precision = get_precision(format, &i, list);
			size = get_size(format, &i);
			if (format[i] == '\0')  /* Handle "%" character at the end of the format string */
			{
				print_buffer(buffer, &buff_ind);
				return (printed_chars);
			}
			if (format[i + 1] == '%')  /* Handle "%%" escape sequence */
			{
				buffer[buff_ind++] = '%';
				i++;
				printed_chars++;
			}
			else
			{
				int unknown_chars = handle_unknown(format[i + 1], buffer, &buff_ind);
				if (unknown_chars == 0)
				{
					++i;
					printed = handle_print(format, &i, list, buffer,
								   flags, width, precision, size);
					if (printed == -1)
					{
						va_end(list);
						return (-1);
					}
					printed_chars += printed;
				}
				else
				{
					printed_chars += unknown_chars;
				}
			}
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

