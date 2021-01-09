/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 00:45:47 by agigi             #+#    #+#             */
/*   Updated: 2020/12/27 16:24:08 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_printf_output(t_params *prm)
{
	size_t count;

	count = 0;
	while (prm->sp_before--)
		count += write(1, " ", 1);
	count += write(1, prm->prefix, ft_strlen(prm->prefix));
	while (prm->count_zero--)
	{
		count += write(1, "0", 1);
	}
	count += write(1, (prm->str), prm->len);
	while (prm->sp_after--)
		count += write(1, " ", 1);
	return (count);
}
