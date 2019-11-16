/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorten_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:08:21 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/04 16:24:26 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: counts the amount of needles in a row in the heystack str.
*/

int		ft_number_of_needles(char *heystack, const char *needle, int len)
{
	int	i;

	i = 0;
	while (ft_strncmp(heystack, needle, len) == 0)
	{
		if ((heystack) + len)
			(heystack) = (heystack) + len;
		else
			return (i + 1);
		i++;
	}
	return (i);
}

/*
** @descr: skips unnecessary operations. Examp: rrb + rb => _
*/

void	ft_skip_mirrored_op(char **old, int count)
{
	*old = *old + count;
}

/*
** @descr: copies necessary operations. Examp: rrb + rrb + rb => rrb
*/

void	ft_copy_remaining_op(char **old, char **new, int count)
{
	ft_memcpy(*new, *old, count);
	*new = *new + count;
	*old = *old + count;
}

/*
** @descr: shortens opperation string removing unnecesary operations.
*/

char	*ft_shorten_str(char **old)
{
	int		i;
	char	*new;
	char	*ret;

	new = (char*)malloc(ft_strlen(*old));
	ret = new;
	i = 0;
	while (**old != '\0')
	{
		if (!ft_rrb_ra_rb_replace(old, &new) && !ft_rrb_rb_delete(old, &new) \
		&& !ft_pb_pa_delete(old, &new) && !ft_ra_rb_replace(old, &new) \
		&& !ft_ra_rra_delete(old, &new) && !ft_rb_pb_rrb_replace(old, &new))
			ft_copy_unshortened(old, &new);
	}
	*new = '\0';
	return (ret);
}
