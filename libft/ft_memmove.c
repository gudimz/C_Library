/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:55:47 by agigi             #+#    #+#             */
/*   Updated: 2020/10/31 17:34:45 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_str;
	const unsigned char *src_str;

	dest_str = dest;
	src_str = src;
	if (dest_str > src_str)
	{
		while (n--)
			dest_str[n] = src_str[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
