/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:03:56 by elvmarti          #+#    #+#             */
/*   Updated: 2021/03/16 18:37:27 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_flags_c(t_printf *p, char c)
{
	if (p->minus == 0)
	{
		while (p->width > 0)
		{
			if (p->zero == 0)
				write(1, " ", 1);
			else
				write(1, "0", 1);
			p->width--;
			p->n_return++;
		}
	}
	write(1, &c, 1);
	p->n_return = p->n_return + 1;
	if (p->minus == 1)
	{
		while (p->width > 0)
		{
			write(1, " ", 1);
			p->width--;
			p->n_return++;
		}
		p->minus = 0;
	}
}

void		ft_print_c_p(const char *main_s, va_list param, t_printf *p)
{
	char c;

	if (main_s[p->i] == 'c')
		c = va_arg(param, int);
	if (main_s[p->i] == '%')
		c = '%';
	p->width = p->width - 1;
	ft_put_flags_c(p, c);
	p->check = 0;
	p->zero = 0;
	p->dot = 0;
}
