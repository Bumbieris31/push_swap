/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_and_sort_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 15:51:19 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/13 21:00:25 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

void	ft_push_b_and_reverse_back(t_node **st_a, t_node **st_b, \
int rot_b, char **str)
{
	ft_push_node(st_a, st_b);
	*str = ft_stradd(*str, "pb\n");
	while ((*st_b) && rot_b > 0)
	{
		rot_b--;
		ft_reverse_rotate_dllist(st_b);
		*str = ft_stradd(*str, "rrb\n");
	}
}

void	ft_swap_first_stack_b(t_node **st_a, t_node **st_b, \
char **str)
{
	ft_push_node(st_a, st_b);
	*str = ft_stradd(*str, "pb\n");
	ft_swap_single(st_b);
	*str = ft_stradd(*str, "sb\n");
}

int		ft_count_rotations(t_node *st_a, t_node *iter)
{
	int	count_rot;

	count_rot = 0;
	while (iter && st_a && st_a->value < iter->value)
	{
		iter = iter->next;
		count_rot++;
	}
	return (count_rot);
}

void	ft_rotate_count_plus_write(t_node **stack_to_rotate, \
char **str, int rot, int stack)
{
	while (rot > 0)
	{
		ft_rotate_dllist(stack_to_rotate);
		if (stack == 0)
			*str = ft_stradd(*str, "ra\n");
		else
			*str = ft_stradd(*str, "rb\n");
		rot--;
	}
}

void	ft_push_and_sort_b(t_node **st_a, t_node **st_b, char **str, int rot)
{
	int	rot_b;

	ft_rotate_count_plus_write(st_a, str, rot, A_STACK);
	if (*st_b)
		rot_b = ft_count_rotations(*st_a, *st_b);
	else
		rot_b = 0;
	if (rot_b > 0 && (*st_b)->next == 0 && (*st_b)->prev == 0)
		ft_swap_first_stack_b(st_a, st_b, str);
	else
	{
		ft_rotate_count_plus_write(st_b, str, rot_b, B_STACK);
		ft_push_b_and_reverse_back(st_a, st_b, rot_b, str);
	}
}
