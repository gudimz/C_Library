/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:55:02 by agigi             #+#    #+#             */
/*   Updated: 2020/11/12 22:59:59 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	size_t	count;

	count = ft_strlen(s1);
	tmp = (char *)malloc(count + 1);
	if (tmp == NULL)
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
