/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:14:11 by agigi             #+#    #+#             */
/*   Updated: 2020/10/31 17:34:08 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_str;
	const unsigned char *src_str;

	dest_str = dest;
	src_str = src;
	if ((dest == src) || (n == 0))
		return (dest);
	while (n--)
		*dest_str++ = *src_str++;
	return (dest);
}
