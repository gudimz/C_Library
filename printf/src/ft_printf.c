/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:30:51 by agigi             #+#    #+#             */
/*   Updated: 2020/12/26 22:32:16 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(const char *format, ...)
{
	size_t		count;
	va_list		arg;
	t_params	prm;

	if (!format)
		return (-1);
	va_start(arg, format);
	count = 0;
	while (*format && prm.error != -1)
	{
		if (*format != '%')
			count += write(1, format++, 1);
		else
		{
			ft_printf_parser(&format, &arg, &prm);
			if (prm.type)
				ft_printf_conver(&prm, &arg);
			count += ft_printf_output(&prm);
			free(prm.str);
		}
	}
	va_end(arg);
	if (prm.error == -1)
		return (-1);
	return (count);
}
