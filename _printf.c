#include "main.h"

/* Function prototypes */
void print_buffer(char buffer[], int *buff_ind);
void print_humorous_message(void); /*New function for %r format*/

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
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

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
 * print_humorous_message - Prints a humorous message for %r format specifier.
 * You can customize the message as you like.
 */
void print_humorous_message(void)
{
    char message[] = "Whoa! You found a mysterious format specifier (%r). "
                     "I'm just a simple printf function, not a magician! 😄";
    write(1, message, sizeof(message) - 1);
}
