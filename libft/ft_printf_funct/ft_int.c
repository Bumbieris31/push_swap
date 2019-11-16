/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 15:41:56 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/17 16:11:30 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_int(t_sbox *sb)
{
	char	*str;

	str = ft_itoa(va_arg(sb->ap, int));
	if (sb->pre == 0 && str[0] == '0')
		str[0] = '\0';
	sb->temp_str = ft_stradd(sb->temp_str, str);
	ft_strdel(&str);
	ft_negative(sb);
	ft_precision(sb);
	return (ST_FIN);
}

int	ft_llint(t_sbox *sb)
{
	char	*str;

	str = ft_lltoa(va_arg(sb->ap, long long));
	if (sb->pre == 0 && str[0] == '0')
		str[0] = '\0';
	sb->temp_str = ft_stradd(sb->temp_str, str);
	ft_strdel(&str);
	ft_negative(sb);
	ft_precision(sb);
	return (ST_FIN);
}

int	ft_lint(t_sbox *sb)
{
	char	*str;

	str = ft_lltoa(va_arg(sb->ap, long));
	if (sb->pre == 0 && str[0] == '0')
		str[0] = '\0';
	sb->temp_str = ft_stradd(sb->temp_str, str);
	ft_strdel(&str);
	ft_negative(sb);
	ft_precision(sb);
	return (ST_FIN);
}

int	ft_hhint(t_sbox *sb)
{
	char	*str;

	str = ft_hhitoa(va_arg(sb->ap, int));
	if (sb->pre == 0 && str[0] == '0')
		str[0] = '\0';
	sb->temp_str = ft_stradd(sb->temp_str, str);
	ft_strdel(&str);
	ft_negative(sb);
	ft_precision(sb);
	return (ST_FIN);
}

int	ft_hint(t_sbox *sb)
{
	char	*str;

	str = ft_hitoa(va_arg(sb->ap, int));
	if (sb->pre == 0 && str[0] == '0')
		str[0] = '\0';
	sb->temp_str = ft_stradd(sb->temp_str, str);
	ft_strdel(&str);
	ft_negative(sb);
	ft_precision(sb);
	return (ST_FIN);
}
