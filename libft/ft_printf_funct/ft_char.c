/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:56:59 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/12 20:20:20 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_char(t_sbox *sb)
{
	char	c;

	c = va_arg(sb->ap, int);
	if (c == 0)
	{
		sb->ret_len += 1;
		if (sb->min == 1)
			ft_putchar(c);
		else if (sb->wid <= 1)
			ft_putchar(c);
		else
			sb->nul = 1;
		if (sb->wid > 1)
			sb->wid--;
	}
	else
		sb->temp_str = ft_strcadd(sb->temp_str, c);
	return (ST_FIN);
}
