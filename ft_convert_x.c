/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:58:50 by elvmarti          #+#    #+#             */
/*   Updated: 2021/06/12 22:49:27 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_minmay(const char *main_s, t_printf *p)
{
	if (main_s[p->i] == 'x')
		return (87);
	else
		return (55);
}

static char	*ft_conv(unsigned int num, int min_may, unsigned int aux, int count)
{
	char *cad_hex;

	while (aux >= 16)
	{
		aux = aux / 16;
		count++;
	}
	cad_hex = (char *)malloc(sizeof(char) * count + 1);
	cad_hex[count] = '\0';
	count--;
	while (num >= 16)
	{
		if ((num % 16) < 10)
			cad_hex[count] = (num % 16) + 48;
		else if ((num % 16) >= 10)
			cad_hex[count] = (num % 16) + min_may;
		num = num / 16;
		count--;
	}
	if (num < 10)
		cad_hex[count] = num + 48;
	else if (num >= 10)
		cad_hex[count] = num + min_may;
	return (cad_hex);
}

char	*ft_conv_hex(unsigned int num, const char *main_s, t_printf *p)
{
	unsigned int	aux;
	int				count;
	char			*cad_hex;
	int				min_may;

	aux = num;
	count = 1;
	min_may = ft_minmay(main_s, p);
	cad_hex = ft_conv(num, min_may, aux, count);
	return (cad_hex);
}

static char	*ft_conv2(unsigned long int num, unsigned long int aux, int count)
{
	char	*cad_hex;

	while (aux >= 16)
	{
		aux = aux / 16;
		count++;
	}
	cad_hex = (char *)malloc(sizeof(char) * count + 1);
	cad_hex[count] = '\0';
	count--;
	while (num >= 16)
	{
		if ((num % 16) < 10)
			cad_hex[count] = (num % 16) + 48;
		else if ((num % 16) >= 10)
			cad_hex[count] = (num % 16) + 87;
		num = num / 16;
		count--;
	}
	if (num < 10)
		cad_hex[count] = num + 48;
	else if (num >= 10)
		cad_hex[count] = num + 87;
	return (cad_hex);
}

char		*ft_conv_p(unsigned long int num)
{
	unsigned long int	aux;
	int					count;
	char				*cad_hex;

	aux = num;
	count = 1;
	cad_hex = ft_conv2(num, aux, count);
	return (cad_hex);
}
