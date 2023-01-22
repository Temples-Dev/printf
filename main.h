#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int checkchar(va_list charr);
int checkstring(va_list string);
int checkpercent(va_list percent);
/*To Do -Project prototypes*/




#endif
