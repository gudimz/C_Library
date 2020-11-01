/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:37:14 by agigi             #+#    #+#             */
/*   Updated: 2020/11/01 18:50:04 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mem;
	size_t	i;
	size_t	res_count;

	i = 0;
	res_count = count * size;
	mem = malloc(res_count);
	if (mem == NULL)
		return (NULL);
	while (res_count--)
	{
		mem[i] = 0;
		i++;
	}
	return (mem);
}
