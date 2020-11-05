/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:58:30 by agigi             #+#    #+#             */
/*   Updated: 2020/11/06 00:37:29 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_lenstr(long num)
{
	int i;
	
	i = 0;
	if (num < 9)
		num *= -1;
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static char *ft_nbr_itoa(int num)
{
	char *str;
	long nb;
	int size;
	
	nb = num;
	size = ft_lenstr(nb);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size + 1] = '\0';
	if (nb < 0)
		nb *= -1;
	while (size--)
	{
		str[size] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (str);
}

char *ft_itoa(int n)
{
	char *res;
	
	res = ft_nbr_itoa(n);
	if (n < 0)
		res = (ft_strjoin("-", res));
	return (res);
}
