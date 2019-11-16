/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 14:45:18 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/13 19:34:01 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	ch;
	char	*s1;
	char	*s2;
	size_t	i;

	i = 0;
	ch = c;
	s1 = dst;
	s2 = (char *)src;
	while (i < n)
	{
		s1[i] = s2[i];
		if (s2[i] == ch)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
