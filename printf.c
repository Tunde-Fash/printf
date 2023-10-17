#include "main.h"
#include <stdio.h>
#include <stdarg.h>

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
	putchar(*str);
	str++;
	count++;
	}
	}
	else
	{
	count += _print_str("(null)");
	}

	return (count);
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
	putchar(*format);
	count++;
	}
	else
	{
		format++;
		switch (*format)
		{
		case 'c':
		putchar(va_arg(args, int));
		count++;
		break;
		case 's':
		count += _print_str(va_arg(args, char *));
		break;
		case '%':
		putchar('%');
		count++;
		break;
		default:
		putchar('%');
		putchar(*format);
		count += 2;
		break;
	}
	}
	format++;
	}

	va_end(args);
	return (count);
}

