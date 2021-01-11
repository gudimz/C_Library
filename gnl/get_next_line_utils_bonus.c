/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:00:14 by agigi             #+#    #+#             */
/*   Updated: 2021/01/12 01:12:36 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int ch)
{
	size_t	i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (s[i] != ch)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return (&s[i]);
}

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	count;

	count = ft_strlen(s1);
	if (!(tmp = (char *)malloc(count + 1)))
		return (NULL);
	count = 0;
	while (s1[count])
	{
		tmp[count] = s1[count];
		count++;
	}
	tmp[count] = '\0';
	return (tmp);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc(i + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	if (src == 0)
		return (0);
	if (dest != src)
	{
		while (src[i] != '\0' && n > 1)
		{
			dest[i] = src[i];
			i++;
			n--;
		}
		if (n > 0)
			dest[i] = '\0';
	}
	return (ft_strlen(src));
}
