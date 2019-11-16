/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 21:23:57 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/02 22:07:06 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

void	ft_print_stacks(t_node *stack_a, t_node *stack_b)
{
	int	temp_a;
	int	temp_b;

	temp_a = 1;
	temp_b = 1;
	ft_printf("-----------------------\n");
	while (stack_a || stack_b)
	{
		if (stack_a && stack_b)
			ft_printf("%-11d|%11d\n", stack_a->value, stack_b->value);
		else if (stack_a)
			ft_printf("%-11d|\n", stack_a->value);
		else
			ft_printf("           |%10d\n", stack_b);
		if (stack_a && stack_a->next)
			stack_a = stack_a->next;
		else
			stack_a = 0;
		if (stack_b && stack_b->next)
			stack_b = stack_b->next;
		else
			stack_b = 0;
	}
	ft_printf("-----------------------\n");
}
