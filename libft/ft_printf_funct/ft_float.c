/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:09:33 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/17 16:40:55 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_add_difference(t_sbox *sb, int pre, long double num)
{
	long long	temp;

	while (pre > 0)
	{
		sb->temp_str = ft_strcadd(sb->temp_str, '0');
		pre--;
	}
	if (sb->has == 1)
	{
		temp = num;
		num = num - temp;
		if (num > 0)
			sb->temp_str = ft_strcadd(sb->temp_str, '.');
	}
}

static int	ft_precision_fix(t_sbox *sb)
{
	int	temp_pre;

	temp_pre = sb->pre - 19;
	if (sb->pre == -1)
		sb->pre = 6;
	else if (sb->pre > 19)
		sb->pre = 19;
	return (temp_pre);
}

int			ft_double(t_sbox *sb)
{
	int		temp_pre;
	char	*num_str;
	double	num;

	temp_pre = ft_precision_fix(sb);
	num = va_arg(sb->ap, double);
	num_str = ft_ldtoa(num, sb->pre);
	sb->temp_str = ft_stradd(sb->temp_str, num_str);
	ft_add_difference(sb, temp_pre, num);
	ft_negative(sb);
	ft_strdel(&num_str);
	return (ST_FIN);
}

int			ft_ldouble(t_sbox *sb)
{
	int			temp_pre;
	char		*num_str;
	long double	num;

	temp_pre = ft_precision_fix(sb);
	num = va_arg(sb->ap, long double);
	num_str = ft_ldtoa(num, sb->pre);
	sb->temp_str = ft_stradd(sb->temp_str, num_str);
	ft_add_difference(sb, temp_pre, num);
	ft_negative(sb);
	ft_strdel(&num_str);
	return (ST_FIN);
}
