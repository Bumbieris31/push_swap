/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 16:32:09 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/09 14:43:15 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	ft_int_conv(t_sbox *sb)
{
	if (sb->l == 1)
		ft_lint(sb);
	else if (sb->ll == 1)
		ft_llint(sb);
	else if (sb->h == 1)
		ft_hint(sb);
	else if (sb->hh == 1)
		ft_hhint(sb);
}

static void	ft_unsign_conv(t_sbox *sb)
{
	if (sb->l == 1)
		ft_unsignedl(sb);
	else if (sb->ll == 1)
		ft_unsignedll(sb);
	else if (sb->h == 1)
		ft_unsigned(sb);
	else if (sb->hh == 1)
		ft_unsigned(sb);
}

static void	ft_hex_conv(t_sbox *sb)
{
	if (sb->l == 1)
		ft_lhexadec(sb);
	else if (sb->ll == 1)
		ft_llhexadec(sb);
	else if (sb->h == 1)
		ft_hexadec(sb);
	else if (sb->hh == 1)
		ft_hexadec(sb);
}

static void	ft_oct_conv(t_sbox *sb)
{
	if (sb->l == 1)
		ft_loctal(sb);
	else if (sb->ll == 1)
		ft_lloctal(sb);
	else if (sb->h == 1)
		ft_octal(sb);
	else if (sb->hh == 1)
		ft_octal(sb);
}

int			ft_conv(t_sbox *sb)
{
	if (sb->str[sb->ind] == 'd' || sb->str[sb->ind] == 'i')
		ft_int_conv(sb);
	else if (sb->str[sb->ind] == 'f')
	{
		if (sb->ld == 1)
			ft_ldouble(sb);
		else if (sb->l == 1)
			ft_double(sb);
	}
	else if (sb->str[sb->ind] == 'u')
		ft_unsign_conv(sb);
	else if (sb->str[sb->ind] == 'o')
		ft_oct_conv(sb);
	else if (sb->str[sb->ind] == 'x' || sb->str[sb->ind] == 'X')
		ft_hex_conv(sb);
	return (ST_FIN);
}
