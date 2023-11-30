/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 17:11:50 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/12 18:20:21 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_base(char c)
{
	char 	*base_X;
	char	*base_x;

	base_x = "0123456789abcdef";
	base_X = "0123456789ABCDEF";
	if (c == 'x')
		return (base_x);
	else
		return (base_X);
}

int	ft_putnbr_hexa(unsigned long int n, char c)
{
	
	char	tab[200];
	int		i;
	int	len;
	char	*base;

	i = 0;
	if (n == 0)
		return (write(1, "0", 1));
	base = ft_base(c);
	while (n > 0)
	{
		tab[i++] = base[n % 16];
		n = n / 16;
	}
	len = i;
	while (--i >= 0)
		ft_putchar(tab[i]);
	return(len);
}

/*generer les negatifs*/
/*
#include <limits.h>
int	main(void)
{
	unsigned long int	n = 0;
	int len;
	len = ft_putnbr_hexa(n, 'X');
	printf("\nlen=%d", len);
	return (0);
}*/
