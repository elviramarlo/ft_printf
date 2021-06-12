# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elvmarti <elvmarti@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/28 15:25:56 by elvmarti          #+#    #+#              #
#    Updated: 2021/03/17 17:07:27 by elvmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SONAME = libftprintf.so
FLAGS = -Wall -Wextra -Werror -I. -c
RM = rm -f
FILES = ft_printf.c \
		ft_print_char.c \
		ft_print_d_i.c \
		ft_print_p.c \
		ft_print_s.c \
		ft_print_u.c \
		ft_print_x.c \
		ft_flags.c \
		ft_utils.c \
		ft_utils2.c \
		ft_utils3.c \
		ft_convert_x.c
		
OBJS = $(FILES:%.c=%.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): $(FILES)
		gcc $(FLAGS) $(FILES)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(SONAME)

re: fclean all

so:
	gcc -shared -o $(SONAME) -fPIC $(FILES)

.PHONY: all clean fclean re so