#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	va_start(args, format);
	while (*format)
		{
			if (*format == '%')
		        format++;
			/* Handle the conversion specifiers*/
			switch (*format)
			{
				case 'c':
					{
						int character = va_arg(args, int);
						putchar(character);
						count++;
						break;
					}
				case 's':
					{
						char str = va_arg(args, char *);
						fputs(str, stdout);
						count += strlen(str);
						break;
					}
				case '%':
					{
						putchar('%');
						count++;
						break;
					}
				default:
					{
						putchar('%');
						putchar(*format);
						count += 2;
						break;
					}
			}
			else
			{
				putchar(*format);
				count++;
			}
			format++;
		}
	va_end(args);
	return count;
}
