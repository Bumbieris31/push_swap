/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 12:29:16 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/08 17:28:13 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_add_diference(t_sbox *sb, int len)
{
	int	dif;
	int	neg;

	neg = 0;
	dif = sb->pre - len;
	if (sb->temp_str[0] == '-')
	{
		sb->temp_str[0] = '0';
		dif--;
		neg = 1;
	}
	while (dif > 0)
	{
		sb->temp_str = ft_prefix_char('0', sb->temp_str);
		dif--;
	}
	if (neg)
		sb->temp_str = ft_prefix_char('-', sb->temp_str);
}

void		ft_precision(t_sbox *sb)
{
	int	len;

	len = ft_strlen(sb->temp_str);
	if (sb->temp_str[0] == '-')
		len--;
	if (sb->pre >= 0)
	{
		sb->zer = 0;
		if (sb->pre > len)
			ft_add_diference(sb, len);
	}
}
