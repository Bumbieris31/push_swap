/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltooa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 14:55:47 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/15 14:27:56 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_lltooa(unsigned long long num)
{
	char	temp;
	char	*str;

	str = ft_strdup("");
	if (num == 0)
		return (ft_prefix_char('0', str));
	while (num >= 1)
	{
		temp = '0' + (num % 8);
		str = ft_prefix_char(temp, str);
		num /= 8;
	}
	return (str);
}
