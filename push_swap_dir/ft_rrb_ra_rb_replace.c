/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb_ra_rb_replace.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 19:44:01 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/07 18:04:18 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: Copies or skips the necessary rrb into the new str.
** @ret: If returns 1 the rest of rr and rb operations are skipped and \
** all of the ra operations are copied.
*/

static int	ft_skip_rrb(char **old, char **new, int rrb_count, int rb_count)
{
	int	rest;

	rest = rrb_count - rb_count;
	if (rest > 0)
	{
		ft_copy_remaining_op(old, new, rest * 4);
		ft_skip_mirrored_op(old, (rrb_count - rest) * 4);
		return (1);
	}
	ft_skip_mirrored_op(old, rrb_count * 4);
	return (0);
}

/*
** @descr: Copies or skips the necessary ra into the new str. Then replaces \
** ra and rb combinations with rr where necessary.
*/

static void	ft_skip_ra(char **old, char **new, int ra_count, int rr_pot)
{
	int	rr_count;

	rr_count = (ra_count < rr_pot ? ra_count : rr_pot);
	if (rr_count < ra_count)
		ft_copy_remaining_op(old, new, (ra_count - rr_count) * 3);
	ft_skip_mirrored_op(old, rr_count * 3);
	ft_replace_with_combined(new, "rr\n", rr_count);
}

/*
** @descr: Copies or skips the necessary rb into the new str.
*/

static void	ft_skip_rb(char **old, char **new, int rb_count, int rrb_ra_count)
{
	if (rb_count - rrb_ra_count > 0)
	{
		ft_copy_remaining_op(old, new, (rb_count - rrb_ra_count) * 3);
		ft_skip_mirrored_op(old, rrb_ra_count * 3);
	}
	else
		ft_skip_mirrored_op(old, rb_count * 3);
}

/*
** @descr: Shortens the rrb_ra_rb combinations fot all the possible \
** operation counts.
*/

int			ft_rrb_ra_rb_replace(char **old, char **new)
{
	int	rb_count;
	int	ra_count;
	int	rrb_count;
	int	temp_switch;

	rrb_count = ft_number_of_needles(*old, "rrb\n", 4);
	ra_count = ft_number_of_needles(*old + (rrb_count * 4), "ra\n", 3);
	rb_count = ft_number_of_needles(*old + (ra_count * 3 + rrb_count * 4), \
	"rb\n", 3);
	if (!rb_count || !ra_count || !rrb_count)
		return (0);
	temp_switch = ft_skip_rrb(old, new, rrb_count, rb_count);
	if (!temp_switch)
		ft_skip_ra(old, new, ra_count, rb_count - rrb_count);
	else
		ft_copy_remaining_op(old, new, ra_count * 3);
	ft_skip_rb(old, new, rb_count, rrb_count + ra_count);
	return (1);
}
