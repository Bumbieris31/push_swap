/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/02 21:33:17 by abumbier          #+#    #+#             */
/*   Updated: 2019/05/19 19:08:03 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_str(char *str, long long int n, int len)
{
	long long unsigned int	temp;

	if (str == NULL)
		return (NULL);
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

char		*ft_lltoa(long long int n)
{
	int			len;
	char		*str;

	if (n >= 0)
		len = ft_llintlen(n);
	else
		len = ft_llintlen(n) + 1;
	str = (char*)malloc(sizeof(char) * len + 1);
	return (ft_get_str(str, n, len));
}
