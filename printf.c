#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _print_char - Print a character
 * @c: The character to print
 *
 * Return: The number of characters printed.
 */
int _print_char(char c)
{
    putchar(c);
    return 1;
}

/**
 * _print_str - Print a string
 * @str: The string to print
 *
 * Return: The number of characters printed.
 */
int _print_str(char *str)
{
    int count = 0;

    if (str)
    {
        while (*str)
        {
            _print_char(*str);
            str++;
            count++;
        }
    }
    else
    {
        count += _print_str("(null)");
    }

    return count;
}

/**
 * _print_percent - Print a percent sign
 *
 * Return: The number of characters printed.
 */
int _print_percent(void)
{
    return _print_char('%');
}

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (format && *format)
    {
        if (*format != '%')
        {
            count += _print_char(*format);
        }
        else
        {
            format++;
            switch (*format)
            {
                case 'c':
                    count += _print_char(va_arg(args, int));
                    break;
                case 's':
                    count += _print_str(va_arg(args, char *));
                    break;
                case '%':
                    count += _print_percent();
                    break;
                default:
                    count += _print_percent();
                    count += _print_char(*format);
                    break;
            }
        }
        format++;
    }

    va_end(args);

    return count;
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
    int len;

    len = _printf("Hello, %s! You have %d dollars.\n", "Alice", 1000);
    _printf("Length: %d\n", len);

    return (0);
}

