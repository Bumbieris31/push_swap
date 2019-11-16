/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/04 16:02:50 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/13 19:48:58 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned	i;
	char		*str;

	i = 0;
	if (s != NULL && f != NULL)
	{
		str = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (str != NULL)
		{
			while (s[i])
			{
				str[i] = f(i, s[i]);
				i++;
			}
			str[i] = '\0';
			return (str);
		}
	}
	return (NULL);
}
