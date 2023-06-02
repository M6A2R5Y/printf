#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/**
 * struct format_specifier - Struct to store format specifiers and their corresponding functions.
 * @specifier: The format specifier.
 * @func: The function pointer to handle the format specifier.
 */
typedef struct format_specifier
{
	char *specifier;
	int (*func)(char *, va_list);
}
format_specifier_t;
int _printf(const char *format, ...);
int print_char(char *buffer, va_list args);
int print_string(char *buffer, va_list args);
int print_integer(char *buffer, va_list args);
int print_unsigned_integer(char *buffer, va_list args);
int print_octal(char *buffer, va_list args);
int print_hexadecimal(char *buffer, va_list args);
int print_hexadecimal_upper(char *buffer, va_list args);
int print_binary(char *buffer, va_list args);
int print_reverse(char *buffer, va_list args);
int print_rot13(char *buffer, va_list args);

static const format_specifier_t format_specifiers[] = 
{
	{ "%c", print_char },
	{ "%s", print_string },
	{ "%d", print_integer },
	{ "%u", print_unsigned_integer },
	{ "%o", print_octal },
	{ "%x", print_hexadecimal },
	{ "%X", print_hexadecimal_upper },
	{ "%b", print_binary },
	{ "%r", print_reverse },
	{ "%R", print_rot13 },
};
#endif
