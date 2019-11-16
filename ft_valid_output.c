/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 19:04:52 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/02 21:10:40 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

void	ft_error_msg(void)
{
	ft_putstr("Error\n");
	exit(1);
}

/*
** @descr: Check if there are duplicate values in a t_node list.
*/

void	ft_check_dup(t_node *stack)
{
	t_node	*iter;

	while (stack)
	{
		iter = stack;
		while (iter)
		{
			iter = iter->next;
			if (iter && stack->value == iter->value)
			{
				ft_delete_list(stack);
				ft_error_msg();
			}
		}
		stack = stack->next;
	}
}

/*
** @descr: Checks for duplicates and int sizes and creates a linked list.
*/

int		ft_valid_output(int argc, char **argv, t_node **stack)
{
	int	flags;

	if (argc < 2)
		ft_error_msg();
	flags = ft_valid_numbers(argc, argv);
	*stack = ft_save_values(argc, argv);
	ft_check_dup(*stack);
	return (flags);
}
