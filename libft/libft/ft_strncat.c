/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/30 13:45:26 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/13 17:52:26 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		len;
	size_t		len2;

	i = 0;
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (*(s2 + i) && i < n)
	{
		*(s1 + len) = *(s2 + i);
		len++;
		i++;
	}
	*(s1 + len) = '\0';
	return (s1);
}
