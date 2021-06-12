/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:13:51 by elvmarti          #+#    #+#             */
/*   Updated: 2021/03/16 16:34:19 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_flags_x(t_printf *p, char *str_hex)
{
	p->width = p->width - ft_strlen(str_hex);
	if (p->minus == 0)
	{
		while (p->width > 0)
		{
			if (p->zero == 0)
				write(1, " ", 1);
			else
				write(1, "0", 1);
			p->n_return++;
			p->width--;
		}
	}
	ft_putstr(str_hex);
	p->n_return = p->n_return + ft_strlen(str_hex);
	if (p->minus == 1)
	{
		while (p->width > 0)
		{
			write(1, " ", 1);
			p->n_return++;
			p->width--;
		}
		p->minus = 0;
	}
}

void		ft_print_hex(const char *main_str, va_list param, t_printf *p)
{
	unsigned int	num;
	char			*str_hex;
	char			*aux;
	char			*str_zeros;

	num = va_arg(param, unsigned int);
	str_hex = ft_conv_hex(num, main_str, p);
	if (str_hex[0] == '0' && p->dot == 0 && p->check)
		str_hex[0] = '\0';
	if (p->dot >= 0 && p->check == 1)
		p->zero = 0;
	if (p->dot > 0 && p->dot > (int)ft_strlen(str_hex))
	{
		p->dot = p->dot - ft_strlen(str_hex);
		aux = ft_strdup(str_hex);
		ft_null(str_hex);
		str_zeros = ft_str_zeros(p, aux);
		str_hex = ft_strjoin(str_zeros, aux);
		ft_null(str_zeros);
		ft_null(aux);
	}
	ft_put_flags_x(p, str_hex);
	p->check = 0;
	p->zero = 0;
	ft_null(str_hex);
}
