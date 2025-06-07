#include "ft_printf.h"

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return(i);
}

int put_char(char c)
{
	return (write(1, &c, 1));
}

int put_str(char *str)
{
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	return (write(1, str, ft_strlen(str)));
}
