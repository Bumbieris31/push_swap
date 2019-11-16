/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:34:48 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/17 18:46:39 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: creates a pls_box and fills the stack_a and sorted values.
*/

t_pls_box	*ft_make_pls_box(t_node **stack_a, t_node **sorted)
{
	t_pls_box	*pls_box;

	pls_box = (t_pls_box*)malloc(sizeof(t_pls_box));
	pls_box->stack_a = stack_a;
	pls_box->sorted = sorted;
	return (pls_box);
}

/*
** @descr: calls functions that sort doubly linked list, shorten \
** the string and free all the elements.
*/

void		ft_sort_stuff(t_node **stack_a, t_node **sorted, int flags, \
int argc)
{
	int			len;
	char		*oper_str;
	char		*del_str;
	char		*final_str;
	t_pls_box	*pls_box;

	pls_box = ft_make_pls_box(stack_a, sorted);
	if (!ft_check_order(*stack_a))
	{
		ft_selectionsort(pls_box->sorted);
		len = ft_dllist_len(*stack_a);
		if (len <= 10)
			oper_str = ft_sort_five(pls_box);
		else
			oper_str = ft_plsworksort(pls_box);
		del_str = oper_str;
		final_str = ft_shorten_str(&oper_str);
		ft_putstr(final_str);
		ft_execute_flags(final_str, flags, argc);
		ft_delete_data_structs(pls_box, &del_str, &final_str);
	}
}
