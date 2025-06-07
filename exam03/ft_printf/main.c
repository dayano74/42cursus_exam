#include "ft_printf.h"

int main(void)
{
	int ret;

	ret = ft_printf("hello\n");
	printf("ret = %d\n", ret);
	ret = printf("hello\n");
	printf("ret = %d\n", ret);


	ret = ft_printf("adsf %s\n", "hello");
	printf("ret = %d\n", ret);
	ret = printf("adsf %s\n", "hello");
	printf("ret = %d\n", ret);

	ret = ft_printf("%d\n", 123);
	printf("ret = %d\n", ret);
	ret = printf("%d\n", 123);
	printf("ret = %d\n", ret);

	ret = ft_printf("%d\n", -456);
	printf("ret = %d\n", ret);
	ret = printf("%d\n", -456);
	printf("ret = %d\n", ret);

	ret = ft_printf("%d\n", 2147483647);
	printf("ret = %d\n", ret);
	ret = printf("%d\n", 2147483647);
	printf("ret = %d\n", ret);

	ret = ft_printf("%d\n", -2147483648);
	printf("ret = %d\n", ret);
	ret = printf("%d\n", (int)-2147483648);
	printf("ret = %d\n", ret);

	ret = ft_printf("%x\n", 255);
	printf("ret = %d\n", ret);
	ret = printf("%x\n", 255);
	// printf("ret = %d\n", ret);

	ret = ft_printf("%s\n", NULL);
	printf("ret = %d\n", ret);
	ret = printf("%s\n", (char *)NULL);
	printf("ret = %d\n", ret);
	return (0);
}
