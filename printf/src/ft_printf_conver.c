/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:14:08 by agigi             #+#    #+#             */
/*   Updated: 2020/12/27 16:53:24 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_conver_space(t_params *prm)
{
	if (prm->precision >= 0 && prm->precision > prm->len && \
	prm->type != 's' && prm->type != 'c' && prm->type != '%')
		prm->count_zero = prm->precision - prm->len;
	if (prm->minus)
	{
		prm->sp_after = prm->width - prm->len - ft_strlen(prm->prefix)\
		- prm->count_zero;
		if (prm->sp_after < 0)
			prm->sp_after = 0;
	}
	else if (prm->zero && prm->len != 0 && prm->precision < 0)
	{
		prm->count_zero = prm->width - prm->len - ft_strlen(prm->prefix);
		if (prm->count_zero < 0)
			prm->count_zero = 0;
	}
	else
	{
		prm->sp_before = prm->width - prm->len - ft_strlen(prm->prefix) \
		- prm->count_zero;
		if (prm->sp_before < 0)
			prm->sp_before = 0;
	}
	return (prm->error);
}

static int	ft_conver_char(t_params *prm, va_list *arg)
{
	char *str;

	if (prm->type == 'c' || prm->type == '%')
	{
		if (!(prm->str = malloc(1)))
			return ((prm->error = -1));
		prm->len = 1;
		if (prm->type == 'c')
			prm->str[0] = (char)va_arg(*arg, int);
		else
			prm->str[0] = '%';
	}
	else if (prm->type == 's')
	{
		str = va_arg(*arg, char *);
		if (!str)
			str = "(null)";
		if (!(prm->str = ft_substr(str, 0, prm->precision)))
			return ((prm->error = -1));
		prm->len = ft_strlen(prm->str);
	}
	return (prm->error);
}

static int	ft_conver_int(t_params *prm, va_list *arg)
{
	long long int n;

	n = (long long int)va_arg(*arg, int);
	if (n < 0)
	{
		n *= -1;
		prm->prefix[0] = '-';
	}
	prm->str = ft_p_itoa_base((size_t)n, 10, "0123456789", prm);
	prm->len += ft_strlen(prm->str);
	return (prm->error);
}

static int	ft_conver_uint(t_params *prm, va_list *arg)
{
	size_t n;

	if (prm->type == 'p')
		n = (size_t)va_arg(*arg, void *);
	else
		n = va_arg(*arg, int);
	if (prm->type == 'p')
	{
		prm->prefix[0] = '0';
		prm->prefix[1] = 'x';
	}
	if (prm->type == 'u')
		prm->str = ft_p_itoa_base((unsigned int)n, 10, "0123456789", prm);
	else if (prm->type == 'X')
		prm->str = ft_p_itoa_base((unsigned int)n, 16, "0123456789ABCDEF", prm);
	else if (prm->type == 'p')
		prm->str = ft_p_itoa_base(n, 16, "0123456789abcdef", prm);
	else
		prm->str = ft_p_itoa_base((unsigned int)n, 16, "0123456789abcdef", prm);
	prm->len = ft_strlen(prm->str);
	return (prm->error);
}

int			ft_printf_conver(t_params *prm, va_list *arg)
{
	if (prm->type == 's' || prm->type == 'c' || prm->type == '%')
		ft_conver_char(prm, arg);
	else if ((prm->type == 'd' || prm->type == 'i'))
		ft_conver_int(prm, arg);
	else
		ft_conver_uint(prm, arg);
	if (prm->str[0] == '0' && prm->len == 1 && prm->type != 's' && \
	prm->type != 'c' && prm->type != '%' && prm->precision == 0)
	{
		prm->len = 0;
		if (ft_strlen(prm->prefix) <= (size_t)prm->width)
		{
			if (prm->minus)
				prm->sp_after = prm->width - ft_strlen(prm->prefix);
			else
				prm->sp_before = prm->width - ft_strlen(prm->prefix);
		}
	}
	else
		ft_conver_space(prm);
	return (prm->error);
}
