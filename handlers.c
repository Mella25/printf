#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;

    print_result("Length:", len, len2);
    print_result("Negative:", -762534, -762534);
    print_result("Unsigned:", ui, ui);
    print_result("Unsigned octal:", ui, ui);
    print_result("Unsigned hexadecimal:", ui, ui);
    print_result("Character:", 'H', 'H');
    print_result("String:", "I am a string !", "I am a string !");
    print_result("Address:", addr, addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    print_result("Len:", len, len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}

void print_result(const char *format, int value1, int value2)
{
    _printf("%s:[%d, %d]\n", format, value1, value2);
    printf("%s:[%d, %d]\n", format, value1, value2);
}
