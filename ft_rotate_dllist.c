/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_dllist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:33:46 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/11 19:59:13 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

/*
** @descr: rotate stack.
*/

void	ft_rotate_dllist(t_node **stack)
{
	t_node	*last;
	t_node	*new_first;

	if (ft_dllist_len(*stack) <= 1)
		return ;
	last = ft_get_last_node(*stack);
	last->next = *stack;
	new_first = (*stack)->next;
	new_first->prev = 0;
	(*stack)->prev = last;
	(*stack)->next = 0;
	*stack = new_first;
}

/*
** @descr: rotates both stacks.
*/

void	ft_rotate_both(t_node **st_a, t_node **st_b)
{
	ft_rotate_dllist(st_a);
	ft_rotate_dllist(st_b);
}

/*
** @descr: reverse rotate stack.
*/

void	ft_reverse_rotate_dllist(t_node **node)
{
	t_node	*last;
	t_node	*new_last;

	if (ft_dllist_len(*node) <= 1)
		return ;
	last = ft_get_last_node(*node);
	new_last = last->prev;
	new_last->next = 0;
	(*node)->prev = last;
	last->next = *node;
	last->prev = 0;
	*node = last;
}

/*
** @descr: reverse rotate both stacks.
*/

void	ft_reverse_rotate_both(t_node **st_a, t_node **st_b)
{
	ft_reverse_rotate_dllist(st_a);
	ft_reverse_rotate_dllist(st_b);
}
