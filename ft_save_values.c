/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 15:04:53 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/02 21:23:40 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

/*
** @descr: creates a doubly linked list which nodes hold the values from argv \
** converted to int.
*/

static int	ft_check_flags(char **argv, int i)
{
	if (ft_strequ(argv[i], "-p") || ft_strequ(argv[i], "-c") \
	|| ft_strequ(argv[i], "-s"))
	{
		return (1);
	}
	return (0);
}

t_node		*ft_save_values(int argc, char **argv)
{
	int		i;
	int		value;
	t_node	*node;

	i = 2;
	value = ft_atoi(argv[1]);
	node = ft_make_new_node(value, 0);
	while (argv[i] && i < argc)
	{
		if (!ft_check_flags(argv, i))
		{
			node->next = ft_make_new_node(ft_atoi(argv[i]), node);
			node = node->next;
		}
		i++;
	}
	node = ft_get_first_node(node);
	return (node);
}
