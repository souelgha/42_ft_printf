/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonouelg <sonouelg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:58:37 by sonouelg          #+#    #+#             */
/*   Updated: 2023/11/25 10:52:22 by sonouelg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*newstr;
	unsigned int	i;
	unsigned int	j;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	newstr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (newstr == NULL)
		return (0);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		newstr[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
		newstr[i++] = s2[j++];
	newstr[i] = '\0';
	return (newstr);
}
/*
#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	char const	*s1 = "";
	char const	*s2 = "to";
	char	*newstr;

	newstr = ft_strjoin(s1, s2);
	printf("newstr=%s\n", newstr);
	free(newstr);
	return(0);
}*/
