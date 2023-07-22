#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS (1 << 0) /* Minus flag */
#define F_PLUS (1 << 1) /* Plus flag */
#define F_ZERO (1 << 2) /* Zero flag */
#define F_HASH (1 << 3) /* Hash flag */
#define F_SPACE (1 << 4) /* Space flag */

/* SIZES */
#define S_LONG (1 << 1) /* Long size */
#define S_SHORT (1 << 0) /* Short size */

typedef struct fmt
{
	
	char fmt; /* The format */

	/* The function associated */
	int (*fn)(va_list, char[], int, int, int, int);
} fmt_t;

int _printf(const char *format, ...); /* Printf function */
int handle_print(const char *fmt, int *i,

/*Handle Print*/
va_list list, char buffer[], int flags, int width, int precision, int size);


/* Function to print chars */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print strings */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print percent */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print integers */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print binary */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print insugned */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/*Functiom to print octal*/
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print hexadecimal */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print hexadecimal uppercase */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);


/*Print hexadecimal */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size);

/* Function to print non-printable characters */
int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function to print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int get_flags(const char *format, int *i); /* Function to get flags */

/* Function to get width */
int get_width(const char *format, int *i, va_list list);

/* Function to get precision */
int get_precision(const char *format, int *i, va_list list);

int get_size(const char *format, int *i); /* Function to get size */

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
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c); /* Write number with padding */


/* Write memory address with padding */
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

/* Write unsigned number with padding */
int write_unsgnd(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size);

int is_printable(char); /* Check if character is printable */
int append_hexa_code(char, char[], int); /* Append hexadecimal code */
int is_digit(char); /* Check if character is a digit */


/* Convert number with size */
long int convert_size_number(long int num, int size);



/* Convert unsigned number with size */
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
