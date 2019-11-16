/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 13:04:35 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/08 15:26:38 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_hash_flag(t_sbox *sb)
{
	if (sb->has == 2)
		sb->temp_str = ft_prefix_str(sb->temp_str, "0x");
	else if (sb->has == 3)
		sb->temp_str = ft_prefix_str(sb->temp_str, "0X");
}

static void	ft_hash_condition(t_sbox *sb)
{
	if (sb->str[sb->ind] == 'x')
		sb->has = 2;
	else if (sb->str[sb->ind] == 'X')
		sb->has = 3;
	if (sb->zer != 1 || sb->wid <= (int)ft_strlen(sb->temp_str))
	{
		ft_hash_flag(sb);
		sb->has = 0;
	}
}

int			ft_hexadec(t_sbox *sb)
{
	int		cap;
	char	*str;

	cap = 0;
	if (sb->str[sb->ind] == 'X')
		cap = 1;
	str = ft_itoha(va_arg(sb->ap, unsigned), cap);
	if (sb->pre == 0 && str[0] == '0')
	{
		str[0] = '\0';
		sb->has = 0;
	}
	sb->temp_str = ft_stradd(sb->temp_str, str);
	ft_strdel(&str);
	if (sb->temp_str[0] == '0')
		sb->has = 0;
	ft_precision(sb);
	if (sb->has == 1)
		ft_hash_condition(sb);
	sb->spe = 0;
	return (ST_FIN);
}

int			ft_llhexadec(t_sbox *sb)
{
	int		cap;
	char	*str;

	cap = 0;
	if (sb->str[sb->ind] == 'X')
		cap = 1;
	str = ft_lltoha(va_arg(sb->ap, unsigned long long), cap);
	if (sb->pre == 0 && str[0] == '0')
	{
		str[0] = '\0';
		sb->has = 0;
	}
	sb->temp_str = ft_stradd(sb->temp_str, str);
	ft_strdel(&str);
	if (sb->temp_str[0] == '0')
		sb->has = 0;
	ft_precision(sb);
	if (sb->has == 1)
		ft_hash_condition(sb);
	sb->spe = 0;
	return (ST_FIN);
}

int			ft_lhexadec(t_sbox *sb)
{
	int		cap;
	char	*str;

	cap = 0;
	if (sb->str[sb->ind] == 'X')
		cap = 1;
	str = ft_lltoha(va_arg(sb->ap, unsigned long), cap);
	if (sb->pre == 0 && str[0] == '0')
	{
		str[0] = '\0';
		sb->has = 0;
	}
	sb->temp_str = ft_stradd(sb->temp_str, str);
	ft_strdel(&str);
	if (sb->temp_str[0] == '0')
		sb->has = 0;
	ft_precision(sb);
	if (sb->has == 1)
		ft_hash_condition(sb);
	sb->spe = 0;
	return (ST_FIN);
}
