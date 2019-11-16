/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsub.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/02 11:39:21 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/13 19:52:29 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	unsigned	i;

	i = 0;
	str = (char*)malloc(sizeof(char) * len + 1);
	if (str == NULL || s == NULL)
		return (NULL);
	else
	{
		while (i < len && s[start])
		{
			str[i] = s[start];
			i++;
			start++;
		}
		str[i] = '\0';
		return (str);
	}
}
