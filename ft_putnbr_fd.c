#include "libft.h"

void    ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483648)
        ft_putstr_fd("-2147483648", fd);
    else if (n < 0)
    {
        ft_putchar_fd('-', fd);
        ft_putnbr_fd(-n, fd);
    }
    else if (n >= 10)
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putchar_fd((n % 10) + '0', fd);
    }
    else
        ft_putchar_fd(n + '0', fd);
}
#include <fcntl.h>   // Для open()
#include <unistd.h>
int main()
{
    int fd = open("number.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
        return (1);

         // Тесты вывода чисел в файл
    ft_putnbr_fd(0, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(42, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(-12345, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(2147483647, fd);
    ft_putchar_fd('\n', fd);
    ft_putnbr_fd(-2147483648, fd);
    ft_putchar_fd('\n', fd);

    close(fd); // Закрыть файл

    // Повторим то же самое, но теперь в стандартный вывод (терминал)
    ft_putnbr_fd(0, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(42, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(-12345, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(2147483647, 1);
    ft_putchar_fd('\n', 1);
    ft_putnbr_fd(-2147483648, 1);
    ft_putchar_fd('\n', 1);

    return (0);
}