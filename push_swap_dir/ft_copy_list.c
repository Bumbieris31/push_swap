/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:34:16 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/11 18:26:48 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: copies the values in stack into a new doubly linked list (copied).
*/

void	ft_copy_list(t_node *stack, t_node **copied)
{
	*copied = ft_make_new_node(stack->value, 0);
	stack = stack->next;
	while (stack)
	{
		(*copied)->next = ft_make_new_node(stack->value, *copied);
		stack = stack->next;
		*copied = (*copied)->next;
	}
	*copied = ft_get_first_node(*copied);
}
