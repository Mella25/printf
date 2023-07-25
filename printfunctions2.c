#include "main.h"
<<<<<<< HEAD
#include <stdarg.h>
/**
 * write_pointer - Prints the value of a pointer variable.
 * @buffer: Buffer array to handle print.
 * @ind: Index in buffer.
 * @length: Length of the output.
 * @width: Width of the output.
 * @flags: Calculates flags.
 * @padd: Padding character.
 * @extra_c: Extra character.
 * Return: Number of characters printed.
 */
int write_pointer(char buffer[], int ind, int length, int width,
	int flags, char padd, char extra_c)
=======

/****************** PRINT POINTER ******************/
int print_pointer(va_list args, char buffer[],
                  int flags, int width, int precision, int size)
>>>>>>> 8f37152 (Final product)
{
    char padding_char = 0, padding = ' ';
    int index = BUFF_SIZE - 2, length = 2, start_padding = 1;
    unsigned long address_num;
    char map_to[] = "0123456789abcdef";
    void *address = va_arg(args, void *);

    UNUSED(width);
    UNUSED(size);

    if (address == NULL)
        return (write(1, "(nil)", 5));

    buffer[BUFF_SIZE - 1] = '\0';
    UNUSED(precision);

    address_num = (unsigned long)address;

    while (address_num > 0)
    {
        buffer[index--] = map_to[address_num % 16];
        address_num /= 16;
        length++;
    }

    if ((flags & F_ZERO) && !(flags & F_MINUS))
        padding = '0';
    if (flags & F_PLUS)
        padding_char = '+', length++;
    else if (flags & F_SPACE)
        padding_char = ' ', length++;

    index++;

    return (write_pointer(buffer, index, length,
                          width, flags, padding, padding_char, start_padding));
}

<<<<<<< HEAD
/**
 * print_non_printable - Prints ASCII codes in hex of non-printable characters.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specification.
 * Return: Number of characters printed.
 */
int print_non_printable(va_list types, char buffer[],
			int flags, int width, int precision, int size)
=======
/************************* PRINT NON PRINTABLE *************************/
int print_non_printable(va_list args, char buffer[],
                        int flags, int width, int precision, int size)
>>>>>>> 8f37152 (Final product)
{
    int i = 0, offset = 0;
    char *str = va_arg(args, char *);

    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (str == NULL)
        return (write(1, "(null)", 6));

    while (str[i] != '\0')
    {
        if (is_printable(str[i]))
            buffer[i + offset] = str[i];
        else
            offset += append_hexa_code(str[i], buffer, i + offset);

        i++;
    }

    buffer[i + offset] = '\0';

    return (write(1, buffer, i + offset));
}

<<<<<<< HEAD
/**
 * print_reverse - Prints a string in reverse.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specification.
 * Return: Numbers of characters printed.
 */
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
=======
/************************* PRINT REVERSE *************************/
int print_reverse(va_list args, char buffer[],
                  int flags, int width, int precision, int size)
>>>>>>> 8f37152 (Final product)
{
    char *str;
    int i, count = 0;

    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(size);

    str = va_arg(args, char *);

<<<<<<< HEAD
	if (str == NULL)
	{
		UNUSED(precision);
		str = ")Null(";
	}

	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];
		write(1, &z, 1);

		count++;
	}
	return (count);
}

/**
 * print_rot13string - Print a string in rot13.
 * @types: List of arguments.
 * @buffer: Buffer array to handle print.
 * @flags: Calculates flags.
 * @width: Width.
 * @precision: Precision specification.
 * @size: Size specification.
 * Return: Numbers of characters printed.
 */
int print_rot13string(va_list types, char buffer[], int flags,
		      int width, int precision, int size)
=======
    if (str == NULL)
    {
        UNUSED(precision);
        str = ")Null(";
    }

    for (i = 0; str[i]; i++)
        ;

    for (i = i - 1; i >= 0; i--)
    {
        char ch = str[i];
        write(1, &ch, 1);
        count++;
    }

    return (count);
}

/************************* PRINT A STRING IN ROT13 *************************/
int print_rot13string(va_list args, char buffer[],
                      int flags, int width, int precision, int size)
>>>>>>> 8f37152 (Final product)
{
    char ch;
    char *str;
    unsigned int i, j;
    int count = 0;
    char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    str = va_arg(args, char *);

<<<<<<< HEAD
	if (str == NULL)
		str = "(AHYY)";

	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}

		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}

	return (count);
=======
    UNUSED(buffer);
    UNUSED(flags);
    UNUSED(width);
    UNUSED(precision);
    UNUSED(size);

    if (str == NULL)
        str = "(AHYY)";

    for (i = 0; str[i]; i++)
    {
        for (j = 0; in[j]; j++)
        {
            if (in[j] == str[i])
            {
                ch = out[j];
                write(1, &ch, 1);
                count++;
                break;
            }
        }

        if (!in[j])
        {
            ch = str[i];
            write(1, &ch, 1);
            count++;
        }
    }

    return (count);
>>>>>>> 8f37152 (Final product)
}
