/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:28:39 by agigi             #+#    #+#             */
/*   Updated: 2020/12/27 16:19:33 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	ft_lenstr(size_t num, size_t base)
{
	size_t	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= base;
		i++;
	}
	return (i);
}

char			*ft_p_itoa_base(size_t n, size_t base, char *ref, t_params *prm)
{
	char	*str;
	size_t	size;

	size = ft_lenstr(n, base);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
	{
		prm->error = -1;
		return (NULL);
	}
	str[size] = '\0';
	while (size--)
	{
		str[size] = ref[n % base];
		n /= base;
	}
	return (str);
}
