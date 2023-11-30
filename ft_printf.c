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
# include <stdarg.h>

/* retourne la longueur de la string*/
/*cherche s il y a une % dans le string */
/* si % existe check du type  */
/* inserer le type dans la string*/

/*rechercher le format*/
/* utiliser ici va_arg(args, type)*/

int	ft_putstr(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
int	ft_putnbr(int n)
{
	char			tab[20];
	int				i;
	unsigned int	nb;
	int				len;

	i = 0;
	if (n < 0)
	{
		ft_putchar('-');
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
	len = i;
	while (i >= 0)
		ft_putchar(tab[i--]);
	return (len);
}

int	ft_findformat(va_list args, const char type)
{
	int len;

	len =  0;
	if (type == 's')
		len = ft_putstr((va_arg(args, char *)));
	else if (type == 'c')
		len = ft_putchar((va_arg(args, int)));	
	else if (type == 'd')
		len = ft_putnbr((va_arg(args, int)));		
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list args;
	int	i;
	int len;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{	
			//printf("bf_format[%d + 1] =%c \n\n", i, format[i + 1] );
			len += ft_findformat(args, format[i + 1]);
			//printf("af_format[%d + 1] =%s \n\n", i, va_arg(args, char *));
			i++;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}


int main(void)
{
	//const char	*str = "bonjour %s toi %s. %s.\n";
	//int i;
	//printf("bonjour %c toi %s. %c.\n", 'j', "hello", 'g');
	ft_printf("bonjour %d %s toi.\n", 5, "er");
	//printf("i=%d\n", i);
	
	return (0);	
}