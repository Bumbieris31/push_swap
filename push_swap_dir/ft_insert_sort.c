/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 17:37:41 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/11 19:47:46 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: finds the highest and lowest values in t_node linked list. \
** If the cond == 1 returns the highest value else the lowest.
*/

int			ft_get_val(t_node *stack, int cond)
{
	int	temp_low;
	int	temp_high;

	temp_low = stack->value;
	temp_high = stack->value;
	while (stack->next)
	{
		stack = stack->next;
		if (temp_low > stack->value)
			temp_low = stack->value;
		if (temp_high < stack->value)
			temp_high = stack->value;
	}
	if (cond == HIGH)
		return (temp_high);
	else
		return (temp_low);
}

/*
** @descr: Finds the value of the next biggest int in a stack.
*/

int			ft_get_next_big_val(t_node *stack, int val)
{
	int	next_big;
	int	temp;

	while (stack && stack->value < val)
		stack = stack->next;
	next_big = stack->value;
	while (stack)
	{
		if (stack->value > val)
		{
			temp = stack->value;
			if (temp < next_big)
				next_big = temp;
		}
		stack = stack->next;
	}
	return (next_big);
}

static void	ft_push_in_the_middle(t_pls_box *pls_box, char **oper_str)
{
	int	next;

	next = ft_get_next_big_val(*pls_box->stack_a, (*pls_box->stack_b)->value);
	ft_rotate_to_val(pls_box->stack_a, oper_str, next);
	ft_push_node(pls_box->stack_b, pls_box->stack_a);
	*oper_str = ft_stradd(*oper_str, "pa\n");
}

/*
** @descr: Inserts the value from stack_b to stack_a in the correct order \
** by rotating stack_a so that the first value is max or next highest after \
** the first value of stack_b.
** @var: high and low variables save the highest and lowest values in stack_a \
** and are updated if the first conditional is true.
*/

void		ft_insert_sort(t_pls_box *pls_box, char **oper_str)
{
	int	low;
	int	high;
	int	first_val;

	low = ft_get_val(*pls_box->stack_a, LOW);
	high = ft_get_val(*pls_box->stack_a, HIGH);
	while (*pls_box->stack_b)
	{
		first_val = (*pls_box->stack_a)->value;
		if ((*pls_box->stack_b)->value < low || \
		(*pls_box->stack_b)->value > high)
		{
			ft_rotate_to_val(pls_box->stack_a, oper_str, low);
			if ((*pls_box->stack_b)->value < low)
				low = (*pls_box->stack_b)->value;
			else
				high = (*pls_box->stack_b)->value;
			ft_push_node(pls_box->stack_b, pls_box->stack_a);
			*oper_str = ft_stradd(*oper_str, "pa\n");
		}
		else
			ft_push_in_the_middle(pls_box, oper_str);
	}
	ft_rotate_to_val(pls_box->stack_a, oper_str, low);
}
