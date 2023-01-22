#include "main.h"
#include <stdarg.h>

/**
 * checkstring - checks for string
 * @string: characters
 * Return: number of char
 */
int checkstring(va_list string)
{
int strlength = 0;
char *str;
str = va_arg(string, char*);

if (str == NULL)
return (NULL);

while (str[strlength] != '\0')
strlength += _putchar(str[strlength]);

return (strlength);
}
