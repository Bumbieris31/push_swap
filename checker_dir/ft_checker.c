/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:40:54 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/02 22:25:19 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

int	main(int argc, char **argv)
{
	int		flags;
	int		sort_ret;
	t_node	*stack_a;
	t_node	*stack_b;

	if (argc == 1)
		return (0);
	stack_b = 0;
	flags = ft_valid_output(argc, argv, &stack_a);
	sort_ret = ft_valid_instr(&stack_a, &stack_b, flags);
	ft_delete_list(stack_a);
	if (sort_ret == 1)
		ft_putstr("OK\n");
	else if (sort_ret == -1)
		ft_error_msg();
	else
		ft_putstr("KO\n");
	return (0);
}
