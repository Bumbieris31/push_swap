/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 20:09:47 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/14 18:19:47 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static float	ft_round_frac(float fl, int len)
{
	int		temp;
	float	new;
	float	incr;

	new = ft_move_point_right(fl, len);
	temp = (long int)new;
	incr = (new - temp) * 10;
	if (incr > 5.0)
	{
		incr = 1;
		fl += ft_move_point_left(incr, len);
	}
	return (fl);
}

static float	ft_round_nat(float fl)
{
	int		num;
	float	temp_fl;

	temp_fl = fl;
	num = (int)fl;
	temp_fl -= (float)num;
	temp_fl *= 10;
	if (temp_fl >= 5.0)
		return (fl + 1);
	return (fl);
}

static char		*ft_get_str(float fl, int len)
{
	int		i;
	int		num;
	char	*str;
	char	*temp;

	num = (int)fl;
	str = ft_itoa(num);
	if (len > 0)
	{
		str = ft_strcadd(str, '.');
		fl -= (float)num;
		if (fl < 0)
			fl *= -1;
		fl = ft_move_point_right(fl, len) + 0.5;
		temp = ft_itoa((int)fl);
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

char			*ft_ftoa(float fl, int len)
{
	if (len > 0)
		fl = ft_round_frac(fl, len);
	else
		fl = ft_round_nat(fl);
	return (ft_get_str(fl, len));
}
