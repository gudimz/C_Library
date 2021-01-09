/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agigi <agigi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 18:06:56 by agigi             #+#    #+#             */
/*   Updated: 2020/12/27 16:23:11 by agigi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFTPRINTF_H
# define FT_LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct	s_params
{
	int			zero;
	int			minus;
	int			width;
	int			precision;
	char		type;
	int			sp_before;
	char		prefix[3];
	int			count_zero;
	char		*str;
	int			len;
	int			sp_after;

	int			error;
}				t_params;

int				ft_printf(const char *format, ...);
void			ft_printf_parser(const char **format, va_list *arg, \
								t_params *prm);
char			*ft_p_itoa_base(size_t n, size_t base, char *ref, \
								t_params *prm);
int				ft_printf_conver(t_params *prm, va_list *arg);
size_t			ft_printf_output(t_params *prm);
int				ft_intmin(int a, int b);
int				ft_intmax(int a, int b);

#endif
