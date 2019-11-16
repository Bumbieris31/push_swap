/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:57:31 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/02 22:29:57 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

int	main(int argc, char **argv)
{
	int		flags;
	t_node	*del;
	t_node	*stack_a;
	t_node	*sorted;

	if (argc == 1)
		return (0);
	sorted = 0;
	flags = ft_valid_output(argc, argv, &stack_a);
	ft_copy_list(stack_a, &sorted);
	del = stack_a;
	ft_sort_stuff(&stack_a, &sorted, flags, argc);
	return (0);
}
