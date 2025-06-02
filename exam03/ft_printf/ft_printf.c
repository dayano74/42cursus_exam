#include "ft_printf.h"

int put_int(int num)
{
	int cnt = 0;
	char dex_set[10] ="0123456789";
	long n;

	n = num;
	if (n < 0)
	{
		cnt += put_char('-');
		n = -n;
	}
	if (n >= 10)
		cnt += put_int(n / 10);
	cnt += put_char(dex_set[n % 10]);
	return (cnt);
}

int put_hex(unsigned int num)
{
	int cnt = 0;
	char dex_set[16] ="0123456789abcdef";
	long long n;

	n = num;
	if (n >= 16)
		cnt += put_hex(n / 16);
	cnt += put_char(dex_set[n % 16]);
	return (cnt);
}

int format_handler(const char *fmt, va_list args)
{
	int cnt = 0;

	fmt++;
	if (*fmt == 's')
		cnt = put_str(va_arg(args, char *));
	if (*fmt == 'd')
		cnt = put_int(va_arg(args, int));
	if (*fmt == 'x')
		cnt = put_hex(va_arg(args, unsigned int));
	return (cnt);
}

int ft_printf(const char *fmt, ...)
{
	int cnt = 0;
	int ret = 0;
	va_list args;

	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			ret = format_handler(fmt, args);
			if (ret == -1)
				return (printf("invalid use\n"), 1);
			cnt += ret;
			fmt ++;
		}
		else
			cnt += put_char(*fmt);
		fmt++;
	}
	va_end(args);
	return (cnt);
}
