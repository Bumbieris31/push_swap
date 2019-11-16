/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 11:49:49 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/13 21:26:44 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

/*
** @descr: Pushes the top node of one linked list onto the top
** of the other linked list whose pointer addreses are passed as
** the arguments t_node **from and t_node **to.
*/

void	ft_push_node(t_node **from, t_node **to)
{
	t_node	*temp;

	temp = 0;
	if (!(*from))
		return ;
	if (*to)
		temp = *to;
	*to = *from;
	if (!(*from)->next)
		*from = 0;
	else
	{
		*from = (*from)->next;
		(*from)->prev = 0;
	}
	if (temp != 0)
	{
		(*to)->next = temp;
		temp->prev = *to;
	}
	else
		(*to)->next = 0;
}
