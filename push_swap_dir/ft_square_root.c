/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_root.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 17:39:23 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/04 14:21:43 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @descr: computes the square root of a number and rounds it down \
** to a whole number.
*/

int		ft_square_root(int num)
{
	int	mid;
	int	low;
	int	old;
	int	high;
	int	precis;

	low = 0;
	mid = num;
	high = num;
	old = -1;
	precis = 1;
	while (precis >= 0.01)
	{
		old = mid;
		mid = (low + high) / 2;
		if (mid * mid > num)
			high = mid;
		else
			low = mid;
		precis = old - mid;
		if (precis < 0)
			precis *= -1;
	}
	return (mid);
}
