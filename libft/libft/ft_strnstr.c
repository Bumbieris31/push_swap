/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 12:41:38 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/14 18:54:22 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hey, const char *nee, size_t len)
{
	char	*str1;
	char	*str2;
	size_t	i;

	str1 = (char*)hey;
	str2 = (char*)nee;
	i = 0;
	if (str2[0] == 0)
		return (str1);
	while ((i < len) && str1[i])
	{
		if (str1[i] == str2[0])
		{
			if (ft_strlen(str2) + i > len)
				return (NULL);
			if (ft_strncmp(&str1[i], &str2[0], ft_strlen(str2)) == 0)
				return (&str1[i]);
		}
		i++;
	}
	return (NULL);
}
