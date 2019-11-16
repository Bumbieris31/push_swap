/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 18:51:59 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/14 13:38:27 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_ptr(t_sbox *sb)
{
	char				*str;
	void				*ptr;
	unsigned long long	conv;

	ptr = va_arg(sb->ap, void*);
	if (sb->pre != 0)
	{
		conv = (unsigned long long)ptr;
		str = ft_lltoha(conv, 0);
		sb->temp_str = ft_stradd(sb->temp_str, str);
		ft_strdel(&str);
	}
	sb->temp_str = ft_prefix_str(sb->temp_str, "0x");
	return (ST_FIN);
}
