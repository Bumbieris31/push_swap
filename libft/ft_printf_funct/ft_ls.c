/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 14:20:23 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/09 14:45:26 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_ls(t_sbox *sb)
{
	if (sb->str[sb->ind] == 'L')
		sb->ld = 1;
	else if (sb->str[sb->ind] == 'l')
		sb->l = 1;
	else if (sb->str[sb->ind] == 'h')
		sb->h = 1;
	return (ST_LS);
}

int	ft_update_ls(t_sbox *sb)
{
	if (sb->str[sb->ind] == 'l')
	{
		if (sb->str[sb->ind - 1] == 'l')
		{
			sb->l = 0;
			sb->ll = 1;
		}
		else
			return (ST_WC);
	}
	if (sb->str[sb->ind] == 'h')
	{
		if (sb->str[sb->ind - 1] == 'h')
		{
			sb->h = 0;
			sb->hh = 1;
		}
		else
			return (ST_WC);
	}
	return (ST_LS);
}
