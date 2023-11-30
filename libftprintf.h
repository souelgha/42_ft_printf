#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H


# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
//# include "../libft/libft.h"


void	ft_putchar_fd(char c, int fd);
int		ft_putchar(char c);
char	*ft_strchr(const char *str, int searchedChar);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *str);
int		ft_putnbr(int n);
int		ft_printf_new(const char *format, ...);
//int		ft_putnbr_hexa(unsigned long int n, const char *base);
int		ft_putnbr_hexa(unsigned long int n, char c);

#endif
