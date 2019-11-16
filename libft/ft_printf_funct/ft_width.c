/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 20:12:44 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/12 19:56:27 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_add_width(t_sbox *sb, char *str, int add)
{
	char	ch;

	ch = ' ';
	if (sb->zer == 1)
		ch = '0';
	if (sb->temp_str[0] == '-' && sb->zer == 1)
	{
		str[0] = '-';
		ft_memset(&str[1], ch, add - 1);
		sb->temp_str[0] = '0';
	}
	else
		ft_memset(str, ch, add);
	str[add] = '\0';
	if (sb->min == 1)
		sb->temp_str = ft_stradd(sb->temp_str, str);
	else
		sb->temp_str = ft_prefix_str(sb->temp_str, str);
}

int			ft_width(t_sbox *sb)
{
	int		len;
	int		add;
	char	*str;

	if (!sb->temp_str)
		sb->temp_str = ft_strdup("");
	len = ft_strlen(sb->temp_str);
	if (sb->has > 1)
		len += 2;
	if (len < sb->wid)
	{
		add = sb->wid - len;
		if (sb->spe == 1 || sb->plu == 1)
			add -= 1;
		str = (char*)malloc(add + 1);
		ft_add_width(sb, str, add);
		ft_strdel(&str);
		return (1);
	}
	return (0);
}
