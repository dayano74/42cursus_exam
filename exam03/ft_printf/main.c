#include "ft_printf.h"

int main(void)
{
	int ret;
	// printf("%d\n", ft_strlen("asdf"));
	// ret = ft_printf("hello\n");
	// ret = ft_printf("adsf %s\n", "hello");
	// printf("ret = %d\n", ret);
	// ft_printf("%s\n", "hello");
	// ft_printf("Hello", "World!");
	// ret = ft_printf("%d\n", 2147483647);
	// printf("ret = %d\n", ret);
	// ret = ft_printf("%d\n", -2147483648);
	// printf("ret = %d\n", ret);
	ret = ft_printf("%d\n", 10);
	printf("ret = %d\n", ret);
	ret = ft_printf("%x\n", 10);
	printf("ret = %d\n", ret);
	ret = printf("%x\n", 10);
	printf("ret = %d\n", ret);
	return (0);
}
