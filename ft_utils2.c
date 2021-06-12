/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:54:45 by elvmarti          #+#    #+#             */
/*   Updated: 2021/03/15 16:09:36 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *string)
{
	int i;

	if (!string)
		return ;
	i = 0;
	while (string[i] != '\0')
	{
		write(1, &string[i], 1);
		i++;
	}
}

char	*ft_strdup_falso(const char *s)
{
	char	*pt;
	int		size;
	int		i;

	size = 0;
	i = 0;
	while (s[size] >= '0' && s[size] <= '9')
		size++;
	if (!(pt = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (!pt)
		return (NULL);
	while (i < size)
	{
		pt[i] = s[i];
		i++;
	}
	pt[i] = '\0';
	return (pt);
}

int		ft_atoi_falso(char *str)
{
	long long int	signo;
	long long int	sol;

	signo = 1;
	sol = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (sol * signo > 2147483648)
			return (-1);
		else if (sol * signo < -2147483648)
			return (0);
		sol = sol * 10 + (*str - 48);
		str++;
	}
	return (signo * sol);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (!s || ft_strlen(s) < start)
	{
		if (!(str = (char *)malloc(sizeof(char))))
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = (char*)malloc(sizeof(*dest) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (*s1 != '\0')
	{
		dest[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		dest[i] = *s2;
		i++;
		s2++;
	}
	dest[i] = '\0';
	return (dest);
}
