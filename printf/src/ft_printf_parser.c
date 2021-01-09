/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:53:48 by agigi             #+#    #+#             */
/*   Updated: 2020/12/27 16:24:19 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_parser_flags(const char **format, t_params *prm)
{
	if (**format == '-')
		prm->minus = 1;
	else
		prm->zero = 1;
}

static void	ft_parser_width(const char **format, t_params *prm, va_list *arg)
{
	if (**format == '*')
	{
		prm->width = va_arg(*arg, int);
	}
	else
		prm->width = ft_atoi(*format);
	if (prm->width < 0)
	{
		prm->width *= -1;
		prm->minus = 1;
	}
}

static void	ft_parser_precision(const char **format, t_params *prm, \
			va_list *arg)
{
	if (**format == '.')
	{
		prm->precision = 0;
		(*format)++;
		if (**format == '*')
			prm->precision = va_arg(*arg, int);
		else
			prm->precision = ft_atoi(*format);
	}
}

static int	ft_parser_type(const char **format)
{
	if (**format == 'c' || **format == 's' || **format == 'p' ||\
		**format == 'd' || **format == 'i' || **format == 'u' ||\
		**format == 'x' || **format == 'X' || **format == '%')
		return (1);
	else
		return (0);
}

void		ft_printf_parser(const char **format, va_list *arg, t_params *prm)
{
	ft_bzero(prm, sizeof(t_params));
	prm->precision = -1;
	(*format)++;
	while (**format == '-' || **format == '0')
	{
		ft_parser_flags(format, prm);
		(*format)++;
	}
	if (**format == '*' || (**format > 47 && **format < 58))
		ft_parser_width(format, prm, arg);
	while ((**format > 47 && **format < 58) || (**format == '*'))
		(*format)++;
	if (**format == '.')
		ft_parser_precision(format, prm, arg);
	while ((**format > 47 && **format < 58) || **format == '*' ||\
			**format == '.')
		(*format)++;
	if (ft_parser_type(format))
	{
		prm->type = **format;
		(*format)++;
	}
}
