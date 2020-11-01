/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:48:28 by agigi             #+#    #+#             */
/*   Updated: 2020/10/31 17:35:34 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < n)
		i++;
	while (src[i] && (i + j + 1) < n)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < n)
		dest[i + j] = '\0';
	return (ft_strlen(src) + i);
}
