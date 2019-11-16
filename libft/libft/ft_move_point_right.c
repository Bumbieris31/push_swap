/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_point_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:05:10 by abumbier          #+#    #+#             */
/*   Updated: 2019/05/17 14:26:00 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_move_point_right(float fl, int len)
{
	int	i;
	int	mult;

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
