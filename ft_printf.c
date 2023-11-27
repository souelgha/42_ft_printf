/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 16:50:18 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/27 16:24:59 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* retourne la longueur de la string*/
/*cherche s il y a une % dans le string */
/* si % existe check du type  */
/* inserer le type dans la string*/

/*rechercher le format*/
/* utiliser ici va_arg(args, type)*/
/*
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
char	*ft_strchr(const char *str, int c)
{
	int		i;

	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}
void	ft_putnbr_fd(int n, int fd)
{
	char			tab[20];
	int				i;
	unsigned int	nb;

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -n;
	}
	else
		nb = n;
	while (nb > 9)
	{
		tab[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	tab[i] = nb % 10 + '0';
	while (i >= 0)
		ft_putchar_fd(tab[i--], fd);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}*/

static void ft_findformat(va_list args, char c)
{
	if (c == 'c')
		ft_putchar_fd((va_arg(args, int)), 1);
	else if (c == 's')
		ft_putstr_fd((va_arg(args, char *)), 1);
	else if (c == 'd')
		ft_putnbr_fd((va_arg(args, int)), 1);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	unsigned int	i;

	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			ft_findformat(args, (str[i + 1]));
			i = i +2;
		}
		ft_putchar_fd(str[i], 1);
		i++;
	}	
	va_end(args);
	return (i);	
}
int main(void)
{
	char	*str = "bonjour %s toi %c. %d.\n";
	int i;
	i = ft_printf(str, "Hello", '!', 5);
	printf("i=%d\n", i);
	printf("bonjour %s toi %c. %d. \n", "Hello", '!', 5);
	return (0);	
}