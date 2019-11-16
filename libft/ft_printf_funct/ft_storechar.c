/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storechar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 14:19:25 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/15 14:28:33 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_store_char(t_sbox *sb)
{
	char	*str;

	str = 0;
	while (sb->str[sb->ind] && sb->str[sb->ind] != '%')
	{
		str = ft_strcadd(str, sb->str[sb->ind]);
		sb->ind++;
	}
	if (str != 0)
	{
		ft_put_ret_str(str);
		sb->ret_len += ft_strlen(str);
	}
	if (str)
		free(str);
}
