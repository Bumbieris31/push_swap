# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/13 16:48:57 by abumbier          #+#    #+#              #
#    Updated: 2019/11/04 19:31:07 by abumbier      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

SRCS1 = checker_dir/ft_checker.c checker_dir/ft_valid_instr.c \
checker_dir/ft_check_sort.c checker_dir/ft_print_stacks.c\
checker_dir/ft_check_flag_output.c

SRCS2 = push_swap_dir/ft_push_swap.c \
push_swap_dir/ft_sort_stuff.c push_swap_dir/ft_square_root.c \
push_swap_dir/ft_check_order.c push_swap_dir/ft_selectionsort.c \
push_swap_dir/ft_plsworksort.c push_swap_dir/ft_copy_list.c \
push_swap_dir/ft_push_and_sort_b.c push_swap_dir/ft_shorten_str.c \
push_swap_dir/ft_copy_unshortened.c push_swap_dir/ft_op_delete.c \
push_swap_dir/ft_op_replace.c push_swap_dir/ft_rrb_ra_rb_replace.c \
push_swap_dir/ft_sort_five.c push_swap_dir/ft_insert_sort.c \
push_swap_dir/ft_rotate_to_val.c push_swap_dir/ft_delete_data_structs.c \
push_swap_dir/ft_execute_flags.c

SRCS3 = ft_swap_op.c ft_push_node.c ft_manage_stack.c ft_isint.c \
ft_rotate_dllist.c ft_save_values.c ft_valid_output.c ft_valid_numbers.c \
ft_int_arg_count.c

OBJS1 = ft_checker.o ft_valid_instr.o ft_check_sort.o \
ft_check_flag_output.o ft_print_stacks.o

OBJS2 =  ft_push_swap.o ft_sort_stuff.o ft_square_root.o ft_check_order.o \
ft_selectionsort.o ft_plsworksort.o ft_copy_list.o ft_push_and_sort_b.o \
ft_shorten_str.o ft_copy_unshortened.o ft_op_delete.o ft_op_replace.o \
ft_rrb_ra_rb_replace.o ft_sort_five.o ft_insert_sort.o ft_rotate_to_val.o \
ft_delete_data_structs.o ft_execute_flags.o

OBJS3 = ft_swap_op.o ft_push_node.o ft_manage_stack.o ft_isint.o \
ft_rotate_dllist.o ft_save_values.o ft_valid_output.o ft_valid_numbers.o \
ft_int_arg_count.o

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/libftprintf.a

all: $(LIBFT) $(NAME1) $(NAME2)

$(NAME1): $(LIBFT) $(OBJS1)
	@gcc $(FLAGS) -o $(NAME1) $(OBJS1) $(OBJS3) -L libft -lftprintf
	@echo "$(NAME1) compiled"

$(NAME2): $(LIBFT) $(OBJS2)
	@gcc $(FLAGS) -o $(NAME2) $(OBJS2) $(OBJS3) -L libft -lftprintf
	@echo "$(NAME2) compiled"

$(OBJS1): $(OBJS3)
	@gcc $(FLAGS) -c $(SRCS1) -I ./

$(OBJS2): $(OBJS3)
	@gcc $(FLAGS) -c $(SRCS2) -I ./

$(OBJS3):
	@gcc $(FLAGS) -c $(SRCS3) -I ./

$(LIBFT):
	@make -C libft

clean:
	@rm -rf $(OBJS1) $(OBJS2) $(OBJS3)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME1) $(NAME2)
	@make -C libft fclean

re: fclean all
