/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_point_left.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 12:10:15 by abumbier          #+#    #+#             */
/*   Updated: 2019/05/17 14:26:15 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

float	ft_move_point_left(float fl, int len)
{
	int		i;
	float	mult;

	i = 1;
	mult = 1;
	while (i <= len)
	{
		mult /= 10;
		i++;
	}
	fl *= mult;
	return (fl);
}
