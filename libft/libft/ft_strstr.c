/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/31 11:10:43 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/13 19:52:08 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *heystack, const char *needle)
{
	int		i;
	char	*str1;
	char	*str2;

	str1 = (char*)heystack;
	str2 = (char*)needle;
	i = 0;
	if (str2[0] == 0)
		return (str1);
	while (str1[i])
	{
		if (str1[i] == str2[0])
		{
			if (ft_strncmp(&str1[i], &str2[0], ft_strlen(str2)) == 0)
				return (&str1[i]);
		}
		i++;
	}
	return (NULL);
}
