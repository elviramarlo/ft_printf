/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 21:16:19 by elvmarti          #+#    #+#             */
/*   Updated: 2021/03/17 17:07:00 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static long	ft_size(long n)
{
	long	i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char		*ft_itoa(long n)
{
	char			*dest;
	unsigned int	len;
	long			nb;
	unsigned int	i;

	nb = (n < 0 ? -n : n);
	len = ft_size(nb);
	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * len + (n < 0 ? 2 : 1))))
		return (NULL);
	if (n < 0)
	{
		dest[0] = '-';
		len++;
	}
	i = len - 1;
	while (nb >= 10)
	{
		dest[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	dest[i] = nb % 10 + '0';
	dest[len] = '\0';
	return (dest);
}

void		ft_bzero(void *pt, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)pt)[i] = '\0';
		i++;
	}
}

void		ft_null(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}
