/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 17:48:20 by elvmarti          #+#    #+#             */
/*   Updated: 2021/03/17 17:05:19 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_minus(const char *main_s, t_printf *p)
{
	p->minus = 1;
	p->i++;
	while (main_s[p->i] == '0')
		p->i++;
}

static void	ft_zero(t_printf *p)
{
	p->zero = 1;
	p->i++;
}

static void	ft_width(const char *main_s, t_printf *p, va_list param)
{
	char *aux;

	aux = 0;
	if (main_s[p->i] == '*' && main_s[p->i - 1] != '.')
	{
		p->width = va_arg(param, int);
		if (p->width < 0)
		{
			p->minus = 1;
			p->width = p->width * -1;
		}
		p->i++;
	}
	if (main_s[p->i] > '0' && main_s[p->i] <= '9')
	{
		aux = ft_strdup_falso(&main_s[p->i]);
		p->width = ft_atoi_falso(aux);
		ft_null(aux);
		while (main_s[p->i] >= '0' && main_s[p->i] <= '9')
			p->i++;
	}
}

static void	ft_dot(const char *main_s, t_printf *p, va_list param)
{
	char *aux;

	p->check = 0;
	if (main_s[p->i] == '.')
	{
		p->i++;
		if (main_s[p->i] == '*')
		{
			p->dot = va_arg(param, int);
			p->i++;
		}
		if (main_s[p->i] >= '0' && main_s[p->i] <= '9')
		{
			aux = ft_strdup_falso(&main_s[p->i]);
			p->dot = ft_atoi_falso(aux);
			ft_null(aux);
			while (main_s[p->i] >= '0' && main_s[p->i] <= '9')
				p->i++;
		}
		if (p->dot <= 0)
			p->check = 1;
	}
}

void		ft_flags(const char *main_s, va_list param, t_printf *p)
{
	while (main_s[p->i] != 'c' && main_s[p->i] != 's' &&
		main_s[p->i] != 'p' && main_s[p->i] != 'd' &&
		main_s[p->i] != 'i' && main_s[p->i] != 'u' &&
		main_s[p->i] != 'x' && main_s[p->i] != 'X' &&
		main_s[p->i] != '%' && main_s[p->i + 1] != '\0')
	{
		while (main_s[p->i] == '0')
			ft_zero(p);
		if (main_s[p->i] == '-')
			ft_minus(main_s, p);
		if (main_s[p->i] == '.')
		{
			ft_dot(main_s, p, param);
			if (main_s[p->i] != '*' ||
				(main_s[p->i] < '0' && main_s[p->i] > '9'))
				p->check = 1;
		}
		if ((main_s[p->i] > '0' && main_s[p->i] <= '9') ||
			main_s[p->i] == '*')
			ft_width(main_s, p, param);
		if (main_s[p->i] != '-' && main_s[p->i] != '.' &&
			main_s[p->i] != '*' && !(main_s[p->i] >= '0' &&
			main_s[p->i] <= '9'))
			break ;
	}
}
