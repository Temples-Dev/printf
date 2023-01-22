#include "main.h"
#include <stdarg.h>

/**
 * checkchar - returns char
 * @charr: characters to be printed
 * Return: print char
 */

int checkchar(va_list charr)
{
return (_putchar(va_arg(charr, int)));
}
