/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:06:52 by elvmarti          #+#    #+#             */
/*   Updated: 2021/03/16 15:49:53 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *main_s, ...)
{
	va_list		param;
	t_printf	p;

	ft_bzero(&p, sizeof(t_printf));
	va_start(param, main_s);
	while (main_s[p.i] != '\0')
	{
		if (main_s[p.i] == '%')
		{
			p.i++;
			if (main_s[p.i] != 'c' || main_s[p.i] != 's' || main_s[p.i] != 'p'
			|| main_s[p.i] != 'd' || main_s[p.i] != 'i' || main_s[p.i] != 'u'
			|| main_s[p.i] != 'x' || main_s[p.i] != 'X' || main_s[p.i] != '%')
				ft_flags(main_s, param, &p);
			if (!main_s[p.i])
				return (0);
			ft_param(main_s, param, &p);
		}
		else if (main_s[p.i] != '%')
			p.n_return += write(1, &main_s[p.i], 1);
		p.i++;
	}
	va_end(param);
	return (p.n_return);
}

void	ft_param(const char *main_s, va_list param, t_printf *p)
{
	if (main_s[p->i] == 'c' || main_s[p->i] == '%')
		ft_print_c_p(main_s, param, p);
	else if (main_s[p->i] == 's')
		ft_print_string(param, p);
	else if (main_s[p->i] == 'p')
		ft_print_punt(param, p);
	else if (main_s[p->i] == 'd' || main_s[p->i] == 'i')
		ft_print_num(param, p);
	else if (main_s[p->i] == 'u')
		ft_print_unsigned(param, p);
	else if (main_s[p->i] == 'x' || main_s[p->i] == 'X')
		ft_print_hex(main_s, param, p);
}
