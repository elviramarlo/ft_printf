/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 18:41:12 by elvmarti          #+#    #+#             */
/*   Updated: 2021/03/16 18:10:24 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_flags_s(t_printf *p, char *str)
{
	p->width = p->width - ft_strlen(str);
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
	ft_putstr(str);
	p->n_return = p->n_return + ft_strlen(str);
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

void		ft_print_string(va_list param, t_printf *p)
{
	char	*str;

	str = va_arg(param, char *);
	if (!str)
		str = "(null)";
	if (p->dot > 0 || (p->dot == 0 && p->check == 1))
		str = ft_substr(str, 0, p->dot);
	ft_put_flags_s(p, str);
	if (p->dot > 0 || (p->dot == 0 && p->check == 1))
		ft_null(str);
	p->check = 0;
	p->zero = 0;
	p->dot = 0;
}
