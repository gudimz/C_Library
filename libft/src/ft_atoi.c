/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:38:20 by agigi             #+#    #+#             */
/*   Updated: 2021/06/25 17:58:24 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_sign(char str)
{
	if (str == '-')
		return (-1);
	return (1);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			res;
	long long	res_check;
	int			sign;

	i = 0;
	res = 0;
	res_check = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	sign = ft_check_sign(str[i]);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = res * 10 + (str[i] - '0');
		i++;
		if (sign * res > sign * res_check && sign == -1)
			return (0);
		if (res < res_check && sign == 1)
			return (-1);
		res_check = res;
	}
	return (sign * res);
}
