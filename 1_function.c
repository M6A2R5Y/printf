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
				case 'd': 
					{
						int d = va_arg(args, int);
						ret += print_int(d);
						break;
					}
				case 'i': 
					{
						int i = va_arg(args, int);
						ret += print_int(i);
						break;
					}
				default: 
					{
						/* Do nothing.*/
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
