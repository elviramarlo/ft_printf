/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 13:15:52 by elvmarti          #+#    #+#             */
/*   Updated: 2021/03/16 16:35:57 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_flags_u(t_printf *p, char *str_num)
{
	p->width = p->width - ft_strlen(str_num);
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
	ft_putstr(str_num);
	p->n_return = p->n_return + ft_strlen(str_num);
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

void		ft_print_unsigned(va_list param, t_printf *p)
{
	unsigned int	num;
	char			*str_num;
	char			*aux;
	char			*str_zeros;

	num = va_arg(param, unsigned int);
	str_num = ft_itoa(num);
	if (str_num[0] == '0' && p->dot == 0 && p->check)
		str_num[0] = '\0';
	if (p->dot >= 0 && p->check == 1)
		p->zero = 0;
	if (p->dot > 0 && p->dot > (int)ft_strlen(str_num))
	{
		p->dot = p->dot - ft_strlen(str_num);
		aux = ft_strdup(str_num);
		ft_null(str_num);
		str_zeros = ft_str_zeros(p, aux);
		str_num = ft_strjoin(str_zeros, aux);
		ft_null(aux);
		ft_null(str_zeros);
	}
	ft_put_flags_u(p, str_num);
	p->check = 0;
	p->zero = 0;
	ft_null(str_num);
}
