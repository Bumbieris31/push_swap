/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plsworksort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 14:53:47 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/11 18:23:06 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: pushes all the stack_b to stack_a.
*/

void		ft_push_all_b_to_a(t_node **stack_a, t_node **stack_b, char **str)
{
	while (*stack_b)
	{
		ft_push_node(stack_b, stack_a);
		*str = ft_stradd(*str, "pa\n");
	}
}

static void	ft_lowest_condition(t_node **iter, t_pls_box *pls_box, int *rot, \
char **str)
{
	if ((*iter)->next)
		*iter = (*iter)->next;
	ft_push_and_sort_b(pls_box->stack_a, pls_box->stack_b, str, *rot);
	*rot = 0;
}

static void	ft_incr_rotate(int *j, int div, int *rotate, t_node **iter)
{
	if (*j == div)
	{
		(*rotate)++;
		if ((*iter)->next)
			*iter = (*iter)->next;
	}
	*j = 0;
}

/*
** @descr: Pushes 10 lowest values from stack_a to stack_b and calls the \
** funct that sorts the values in stack_b.
*/

void		ft_push_ten_val(t_pls_box *pls_box, char **str, int div)
{
	int		i;
	int		j;
	int		rotate;
	t_node	*iter;

	i = 0;
	j = 0;
	rotate = 0;
	iter = *pls_box->stack_a;
	while (i < div && *pls_box->stack_a)
	{
		while (j < div && (*pls_box->sorted))
		{
			if ((*pls_box->sorted)->value == iter->value)
			{
				i++;
				ft_lowest_condition(&iter, pls_box, &rotate, str);
				break ;
			}
			j++;
			(*pls_box->sorted) = (*pls_box->sorted)->next;
		}
		ft_incr_rotate(&j, div, &rotate, &iter);
		(*pls_box->sorted) = ft_get_first_node(*pls_box->sorted);
	}
}

/*
** @descr: Sorts the values by pushing the amount of square root of total \
** amount to stack_b which is there reverse sorted by insertion sort and \
** once the stack_a is sorted or empty, stack_b is pushed back to stack_a.
*/

char		*ft_plsworksort(t_pls_box *pls_box)
{
	int			i;
	int			div;
	t_node		*stack_b;
	char		*oper_str;

	stack_b = 0;
	oper_str = 0;
	pls_box->stack_b = &stack_b;
	div = ft_square_root(ft_dllist_len(*pls_box->stack_a));
	while (*pls_box->stack_a)
	{
		ft_push_ten_val(pls_box, &oper_str, div);
		i = 0;
		while (*pls_box->sorted && i < div)
		{
			i++;
			ft_rotate_dllist(pls_box->sorted);
		}
	}
	ft_push_all_b_to_a(pls_box->stack_a, pls_box->stack_b, &oper_str);
	return (oper_str);
}
