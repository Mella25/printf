#include "main.h"

/**
 * print_char - Print a single character to the buffer
 * @buffer: Buffer to store the characters
 * @buff_ind: Index to add the character to the buffer
 * @c: Character to be printed
 * Return: None
 */
void print_char(char buffer[], int *buff_ind, char c)
{
	buffer[*buff_ind] = c;
	(*buff_ind)++;

	if (*buff_ind == BUFF_SIZE - 1)
	{
		print_buffer(buffer, buff_ind);
	}
}

/**
 * _printf - Printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	va_list list;
	va_start(list, format);

	int printed_chars = 0;
	char buffer[BUFF_SIZE];
	int buff_ind = 0;

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			print_char(buffer, &buff_ind, format[i]);
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			i++;

			if (format[i] == '\0')
			{
				print_buffer(buffer, &buff_ind);
				return (-1);
			}

			if (format[i] == '%')
			{
				print_char(buffer, &buff_ind, '%');
				printed_chars++;
			}
			else if (format[i] == 'c')
			{
				char c = va_arg(list, int);
				print_char(buffer, &buff_ind, c);
				printed_chars++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(list, char*);
				if (str == NULL)
					str = "(null)";
				while (*str)
				{
					print_char(buffer, &buff_ind, *str);
					str++;
					printed_chars++;
				}
			}
		}
	}

	print_buffer(buffer, &buff_ind);
	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length
 * Return: None
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind);
		*buff_ind = 0;
	}
}

