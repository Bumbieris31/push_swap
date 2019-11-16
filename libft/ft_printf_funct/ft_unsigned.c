/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 18:49:24 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/08 18:10:35 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_unsigned(t_sbox *sb)
{
	char	*str;

	str = ft_utoa(va_arg(sb->ap, unsigned));
	sb->temp_str = ft_stradd(sb->temp_str, str);
	ft_strdel(&str);
	sb->plu = 0;
	sb->spe = 0;
	ft_precision(sb);
	return (ST_FIN);
}

int	ft_unsignedll(t_sbox *sb)
{
	char	*str;

	str = ft_llutoa(va_arg(sb->ap, unsigned long long));
	sb->temp_str = ft_stradd(sb->temp_str, str);
	ft_strdel(&str);
	sb->plu = 0;
	sb->spe = 0;
	ft_precision(sb);
	return (ST_FIN);
}

int	ft_unsignedl(t_sbox *sb)
{
	char	*str;

	str = ft_llutoa(va_arg(sb->ap, unsigned long));
	sb->temp_str = ft_stradd(sb->temp_str, str);
	ft_strdel(&str);
	sb->plu = 0;
	sb->spe = 0;
	ft_precision(sb);
	return (ST_FIN);
}
