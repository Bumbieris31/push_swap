/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 13:06:17 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/13 18:41:49 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Descr: Function returns replacement string for the post argument which\
** is substituted by assigning to the post variable a return value.\
** (In a similar manner as both ft_strcadd() and ft_stradd()).
*/

char		*ft_prefix_str(char *post, char *pre)
{
	int		len1;
	int		len2;
	char	*temp;

	if (!post)
		post = ft_strdup(pre);
	else
	{
		len1 = ft_strlen(pre);
		len2 = ft_strlen(post);
		temp = ft_strjoin(pre, post);
		ft_strdel(&post);
		post = temp;
	}
	return (post);
}
