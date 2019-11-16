/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 18:04:53 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/11 19:52:28 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char		c;
	unsigned	temp;

	if (n < 0)
	{
		write(1, "-", 1);
		temp = n * -1;
	}
	else
		temp = n;
	if (temp < 10)
	{
		c = '0' + temp;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(temp / 10);
		ft_putnbr(temp % 10);
	}
}
