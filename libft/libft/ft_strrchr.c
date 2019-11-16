/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 10:55:55 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/13 19:51:46 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	ch = c;
	str = (char*)s;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (str[len - i] == ch)
			return (&str[len - i]);
		i++;
	}
	return (NULL);
}
