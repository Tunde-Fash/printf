#include "main.h"  // Include the custom header file

#include <stdio.h>
#include <stdarg.h>

/** Print a string
 * @str: The string to print
 * Return: The number of characters printed.
 */
int _print_str(char *str) {
    int count = 0;

    if (str) {  // Check if the string is not NULL
        while (*str) {  // Iterate through the characters of the string
            putchar(*str);
            str++;
            count++;
        }
    } else {
        count += _print_str("(null)");  // Handle the case when the string is NULL by printing "(null)"
    }

    return count;
}

/** Custom printf function
 * @format: The format string
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...) {
    va_list args;
    int count = 0;

    va_start(args, format);  // Start variable argument processing

    while (format && *format) {  // Iterate through the format string
        if (*format != '%') {  // Check if the character is not '%'
            putchar(*format);
            count++;
        } else {
            format++;  // Move to the next character after '%'
            switch (*format) {  // Check the conversion specifier
                case 'c':  // Handle character specifier
                    putchar(va_arg(args, int));
                    count++;
                    break;
                case 's':  // Handle string specifier
                    count += _print_str(va_arg(args, char *));
                    break;
                case '%':  // Handle the '%' literal
                    putchar('%');
                    count++;
                    break;
                default:  // Handle unknown specifier
                    putchar('%');
                    putchar(*format);
                    count += 2;
                    break;
            }
        }
        format++;
    }

    va_end(args);  // End variable argument processing

    return count;
}
