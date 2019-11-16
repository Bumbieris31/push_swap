/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/11 19:32:26 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/14 16:59:36 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_link;

	new_link = (t_list*)malloc(sizeof(*new_link));
	if (new_link == NULL)
		return (NULL);
	new_link->next = NULL;
	if (content == NULL)
	{
		new_link->content = NULL;
		new_link->content_size = 0;
	}
	else
	{
		new_link->content = malloc(sizeof(content_size));
		if (new_link->content == NULL)
			return (NULL);
		ft_memcpy(new_link->content, content, content_size);
		new_link->content_size = content_size;
	}
	return (new_link);
}
