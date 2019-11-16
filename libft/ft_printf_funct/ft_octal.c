/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 18:02:22 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/07 16:20:16 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_octal(t_sbox *sb)
{
	int		len;
	char	*str;

	str = ft_itooa(va_arg(sb->ap, int));
	if (sb->pre == 0 && str[0] == '0')
		str[0] = '\0';
	sb->temp_str = ft_stradd(sb->temp_str, str);
	ft_strdel(&str);
	len = ft_strlen(sb->temp_str);
	if (sb->has == 1)
		if (sb->pre <= len)
			if (sb->temp_str[0] != '0')
				sb->temp_str = ft_prefix_char('0', sb->temp_str);
	if (sb->spe == 1)
		sb->spe = 0;
	ft_precision(sb);
	return (ST_FIN);
}

int	ft_lloctal(t_sbox *sb)
{
	int		len;
	char	*str;

	str = ft_lltooa(va_arg(sb->ap, unsigned long long));
	if (sb->pre == 0 && str[0] == '0')
		str[0] = '\0';
	sb->temp_str = ft_stradd(sb->temp_str, str);
	ft_strdel(&str);
	len = ft_strlen(sb->temp_str);
	if (sb->has == 1)
		if (sb->pre <= len)
			if (sb->temp_str[0] != '0')
				sb->temp_str = ft_prefix_char('0', sb->temp_str);
	if (sb->spe == 1)
		sb->spe = 0;
	ft_precision(sb);
	return (ST_FIN);
}

int	ft_loctal(t_sbox *sb)
{
	int		len;
	char	*str;

	str = ft_lltooa(va_arg(sb->ap, unsigned long));
	if (sb->pre == 0 && str[0] == '0')
		str[0] = '\0';
	sb->temp_str = ft_stradd(sb->temp_str, str);
	ft_strdel(&str);
	len = ft_strlen(sb->temp_str);
	if (sb->has == 1)
		if (sb->pre <= len)
			if (sb->temp_str[0] != '0')
				sb->temp_str = ft_prefix_char('0', sb->temp_str);
	if (sb->spe == 1)
		sb->spe = 0;
	ft_precision(sb);
	return (ST_FIN);
}
