# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/04 21:12:04 by abumbier          #+#    #+#              #
#    Updated: 2019/11/02 21:16:03 by abumbier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_atoi.c ft_memccpy.c ft_strcpy.c ft_strrchr.c \
ft_memchr.c ft_strdel.c ft_strstr.c ft_memcmp.c ft_strdup.c \
ft_tolower.c ft_bzero.c ft_memcpy.c ft_strlcat.c ft_toupper.c \
ft_isalnum.c ft_memmove.c ft_strlen.c ft_isalpha.c ft_memset.c \
ft_strncat.c ft_isascii.c ft_strcat.c ft_strncmp.c ft_isdigit.c \
ft_strchr.c ft_strncpy.c ft_isprint.c ft_strclr.c ft_strcmp.c \
ft_strnstr.c ft_putchar_fd.c ft_putstr_fd.c ft_strmap.c ft_strtrim.c \
ft_putendl.c ft_strclr.c ft_strmapi.c ft_itoa.c ft_putendl_fd.c \
ft_strequ.c ft_strnequ.c ft_memalloc.c ft_putnbr.c ft_striter.c \
ft_strnew.c ft_memdel.c ft_putnbr_fd.c ft_striteri.c ft_strsplit.c \
ft_putchar.c ft_putstr.c ft_strjoin.c ft_strsub.c ft_lstadd.c \
ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
ft_wordlen.c ft_intlen.c ft_get_next_line.c ft_stradd.c ft_strcadd.c \
ft_ftoa.c ft_move_point_left.c ft_move_point_right.c ft_llintlen.c \
ft_lltoa.c ft_ldtoa.c ft_move_point_left_ld.c ft_move_point_right_ld.c \
ft_unslen.c ft_prefix_str.c ft_prefix_char.c

OBJ = ft_atoi.o ft_memccpy.o ft_strcpy.o ft_strrchr.o \
ft_memchr.o ft_strdel.o ft_strstr.o ft_memcmp.o ft_strdup.o \
ft_tolower.o ft_bzero.o ft_memcpy.o ft_strlcat.o ft_toupper.o \
ft_isalnum.o ft_memmove.o ft_strlen.o ft_isalpha.o ft_memset.o \
ft_strncat.o ft_isascii.o ft_strcat.o ft_strncmp.o ft_isdigit.o \
ft_strchr.o ft_strncpy.o ft_isprint.o ft_strclr.o ft_strcmp.o \
ft_strnstr.o ft_putchar_fd.o ft_putstr_fd.o ft_strmap.o ft_strtrim.o \
ft_putendl.o ft_strclr.o ft_strmapi.o ft_itoa.o ft_putendl_fd.o \
ft_strequ.o ft_strnequ.o ft_memalloc.o ft_putnbr.o ft_striter.o \
ft_strnew.o ft_memdel.o ft_putnbr_fd.o ft_striteri.o ft_strsplit.o \
ft_putchar.o ft_putstr.o ft_strjoin.o ft_strsub.o ft_lstadd.o \
ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o ft_lstnew.o \
ft_wordlen.o ft_intlen.o ft_get_next_line.o ft_stradd.o ft_strcadd.o \
ft_ftoa.o ft_move_point_left.o ft_move_point_right.o ft_llintlen.o \
ft_lltoa.o ft_ldtoa.o ft_move_point_left_ld.o ft_move_point_right_ld.o \
ft_unslen.o ft_prefix_str.o ft_prefix_char.o

NAME = libft.a

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRCS) -I .
	@ar -rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
