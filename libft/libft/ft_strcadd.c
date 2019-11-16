/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 14:23:51 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/14 13:08:12 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @desc: Adds the char at the end of the string and returns the string as\
** a substitution for the s1.
** Function creates a new string if the s1 is NULL.
*/

static char	*ft_create_new(char c)
{
	char	*str;

	str = (char*)malloc(2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char		*ft_strcadd(char *s1, char c)
{
	int		i;
	int		len;
	char	*str;
	char	*str_temp;

	i = 0;
	len = 0;
	if (s1 == NULL)
		return (ft_create_new(c));
	str_temp = ft_strdup(s1);
	if (s1 != NULL)
		ft_strdel(&s1);
	str = (char*)malloc(sizeof(char) * ft_strlen(str_temp) + 2);
	if (str == NULL)
		return (NULL);
	while (str_temp[len])
	{
		str[len] = str_temp[len];
		len++;
	}
	str[len] = c;
	str[len + 1] = '\0';
	ft_strdel(&str_temp);
	return (str);
}
