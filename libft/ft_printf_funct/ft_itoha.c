/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoha.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:56:34 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/15 14:27:56 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_itoha(unsigned int num, int cap)
{
	char	temp;
	char	*str;
	char	*hex;
	char	*hex1;
	char	*hex2;

	hex1 = "0123456789abcdef";
	hex2 = "0123456789ABCDEF";
	str = ft_strdup("");
	if (num == 0)
		return (ft_prefix_char('0', str));
	hex = hex1;
	if (cap)
		hex = hex2;
	while (num >= 1)
	{
		temp = hex[num % 16];
		str = ft_prefix_char(temp, str);
		num /= 16;
	}
	return (str);
}
