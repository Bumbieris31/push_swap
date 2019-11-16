/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_five.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:38:17 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/07 16:55:59 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: pushes values to the stack_b and writes the operations if sorting \
** is needed.
*/

void	ft_push_two_b(t_pls_box *pls_box, char **oper_str)
{
	while (!ft_check_order(*pls_box->stack_a) && \
	ft_dllist_len(*pls_box->stack_a) > 3)
	{
		ft_push_node(pls_box->stack_a, pls_box->stack_b);
		*oper_str = ft_stradd(*oper_str, "pb\n");
	}
}

/*
** @descr: finds and returns the index of the highest values in a stack if.
*/

int		ft_find_high(t_node *stack_a)
{
	int	i;
	int	tmp;
	int	high;

	i = 0;
	tmp = 0;
	high = stack_a->value;
	while (stack_a->next)
	{
		tmp++;
		stack_a = stack_a->next;
		if (stack_a->value > high)
		{
			i = tmp;
			high = stack_a->value;
		}
	}
	return (i);
}

/*
** @descr: sorts the 3 values left in stack_a. If the index of high value is \
** either 0 or 1 then stack rotates so that it becomes the last one.
** Then if necessary swaps the first 2 values.
*/

void	ft_sort_three_a(t_pls_box *pls_box, char **oper_str)
{
	int	high;

	high = ft_find_high(*pls_box->stack_a);
	if (high == 1)
	{
		ft_reverse_rotate_dllist(pls_box->stack_a);
		*oper_str = ft_stradd(*oper_str, "rra\n");
	}
	else if (high == 0)
	{
		ft_rotate_dllist(pls_box->stack_a);
		*oper_str = ft_stradd(*oper_str, "ra\n");
	}
	if ((*pls_box->stack_a)->value > (*pls_box->stack_a)->next->value)
	{
		ft_swap_single(pls_box->stack_a);
		*oper_str = ft_stradd(*oper_str, "sa\n");
	}
}

/*
** @descr: sorts the 5 value stack in a sufficient manner.
*/

char	*ft_sort_five(t_pls_box *pls_box)
{
	t_node	*stack_b;
	char	*oper_str;

	stack_b = 0;
	oper_str = 0;
	pls_box->stack_b = &stack_b;
	ft_push_two_b(pls_box, &oper_str);
	if (!ft_check_order(*pls_box->stack_a))
		ft_sort_three_a(pls_box, &oper_str);
	ft_insert_sort(pls_box, &oper_str);
	return (oper_str);
}
