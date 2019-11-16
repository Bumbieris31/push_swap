/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strclr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/01 14:45:59 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/11 19:54:00 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int	len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		ft_bzero(s, len);
	}
}
