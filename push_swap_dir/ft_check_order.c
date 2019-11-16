/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_order.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 14:23:55 by abumbier          #+#    #+#             */
/*   Updated: 2019/08/23 18:19:31 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: returns 0 if values are not sorted in growing order.
** othervise returns 1.
*/

int	ft_check_order(t_node *stack)
{
	t_node	*temp;

	if (stack && stack->next)
		temp = stack->next;
	else
		return (1);
	while (temp)
	{
		if (stack->value > temp->value)
			return (0);
		stack = stack->next;
		temp = stack->next;
	}
	return (1);
}
