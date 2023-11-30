/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:56:55 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/25 11:18:57 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putstr(char *s)
{
	//int	i;

	if (!s)
		return (0) ;	
	return(	write(1, s, ft_strlen(s)));
}
/*
int main(void)
{
	int i;

	i = ft_putstr("hello de lu \n");
	printf("i=%d", i);
	return (0);
}*/

