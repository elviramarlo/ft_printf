/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 13:06:29 by elvmarti          #+#    #+#             */
/*   Updated: 2021/03/16 16:57:34 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put_flags1(t_printf *p, char *str)
{
	while (p->width > 0)
	{
		if (p->zero == 0)
			write(1, " ", 1);
		else
		{
			if (str[0] == '-')
			{
				str[0] = '0';
				write(1, "-", 1);
				p->width--;
				if (p->width > 0)
					p->n_return++;
			}
			if (p->width > 0)
				write(1, "0", 1);
		}
		p->width--;
		p->n_return++;
	}
}

static void	ft_put_flags2(t_printf *p)
{
	while (p->width > 0)
	{
		write(1, " ", 1);
		p->width--;
		p->n_return++;
	}
	p->minus = 0;
}

static void	ft_put_flag(t_printf *p, char *str)
{
	p->width = p->width - ft_strlen(str);
	if (p->minus == 0)
		ft_put_flags1(p, str);
	ft_putstr(str);
	if (p->minus == 1)
		ft_put_flags2(p);
	p->zero = 0;
	p->check = 0;
}

void		ft_print_num(va_list param, t_printf *p)
{
	int		num;
	char	*str;
	char	*aux;
	char	*str_zeros;

	num = va_arg(param, int);
	str = ft_itoa(num);
	if (str[0] == '0' && p->dot == 0 && p->check)
		str[0] = '\0';
	if (p->dot >= 0 && p->check == 1)
		p->zero = 0;
	if (p->dot > 0 && p->dot >= (int)ft_strlen(str))
	{
		p->dot = p->dot - ft_strlen(str);
		aux = ft_strdup(str);
		ft_null(str);
		str_zeros = ft_str_zeros(p, aux);
		str = ft_strjoin(str_zeros, aux);
		ft_null(str_zeros);
		ft_null(aux);
	}
	ft_put_flag(p, str);
	p->n_return = p->n_return + ft_strlen(str);
	ft_null(str);
}

char		*ft_str_zeros(t_printf *p, char *str)
{
	char	*cad_ceros;
	int		count;

	count = 0;
	if (!(cad_ceros = (char *)malloc(sizeof(char) * p->dot + 1)))
		return (NULL);
	if (str[0] == '-')
	{
		cad_ceros[count] = '-';
		str[0] = '0';
		count++;
	}
	while (p->dot > 0)
	{
		cad_ceros[count] = '0';
		count++;
		p->dot--;
	}
	cad_ceros[count] = '\0';
	return (cad_ceros);
}
