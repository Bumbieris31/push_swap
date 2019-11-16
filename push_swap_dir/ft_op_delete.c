/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 16:43:19 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/04 15:24:07 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: copy shortened version of *old operations into the *new str.
** @var: rb_count and rrb_count do not advance index in old. Thats why the \
** the second call of ft_number_of_needles is *old is advanced (rrb_count * 4) \
** spaces further.
** @var: del holds the amount of combinations required to delete.
*/

int		ft_rrb_rb_delete(char **old, char **new)
{
	int	del;
	int	rb_count;
	int	rrb_count;

	rrb_count = ft_number_of_needles(*old, "rrb\n", 4);
	if (rrb_count == 0)
		return (0);
	rb_count = ft_number_of_needles(*old + (rrb_count * 4), "rb\n", 3);
	if (rb_count == 0)
		return (0);
	del = (rrb_count < rb_count ? rrb_count : rb_count);
	if (rrb_count > rb_count)
		ft_copy_remaining_op(old, new, (rrb_count - rb_count) * 4);
	ft_skip_mirrored_op(old, del * 7);
	return (1);
}

/*
** @descr: same as ft_rrb_rb_delete()
*/

int		ft_pb_pa_delete(char **old, char **new)
{
	int	del;
	int	pb_count;
	int	pa_count;

	pb_count = ft_number_of_needles(*old, "pb\n", 3);
	if (pb_count == 0)
		return (0);
	pa_count = ft_number_of_needles(*old + (pb_count * 3), "pa\n", 3);
	if (pa_count == 0)
		return (0);
	del = (pb_count < pa_count ? pb_count : pa_count);
	if (pb_count > pa_count)
		ft_copy_remaining_op(old, new, (pb_count - pa_count) * 3);
	ft_skip_mirrored_op(old, del * 6);
	return (1);
}

/*
** @descr: same as ft_rrb_rb_delete()
*/

int		ft_ra_rra_delete(char **old, char **new)
{
	int	del;
	int	ra_count;
	int	rra_count;

	ra_count = ft_number_of_needles(*old, "ra\n", 3);
	if (ra_count == 0)
		return (0);
	rra_count = ft_number_of_needles(*old + (ra_count * 3), "rra\n", 4);
	if (rra_count == 0)
		return (0);
	del = (ra_count < rra_count ? ra_count : rra_count);
	if (ra_count > rra_count)
		ft_copy_remaining_op(old, new, (ra_count - rra_count) * 3);
	ft_skip_mirrored_op(old, del * 7);
	return (1);
}
