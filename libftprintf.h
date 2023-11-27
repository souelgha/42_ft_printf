#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H


# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>


void	ft_putchar_fd(char c, int fd);
char	*ft_strchr(const char *str, int searchedChar);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *str);
void	ft_putnbr_fd(int n, int fd);

#endif
