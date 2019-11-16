/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:53:31 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/07 16:39:17 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

long int	ft_atoli(const char *str)
{
	int				i;
	int				sign;
	long int		nbr;

	nbr = 0;
	i = 0;
	sign = 1;
	if (!str[i])
		return (0);
	while (str[i] == '\f' || str[i] == '\v' || str[i] == ' ' \
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = 10 * nbr + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

/*
** @descr: Checks if the number represented in a string is an integer.
** @param: char *str - has to contain characters that represent numbers.
** @ret: returns 1 if str contains int. Otherwise returns 0.
*/

int			ft_isint(char *str)
{
	int		i;
	int		j;
	long	temp;

	i = 0;
	while (str[i] && str[i] == 0)
		i++;
	j = i;
	while (str[j] && ft_isdigit(str[j]))
		j++;
	if (j - i > 11)
		return (0);
	temp = ft_atoli(str);
	if (temp > 2147483647 || temp < -2147483648)
		return (0);
	return (1);
}
