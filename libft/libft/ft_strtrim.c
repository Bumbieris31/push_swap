/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 19:13:48 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/13 19:53:15 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	trim_begin(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	return (i);
}

static int	trim_end(const char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i--;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	int		i[2];
	int		end;
	char	*str;

	if (s == NULL)
		return (NULL);
	i[1] = 0;
	i[0] = trim_begin(s);
	end = trim_end(s);
	if (i[0] == (int)ft_strlen(s))
	{
		str = ft_strdup("\0");
		return (str);
	}
	str = (char*)malloc(sizeof(char) * (end - i[0] + 2));
	if (str == NULL)
		return (NULL);
	while (i[0] <= end)
	{
		str[i[1]] = s[i[0]];
		i[1]++;
		i[0]++;
	}
	str[i[1]] = '\0';
	return (str);
}
