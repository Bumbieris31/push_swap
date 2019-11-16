/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selectionsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 17:43:29 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/07 18:04:18 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: returns the value of the next lowest int in a t_node list.
*/

int			ft_find_next_lowest(t_node *stack, int len)
{
	int	i;
	int	low;
	int	low_ind;

	i = 0;
	low_ind = 0;
	stack = ft_get_first_node(stack);
	low = stack->value;
	while (stack->next)
	{
		i++;
		stack = stack->next;
		if (low > stack->value)
		{
			low = stack->value;
			low_ind = i;
		}
	}
	if (low_ind > len / 2)
		low_ind = (len - low_ind) * -1;
	return (low_ind);
}

/*
** @descr: pushes all the stack_b to stack_a.
*/

void		ft_push_back(t_node **stack_a, t_node **stack_b)
{
	while (*stack_b)
		ft_push_node(stack_b, stack_a);
}

/*
** @descr: rotates the amount of value of the parameter rotate.
** If rotate is negative then reverse rotates.
*/

static void	ft_execute_rotate(t_node **stack_a, int rotate)
{
	while (rotate != 0)
	{
		if (rotate > 0)
		{
			ft_rotate_dllist(stack_a);
			rotate--;
		}
		else
		{
			ft_reverse_rotate_dllist(stack_a);
			rotate++;
		}
	}
}

/*
** @descr: sorts the array of numbers by pushing smallest number onto the \
** stack_b and then pushing them all back to stack_a.
*/

int			ft_selectionsort(t_node **stack_a)
{
	int		len;
	int		rotate;
	t_node	*stack_b;

	len = ft_dllist_len(*stack_a);
	stack_b = 0;
	while (len > 1 && !ft_check_order(*stack_a))
	{
		rotate = ft_find_next_lowest(*stack_a, len);
		ft_execute_rotate(stack_a, rotate);
		ft_push_node(stack_a, &stack_b);
		len = ft_dllist_len(*stack_a);
	}
	ft_push_back(stack_a, &stack_b);
	return (1);
}
