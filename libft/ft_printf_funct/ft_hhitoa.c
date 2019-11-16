/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hhitoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:47:09 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/16 16:13:17 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*get_str(char *str, char n, int len)
{
	unsigned char	temp;

	if (str == 0)
		return (0);
	else if (n < 0)
	{
		str[0] = '-';
		temp = n * -1;
	}
	else
		temp = n;
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (temp)
	{
		str[len - 1] = (temp % 10) + '0';
		temp /= 10;
		len--;
	}
	return (str);
}

char		*ft_hhitoa(char n)
{
	int			len;
	char		*str;

	if (n >= 0)
		len = ft_intlen(n);
	else
		len = ft_intlen(n) + 1;
	str = (char*)malloc(sizeof(char) * len + 1);
	return (get_str(str, n, len));
}
