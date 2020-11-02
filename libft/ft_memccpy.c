/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:18:20 by agigi             #+#    #+#             */
/*   Updated: 2020/11/03 00:25:21 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dst;
	const unsigned char *str;

	i = 0;
	dst = dest;
	str = src;
	if ((dest == 0) && (src == 0))
		return (0);
	while (i < n)
	{
		dst[i] = str[i];
		if (str[i] == (unsigned char)c)
			return (&dst[i + 1]);
		i++;
	}
	return (0);
}
