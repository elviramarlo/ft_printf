/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 17:05:48 by elvmarti          #+#    #+#             */
/*   Updated: 2021/03/17 17:06:15 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*pt;
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (s[size] != '\0')
		size++;
	if (!(pt = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		pt[i] = s[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}
