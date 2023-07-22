#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
	/*check if the format argument is NULL*/
	if (format == NULL)
		return (-1);

	va_list args; /*handle the variable arguments*/
	int printed_chars = 0; /*track the number of characters printed*/
	int buffer_index = 0; /*track the current index in the buffer array*/
	char buffer[BUFF_SIZE]; /*temporarily store characters b4 printing*/
	int flags, width, precision, size, printed; /*store info about the format specifiers*/

	va_start(args, format);

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFF_SIZE)
			{
				write(1, buffer, buffer_index);
				printed_chars += buffer_index;
				buffer_index = 0;
			}
			printed_chars++;
		}
		else
		{
			if (buffer_index > 0)
			{
				write(1, buffer, buffer_index);
				printed_chars += buffer_index;
				buffer_index = 0;
			}

			flags = get_flags(format, &i);
			width = get_width(format, &i, args);
			precision = get_precision(format, &i, args);
			size = get_size(format, &i);
			i++;
		/*returns number of characters printed by the format specifier*/
			printed = handle_print(format, &i, args, buffer,
					       flags, width, precision, size);

			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	if (buffer_index > 0)
	{
		write(1, buffer, buffer_index);
		printed_chars += buffer_index;
	}

	va_end(args); /*called to clean up the args list*/

	return (printed_chars);
}
