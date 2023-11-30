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

int	ft_putnbr(int n)
{
	char			tab[20];
	int				i;
	unsigned int	nb;
	int				len;
	int				sign;

	i = 0;
	sign = 0;
	if (n < 0)
	{
		ft_putchar('-');
		nb = -n;
		sign = 1;
	}
	else
		nb = n;
	while (nb != 0)
	{
		tab[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	len = i;
	i = i- 1;
	while (i >= 0)
		ft_putchar(tab[i--]);
	return (len + sign);
}
/*
#include <limits.h>
int	main(void)
{
	int	n = -27483648;
	int len;
	
	len = ft_putnbr(n);
	printf("\n len=%d", len);
	return (0);
}*/
