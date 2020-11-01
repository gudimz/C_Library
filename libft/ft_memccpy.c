/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 22:18:20 by agigi             #+#    #+#             */
/*   Updated: 2020/10/31 18:52:42 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dest_str;
	const unsigned char *src_str;

	i = 0;
	dest_str = dest;
	src_str = src;
	if ((dest == 0) && (src == 0))
		return (0);
	while (i < n)
	{
		dest_str[i] = src_str[i];
		if (src_str[i] == (unsigned char)c)
			return (&dest_str[i + 1]);
		i++;
	}
	return (0);
}
