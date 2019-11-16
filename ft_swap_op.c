/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 16:30:47 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/02 14:36:55 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

/*
** @descr: Swaps the top node of the doubly linked list.
*/

void	ft_swap_single(t_node **node)
{
	t_node	*node_sec;
	t_node	*node_third;

	if ((*node) && (*node)->next)
	{
		node_sec = (*node)->next;
		if (node_sec->next)
		{
			node_third = node_sec->next;
			(*node)->next = node_third;
			node_third->prev = *node;
		}
		else
			(*node)->next = 0;
		node_sec->next = *node;
		(*node)->prev = node_sec;
		node_sec->prev = 0;
		*node = ft_get_first_node(*node);
	}
}

/*
** @descr: Swaps two top nodes of the doubly linked lists.
*/

void	ft_swap_both(t_node **st_a, t_node **st_b)
{
	ft_swap_single(st_a);
	ft_swap_single(st_b);
}
