/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:40:51 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/02 22:16:47 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H

# include "libft/libft.h"
# include "libft/ft_printf.h"

# define A_STACK 0
# define B_STACK 1
# define LOW 0
# define HIGH 1

/*
** Point Encodings
*/

# define POINTS 1
# define COUNT 2
# define STATE 4
# define ALL_FLAGS 7

/*
** For testing: ARG=(); ./push_swap $ARG | ./checker $ARG
*/

typedef struct		s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_pls_box
{
	t_node			**stack_a;
	t_node			**stack_b;
	t_node			**sorted;
}					t_pls_box;

void				ft_error_msg();
int					ft_isint(char *str);
void				ft_check_dup(t_node *stack);
int					ft_dllist_len(t_node *node);
void				ft_delete_list(t_node *node);
void				ft_swap_single(t_node **node);
void				ft_rotate_dllist(t_node **node);
t_node				*ft_get_last_node(t_node *node);
t_node				*ft_get_first_node(t_node *node);
t_node				*ft_save_input(int argc, char **argv);
t_node				*ft_save_values(int argc, char **argv);
int					ft_valid_numbers(int argc, char **argv);
void				ft_push_node(t_node **from, t_node **to);
t_node				*ft_make_new_node(int value, t_node *prev);
int					ft_valid_output(int argc, char **argv, t_node **stack);
int					ft_valid_instr(t_node **st_a, t_node **st_b, int flags);
void				ft_swap_both(t_node **st_a, t_node **st_b);
void				ft_rotate_both(t_node **st_a, t_node **st_b);
void				ft_reverse_rotate_dllist(t_node **node);
void				ft_reverse_rotate_both(t_node **st_a, t_node **st_b);
int					ft_check_sort(t_node *st_a, t_node *st_b);
t_node				*ft_dllist_find_ind(t_node *stack, int ind);

/*
** checker
*/

int					ft_check_flag_output(char *str);
void				ft_print_stacks(t_node *stack_a, t_node *stack_b);
int					ft_find_operation(char *str, t_node **st_a, t_node **st_b);
/*
** push_swap
*/

int					ft_int_arg_count1(int flags, int argc);
t_node				*ft_valid_input(int argc, char **argv);
void				ft_execute_flags(char *final_str, int flags, int argc);
void				ft_sort_stuff(t_node **stack_a, t_node **sorted, \
int flags, int argc);

/*
** Select Algo
*/

int					ft_check_order(t_node *stack);
int					ft_selectionsort(t_node **stack_a);
int					ft_find_next_lowest(t_node *stack, int len);
void				ft_rotate_to_ind(t_node **stack_a, int rotate);
void				ft_find_closest(int *ind_1, int *ind_2, int len);
void				ft_push_back(t_node **stack_a, t_node **stack_b);

/*
** Plswork Algo
*/

int					ft_square_root(int num);
char				*ft_plsworksort(t_pls_box *pls_box);
void				ft_copy_list(t_node *stack, t_node **copied);
int					ft_count_rotation(t_node *st_a, t_node *iter);
void				ft_swap_first_stack_b(t_node **st_a, t_node **st_b, \
char **str);
void				ft_push_and_sort_b(t_node **st_a, t_node **st_b, \
char **str, int rot);
void				ft_push_all_b_to_a(t_node **stack_a, t_node **stack_b, \
char **str);
void				ft_delete_data_structs(t_pls_box *pls_box, \
char **del_str, char **final_str);

/*
** Sort five
*/
int					ft_find_high(t_node *stack_a);
char				*ft_sort_five(t_pls_box *pls_box);
int					ft_get_val(t_node *stack, int cond);
int					ft_get_next_big_val(t_node *stack, int val);
void				ft_push_two_b(t_pls_box *pls_box, char **oper_str);
void				ft_insert_sort(t_pls_box *pls_box, char **oper_str);
void				ft_sort_three_a(t_pls_box *pls_box, char **oper_str);
void				ft_rotate_to_val(t_node **stack, char **oper_str, int val);

/*
** String Shortener
*/

char				*ft_shorten_str(char **old);
int					ft_pb_pa_delete(char **old, char **new);
int					ft_rrb_rb_delete(char **old, char **new);
int					ft_ra_rb_replace(char **old, char **new);
void				ft_skip_mirrored_op(char **old, int count);
void				ft_copy_unshortened(char **old, char **new);
int					ft_rrb_ra_rb_replace(char **old, char **new);
int					ft_rb_pb_rrb_replace(char **old, char **new);
int					ft_rrb_ra_rb_replace(char **old, char **new);
void				ft_copy_remaining_op(char **old, char **new, int count);
void				ft_replace_with_combined(char **new, const char *str, \
int count);
int					ft_number_of_needles(char *heystack, const char *needle, \
int len);
int					ft_ra_rra_delete(char **old, char **new);

#endif
