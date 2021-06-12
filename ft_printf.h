/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 17:17:04 by elvmarti          #+#    #+#             */
/*   Updated: 2021/03/17 17:05:01 by elvmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_printf
{
	int		i;
	int		n_return;
	int		minus;
	int		dot;
	int		width;
	int		zero;
	int		check;
}				t_printf;

int				ft_printf(char *main_s, ...);
void			ft_param(const char *main_s, va_list param, t_printf *p);
void			ft_flags(const char *main_s, va_list param, t_printf *p);
void			ft_print_c_p(const char *main_s, va_list param, t_printf *p);
void			ft_print_string(va_list param, t_printf *p);
void			ft_put_flags(t_printf *p, char *str);
void			ft_print_num(va_list param, t_printf *p);
char			*ft_str_zeros(t_printf *p, char *str);
void			ft_print_unsigned(va_list param, t_printf *p);
void			ft_print_hex(const char *main_s, va_list param, t_printf *p);
void			ft_print_punt(va_list param, t_printf *p);
char			*ft_conv_hex(unsigned int num, const char *main_s, t_printf *p);
char			*ft_conv_p(unsigned long int num);
char			*ft_itoa(long n);
size_t			ft_strlen(const char *str);
void			ft_putstr(char *string);
char			*ft_strdup_falso(const char *s);
void			ft_null(char *str);
int				ft_atoi_falso(char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_bzero(void *pt, size_t n);
char			*ft_strdup(const char *s);

#endif
