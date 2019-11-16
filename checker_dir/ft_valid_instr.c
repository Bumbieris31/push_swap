/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_instr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 18:33:39 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/04 19:42:59 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: finds and executes the operation in str.
** @ret: 0 if operation exists and 1 if it doesnt or is incorrectly \
** formated.
*/

int			ft_find_operation(char *str, t_node **st_a, t_node **st_b)
{
	if (ft_strequ(str, "sa"))
		ft_swap_single(st_a);
	else if (ft_strequ(str, "sb"))
		ft_swap_single(st_b);
	else if (ft_strequ(str, "ss"))
		ft_swap_both(st_a, st_b);
	else if (ft_strequ(str, "pa"))
		ft_push_node(st_b, st_a);
	else if (ft_strequ(str, "pb"))
		ft_push_node(st_a, st_b);
	else if (ft_strequ(str, "ra"))
		ft_rotate_dllist(st_a);
	else if (ft_strequ(str, "rb"))
		ft_rotate_dllist(st_b);
	else if (ft_strequ(str, "rr"))
		ft_rotate_both(st_a, st_b);
	else if (ft_strequ(str, "rra"))
		ft_reverse_rotate_dllist(st_a);
	else if (ft_strequ(str, "rrb"))
		ft_reverse_rotate_dllist(st_b);
	else if (ft_strequ(str, "rrr"))
		ft_reverse_rotate_both(st_a, st_b);
	else
		return (1);
	return (0);
}

/*
** @descr: Checks if the instruction is correct. If not then deletes st_b \
** and returns -1. Deletes the str after it is checked.
*/

static int	ft_check_only_instr(t_node **st_a, t_node **st_b, \
char **str)
{
	int	invalid_instr;

	if (ft_strequ(*str, ""))
		invalid_instr = 0;
	else
		invalid_instr = ft_find_operation(*str, st_a, st_b);
	if (invalid_instr)
	{
		if (ft_check_flag_output(*str))
			invalid_instr = 0;
	}
	free(*str);
	if (invalid_instr)
	{
		if (*st_b)
			ft_delete_list(*st_b);
		return (-1);
	}
	return (0);
}

/*
** @descr: Checks if the instructions passed from push_swap are valid and \
** sort the stack correctly.
*/

int			ft_valid_instr(t_node **st_a, t_node **st_b, int flags)
{
	int		i;
	int		state_flag;
	char	*str;

	i = 1;
	state_flag = 0;
	if (flags >= STATE)
		state_flag = 1;
	while (i > 0)
	{
		i = ft_get_next_line(0, &str);
		if (ft_check_only_instr(st_a, st_b, &str) == -1)
			return (-1);
		if (state_flag)
			ft_print_stacks(*st_a, *st_b);
	}
	return (ft_check_sort(*st_a, *st_b));
}
