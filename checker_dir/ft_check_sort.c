/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:10:34 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/06 20:21:59 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: checks if the values in st_a are sorted and st_b is empty.
** @ret: returns 1 if the st_a is sorted and st_b is empty. Otherwise 0.
*/

int	ft_check_sort(t_node *st_a, t_node *st_b)
{
	if (st_b)
	{
		ft_delete_list(st_b);
		return (0);
	}
	if (st_a)
	{
		while (st_a->next)
		{
			if (st_a->value < st_a->next->value)
				st_a = st_a->next;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}
