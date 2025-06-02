#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int ft_printf(const char *fmt, ...);
int ft_strlen(char *str);
int put_char(char c);
int put_str(char *str);
int put_int(int num);
int put_hex(unsigned int num);


#endif
