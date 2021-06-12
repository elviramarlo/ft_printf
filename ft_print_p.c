/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:15:44 by elvmarti          #+#    #+#             */
/*   Updated: 2021/03/16 16:59:26 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_flags_p1(char *str, t_printf *p)
{
	if (p->zero == 1)
		ft_putstr("0x");
	while (p->width > 0)
	{
		if (p->zero == 1)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		p->width--;
		p->n_return++;
	}
	if (p->zero == 0)
		ft_putstr("0x");
	ft_putstr(str);
	p->n_return = p->n_return + ft_strlen(str) + 2;
}

static void	ft_put_flags_p2(char *str, t_printf *p)
{
	ft_putstr("0x");
	ft_putstr(str);
	p->n_return = p->n_return + ft_strlen(str) + 2;
	while (p->width > 0)
	{
		write(1, " ", 1);
		p->width--;
		p->n_return++;
	}
	p->minus = 0;
}

static void	ft_put_flag(char *str_dir, t_printf *p)
{
	p->width = p->width - ft_strlen(str_dir) - 2;
	if (p->minus == 0)
		ft_put_flags_p1(str_dir, p);
	if (p->minus == 1)
		ft_put_flags_p2(str_dir, p);
	p->check = 0;
	p->zero = 0;
}

void		ft_print_punt(va_list param, t_printf *p)
{
	unsigned long int	num;
	char				*str_dir;
	char				*aux;
	char				*str_zeros;

	num = va_arg(param, unsigned long int);
	str_dir = ft_conv_p(num);
	if (str_dir[0] == '0' && p->dot == 0 && p->check)
		str_dir[0] = '\0';
	if (p->dot >= 0 && p->check == 1)
		p->zero = 0;
	if (p->dot > 0 && p->dot > (int)ft_strlen(str_dir))
	{
		p->dot = p->dot - ft_strlen(str_dir);
		aux = ft_strdup(str_dir);
		ft_null(str_dir);
		str_zeros = ft_str_zeros(p, aux);
		str_dir = ft_strjoin(str_zeros, aux);
		ft_null(str_zeros);
		ft_null(aux);
	}
	ft_put_flag(str_dir, p);
	ft_null(str_dir);
}
