#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS (1 << 0)
/* Minus flag */

#define F_PLUS (1 << 1)
/* Plus flag */

#define F_ZERO (1 << 2)
/* Zero flag */

#define F_HASH (1 << 3)
/* Hash flag */

#define F_SPACE (1 << 4)
/* Space flag */

/* SIZES */
#define S_LONG (1 << 1)
/* Long size */

#define S_SHORT (1 << 0)
/* Short size */

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	/* The format */
	int (*fn)(va_list, char[], int, int, int, int);
	/* The function associated */
};

/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

/* Printf function */
int _printf(const char *format, ...);
/* Handle print */
int handle_print(const char *fmt, int *i,
	va_list list, char buffer[], int flags, int width, int precision, int size);

/* Funtions to print chars and strings */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* Function to print chars */

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* Function to print strings */

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* Function to print percent */

/* Functions to print numbers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* Function to print integers */

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* Function to print binary */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* Function to print unsigned */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* Function to print octal */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* Function to print hexadecimal */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
/* Function to print hexadecimal uppercase */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size);
/* Print hexadecimal */

/* Function to print non-printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions to handle other specifiers */
int get_flags(const char *format, int *i);
/* Function to get flags */

int get_width(const char *format, int *i, va_list list);
/* Function to get width */

int get_precision(const char *format, int *i, va_list list);
/* Function to get precision */

int get_size(const char *format, int *i);
/* Function to get size */

/* Function to print string in reverse */
int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print a string in rot13 */
int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Width handler for writing characters */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);

/* Width handler for writing numbers */
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);

/* Write number with padding */
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);

/* Write memory address with padding */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

/* Write unsigned number with padding */
int write_unsgnd(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size);

/* Check if character is printable */
int is_printable(char);

/* Append hexadecimal code */
int append_hexa_code(char, char[], int);

/* Check if character is a digit */
int is_digit(char);

/* Convert number with size */
long int convert_size_number(long int num, int size);

/* Convert unsigned number with size */
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */

