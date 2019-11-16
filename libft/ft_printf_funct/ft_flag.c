/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:31:04 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/06 12:26:57 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_prec_and_width(t_sbox *sb)
{
	if (sb->str[sb->ind] == '.')
	{
		if (!(sb->str[sb->ind + 1] >= '0' && sb->str[sb->ind + 1] <= '9'))
			sb->pre = 0;
		else
		{
			sb->pre = ft_atoi(&sb->str[sb->ind + 1]);
			sb->ind += ft_intlen(sb->pre);
		}
	}
	else if (sb->str[sb->ind] > '0' && sb->str[sb->ind] <= '9')
	{
		sb->wid = ft_atoi(&sb->str[sb->ind]);
		sb->ind += ft_intlen(sb->wid) - 1;
	}
}

int			ft_flag(t_sbox *sb)
{
	if (sb->str[sb->ind] == '+')
	{
		sb->plu = 1;
		sb->spe = 0;
	}
	else if (sb->str[sb->ind] == '0')
	{
		if (sb->min == 0)
			sb->zer = 1;
	}
	else if (sb->str[sb->ind] == ' ')
	{
		if (sb->plu != 1)
			sb->spe = 1;
	}
	else if (sb->str[sb->ind] == '-')
	{
		sb->min = 1;
		sb->zer = 0;
	}
	else if (sb->str[sb->ind] == '#')
		sb->has = 1;
	else
		ft_prec_and_width(sb);
	return (ST_FLAG);
}
