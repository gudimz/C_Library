/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:33:50 by agigi             #+#    #+#             */
/*   Updated: 2020/11/12 23:07:13 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!(sub = (char *)malloc(len + 1)))
		return (NULL);
	while (i < len)
	{
		sub[i] = str[start];
		i++;
		start++;
	}
	sub[i] = '\0';
	return (sub);
}
