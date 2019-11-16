/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 11:50:33 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/11 19:50:44 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	ch;
	char			*str;

	i = 0;
	ch = c;
	str = b;
	while (i < len)
	{
		*str = ch;
		str++;
		i++;
	}
	return (b);
}
