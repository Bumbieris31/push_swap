/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 19:07:00 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/07 16:51:35 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

/*
** @descr: allocates and returns t_node struct with a node->value passed in \
** as the first parameter.
*/

t_node	*ft_make_new_node(int value, t_node *prev)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	node->next = 0;
	node->prev = prev;
	node->value = value;
	return (node);
}

/*
** @descr: frees the values in a t_node doubly linked list
*/

void	ft_delete_list(t_node *node)
{
	t_node	*backup;

	node = ft_get_last_node(node);
	while (node && node->prev)
	{
		backup = node->prev;
		free(node);
		node = backup;
	}
	if (node)
		free(node);
}

/*
** @descr: returns the first node in a t_node doubly linked list.
*/

t_node	*ft_get_first_node(t_node *node)
{
	while (node && node->prev)
		node = node->prev;
	return (node);
}

/*
** @descr: returns the last node in a t_node doubly linked list.
*/

t_node	*ft_get_last_node(t_node *node)
{
	while (node && node->next)
		node = node->next;
	return (node);
}

/*
** @desc: Returns the number of nodes the doubly linked list holds.
** For index usage subtract - 1.
*/

int		ft_dllist_len(t_node *node)
{
	int	i;

	i = 1;
	if (node == 0)
		return (0);
	node = ft_get_first_node(node);
	while (node->next)
	{
		node = node->next;
		i++;
	}
	return (i);
}
