/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 19:58:30 by agigi             #+#    #+#             */
/*   Updated: 2020/11/04 22:57:01 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_itoa(int n)
{
	char *res;
	char tmp;
	int size;
	int j;
	int i;

	size = 0;
	j = n;
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	if (!(res = (char *)malloc(size + 2)))
		return (NULL);
	i = 0;
	n = j;
	if (n < 0)
	{
		n = n * -1;
		// res[size] = '-';
		// size--;
	}
	while (size--)
	{
		res[i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	res[i++] = (n % 10) + '0';
	res[i] = '\0';
	j = 0;
	while (j < i / 2)
	{
		tmp = res[j];
		res[j] = res[i - 1 - j];
		res[i - 1 - j] = tmp;
		j++;
	}
	//создаешь временную строку и заполняешь ее через пут_нбр при этом передаешь положительно ечисло в лонге 
	//если число отр то стр джоин с минусом иначпе с пустой строкой при этом память выделяется в джойне 
	printf("%s", res);
	res[j] = '\0';
	if (n < 0)
		ft_strjoin("-", res);
	return (res);
}


int main(int argc, char const *argv[])
{
	
	printf("%s\n", ft_itoa(-12345));
	return 0;
}
