#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

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
    return(write(1, str, ft_strlen(str)));
}

int put_d(int num)
{
    int cnt = 0;
    (void)num;
    return (cnt);
}

int put_x(int num)
{
    int cnt = 0;
    (void)num;
    return (cnt);
}

int format_handler(const char *fmt, va_list args)
{
    int cnt = 0;
    (void)args;

    if (*(++fmt) == 's')
    {
        cnt = put_str(va_arg(args, char *));
    }
    if (*(++fmt) == 'd')
    {
        // TODO : implement put_d()
        cnt = put_d(va_arg(args, int));
    }
    if (*(++fmt) == 'x')
    {
        // TODO : implement put_x()
        cnt = put_x(va_arg(args, int));
    }
    return (cnt);
}

// char *str = va_arg(args, char *);
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

int main(void)
{
    int ret;
    // printf("%d\n", ft_strlen("asdf"));
    // ret = ft_printf("hello\n");
    // ret = ft_printf("adsf %s\n", "hello");
    // printf("ret = %d\n", ret);
    // ft_printf("%s\n", "hello");
    // ft_printf("Hello", "World!");
    ret = printf("%d\n", 2147483647);
    printf("ret = %d\n", ret);
    return (0);
}