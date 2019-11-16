# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/16 14:38:55 by abumbier          #+#    #+#              #
#    Updated: 2019/11/02 21:15:25 by abumbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf_funct

SRCS = $(wildcard $(SRC)/*.c)

OBJS = $(subst .c,.o,$(subst $(SRC)/,,$(SRCS)))

FLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@cp ./libft/libft.a .
	@mv libft.a $(NAME)
	@ar -rc $(NAME) $(OBJS)
	@echo "libftprintf compiled"

$(OBJS):
	@gcc $(FLAGS) $(SRCS) -I ./libft

clean:
	@rm -rf $(OBJS)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
