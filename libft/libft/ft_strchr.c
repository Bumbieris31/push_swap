/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:17:21 by abumbier          #+#    #+#             */
/*   Updated: 2019/03/21 20:07:48 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;
	char	*str;

	i = 0;
	ch = c;
	str = (char*)s;
	while (s[i])
	{
		if (str[i] == ch)
		{
			return (&str[i]);
		}
		i++;
	}
	if (s[i] == c)
		return (&str[i]);
	return (NULL);
}
