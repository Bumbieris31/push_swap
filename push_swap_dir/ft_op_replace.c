/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_replace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 19:05:33 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/13 21:00:56 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: copies new string (size of count) into the empty buffer str.
*/

void	ft_replace_with_combined(char **new, const char *str, int count)
{
	int	len;

	len = ft_strlen(str);
	while (count > 0)
	{
		ft_memcpy(*new, str, len);
		*new = *new + len;
		count--;
	}
}

/*
** @descr: replaces ra and rb operation combinations with rr.
** @var: ra_count and rb_count do not advance index in old. Thats why the \
** the second call of ft_number_of_needles is *old is advanced (ra_count * 3) \
** spaces further.
** @var: del holds the amount of combinations required to replace.
*/

int		ft_ra_rb_replace(char **old, char **new)
{
	int	del;
	int	ra_count;
	int	rb_count;

	ra_count = ft_number_of_needles(*old, "ra\n", 3);
	if (ra_count == 0)
		return (0);
	rb_count = ft_number_of_needles(*old + (ra_count * 3), "rb\n", 3);
	if (rb_count == 0)
		return (0);
	del = (ra_count < rb_count ? ra_count : rb_count);
	if (ra_count > rb_count)
		ft_copy_remaining_op(old, new, (ra_count - rb_count) * 3);
	ft_skip_mirrored_op(old, del * 6);
	ft_replace_with_combined(new, "rr\n", del);
	return (1);
}

int		ft_rb_pb_rrb_replace(char **old, char **new)
{
	if (ft_strncmp(*old, "rb\npb\nrrb\n", 10) != 0)
		return (0);
	ft_skip_mirrored_op(old, 10);
	ft_replace_with_combined(new, "pb\nsb\n", 1);
	return (1);
}
