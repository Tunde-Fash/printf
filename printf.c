#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...) {
    va_list args;
    const char *ptr;
    int count = 0;

    va_start(args, format);

    for (ptr = format; *ptr != '\0'; ptr++) {
        if (*ptr == '%') {
            ptr++;  /* Move to the next character after '%' */
            if (*ptr == 'c') {
                int character = va_arg(args, int);
                putchar(character);
                count++;
            } else if (*ptr == 's') {
                const char *str = va_arg(args, const char *);
                while (*str != '\0') {
                    putchar(*str);
                    str++;
                    count++;
                }
            } else if (*ptr == '%') {
                putchar('%');
                count++;
            }
        } else {
            putchar(*ptr);
            count++;
        }
    }

    va_end(args);

    return count;
}

int main() {
    int count = _printf("Hello, %c! This is a %s function.\n", 'W', "printf");
    printf("Total characters printed: %d\n", count);
    return 0;
}