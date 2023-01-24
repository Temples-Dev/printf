#include "main.h"
#include <stdio.h>

/**
 * _printf - custom printf that produces
 *          output according to a format
 * @format: character string
 *
 * Return: number of characters printed excluding
 * null bytes
 */

int _printf(const char *format, ...)
{
int bytes_printed = 0;
va_list args;

va_start(args, format);

if (!format || (format[0] == '%' && !format[1]))
return (-1);

for (const char *p = format; *p; p++)
{
if (*p != '%')
{
bytes_printed += _putchar(*p);
continue;
}
p++;

if (!*p)
break;

int width = 0, precision = -1;
char flags = 0;
int length_modifier = 0;

if (*p == '0')
{
flags |= FLAG_ZERO;
p++;
}

while (*p >= '0' && *p <= '9')
{
width = width * 10 + (*p - '0');
p++;
}

if (*p == '.')
{
p++;
precision = 0;
while (*p >= '0' && *p <= '9')
{
precision = precision * 10 + (*p - '0');
p++;
}
}

if (*p == 'h' || *p == 'l' || *p == 'L')
length_modifier = *p++;

switch (*p)
{
case 'd':
case 'i': {
int value = va_arg(args, int);
bytes_printed += print_int(value,
flags, width, precision, length_modifier);
break;
}
case 'c': {
int value = va_arg(args, int);
bytes_printed += print_char(value);
break;
}
case 's': {
char *value = va_arg(args, char *);
bytes_printed += print_string(value,
flags, width, precision);
break;
}
case '%': {
bytes_printed += _putchar('%');
break;
}
default: {
bytes_printed += _putchar(*p);
break;
}
}
}

_putchar(BUF_FLUSH);
va_end(args);
return (bytes_printed);
}
