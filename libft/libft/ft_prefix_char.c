/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:40:01 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/12 20:26:36 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Descr: Function returns replacement string for the str argument which\
** is substituted by assigning to the str variable a return value.\
** (In a similar manner as both ft_strcadd() and ft_stradd()).
*/

char	*ft_prefix_char(char c, char *str)
{
	int		len;
	char	*ret_str;

	len = 0;
	ret_str = 0;
	if (str)
	{
		len = ft_strlen(str);
		ret_str = ft_strdup(str);
		ft_strdel(&str);
	}
	str = (char*)malloc(len + 2);
	str[0] = c;
	str[len + 1] = '\0';
	if (ret_str)
	{
		ft_strncpy(str + 1, ret_str, len);
		ft_strdel(&ret_str);
	}
	return (str);
}
