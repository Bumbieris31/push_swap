/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_point_right_ld.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:05:10 by abumbier          #+#    #+#             */
/*   Updated: 2019/05/19 19:01:20 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long double	ft_move_point_right_ld(long double fl, int len)
{
	int			i;
	long double	mult;

	i = 1;
	mult = 1;
	while (i <= len)
	{
		mult *= 10;
		i++;
	}
	fl *= mult;
	return (fl);
}
