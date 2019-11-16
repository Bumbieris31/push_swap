/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_to_val.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 18:42:59 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/11 18:23:41 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: finds the value in the t_node linked list rotates it so that \
** the node with such value is in the first place.
*/

void	ft_rotate_to_push(t_node **stack, char **oper_str, int ind, int len)
{
	int	i;

	i = 0;
	if (len / 2 >= ind)
	{
		while (i < ind)
		{
			ft_rotate_dllist(stack);
			*oper_str = ft_stradd(*oper_str, "ra\n");
			i++;
		}
	}
	else
	{
		while (i < (len - ind))
		{
			ft_reverse_rotate_dllist(stack);
			*oper_str = ft_stradd(*oper_str, "rra\n");
			i++;
		}
	}
}

/*
** @descr: Finds an index for a first occurance of a int value val.
*/

int		ft_find_ind_for_val(t_node *stack, int val)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->value == val)
			return (i);
		if (stack->next)
			stack = stack->next;
		else
			break ;
		i++;
	}
	return (0);
}

/*
** @descr: Finds the index of a int value val and rotates so that this \
** value is on top of the stack.
*/

void	ft_rotate_to_val(t_node **stack, char **oper_str, int val)
{
	int	ind;
	int	len;

	ind = ft_find_ind_for_val(*stack, val);
	len = ft_dllist_len(*stack);
	ft_rotate_to_push(stack, oper_str, ind, len);
}
