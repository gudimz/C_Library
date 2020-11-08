/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 01:23:32 by agigi             #+#    #+#             */
/*   Updated: 2020/11/09 01:48:49 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strcount(const char *str, char c)
{
	size_t	count;
	size_t	i;
	size_t len;

	count = 0;
	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] != c && ((str[i + 1] == c) || str[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static	int		ft_strlen_spl(const char *str, char c)
{
	int	len;

	len = 0;
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

static	char	**ft_memclear(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		count;
	int		start;
	int		i;
	char	**arr;

	if (!s)
		return (NULL);
	count = ft_strcount(s, c);
	if (!(arr = (char**)ft_calloc(count + 1, sizeof(char*))))
		return (NULL);
	start = 0;
	i = 0;
	while (i < count)
	{
		while (s[start] == c)
			start++;
		if (!(arr[i] = ft_substr(s, start, ft_strlen_spl(&s[start], c))))
			return (ft_memclear(arr));
		start += ft_strlen_spl(&s[start], c);
		i++;
	}
	return (arr);
}
