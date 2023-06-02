#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	va_start(args, format);
	int ret = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'b':
					{
						unsigned int b = va_args(args, unsigned int);
						ret += printf_binary(b);
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
