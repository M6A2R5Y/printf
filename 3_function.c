#include "main.h"
#include <stdio.h>
#include <stdarg.h>
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
	int ret = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'u':
					{
						unsigned int u = va_args(args, unsigned int);
						ret += printf_unsigned(u);
						break
					}
				case 'o':
					{
						unsigned int o = va_args(args, usigned int);
					        ret += print_octal(o);
						break;
					}
				case 'x':
					{
						unsigned int x = va_args(args, unsigned int);
						ret += print_hex(x);
						break;
					}
				case 'X':
					{
						unsigned int X = va_args(args, unsigned int);
						ret += print_hex_upper(X);
						break;
					}
				default:
					{
						/* do nothing*/
						break;
					}
			}
		}
		else
		{
			ret += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return ret;
}
