/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 17:10:49 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/25 17:04:32 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double	ft_round_frac(long double fl, int len)
{
	long long int	temp;
	long double		new;
	long double		incr;

	new = ft_move_point_right_ld(fl, len);
	temp = (long long int)new;
	incr = (new - temp) * 10;
	if (incr > 5.0)
	{
		incr = 1;
		fl += ft_move_point_left_ld(incr, len);
	}
	return (fl);
}

static long double	ft_round_nat(long double fl)
{
	long long int	num;
	long double		temp_fl;

	temp_fl = fl;
	num = (long long int)fl;
	temp_fl -= (long double)num;
	temp_fl *= 10;
	if (temp_fl >= 5.0)
		return (fl + 1);
	return (fl);
}

static char			*ft_get_str(long double fl, int len)
{
	int				i;
	long long int	num;
	char			*str;
	char			*temp;

	num = (long long int)fl;
	str = ft_lltoa(num);
	if (len > 0)
	{
		str = ft_strcadd(str, '.');
		fl -= (long double)num;
		if (fl < 0)
			fl *= -1;
		fl = ft_move_point_right_ld(fl, len);
		temp = ft_lltoa((long long int)fl);
		str = ft_stradd(str, temp);
		i = ft_strlen(temp);
		while (i < len)
		{
			str = ft_strcadd(str, '0');
			i++;
		}
		ft_strdel(&temp);
	}
	return (str);
}

char				*ft_ldtoa(long double fl, int len)
{
	char	*str;

	if (len > 0)
		fl = ft_round_frac(fl, len);
	else
		fl = ft_round_nat(fl);
	str = ft_get_str(fl, len);
	return (str);
}
