/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 18:49:03 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/07 16:27:36 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_short_str(t_sbox *sb)
{
	char	*temp;

	temp = ft_strsub(sb->temp_str, 0, sb->pre);
	ft_strdel(&sb->temp_str);
	sb->temp_str = temp;
}

int			ft_str(t_sbox *sb)
{
	char	*str;

	str = va_arg(sb->ap, char*);
	if (str == 0)
		sb->temp_str = ft_stradd(sb->temp_str, "(null)");
	else
	{
		sb->temp_str = ft_stradd(sb->temp_str, str);
		if (sb->pre >= 0 && sb->pre < (int)ft_strlen(sb->temp_str))
			ft_short_str(sb);
	}
	sb->pre = -1;
	return (ST_FIN);
}
