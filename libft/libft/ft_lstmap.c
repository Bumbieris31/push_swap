/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/13 10:59:54 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/14 17:49:48 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*new_temp;

	if (lst == NULL)
		return (NULL);
	new_temp = f(lst);
	new_list = new_temp;
	while (lst->next)
	{
		lst = lst->next;
		new_temp->next = f(lst);
		if (new_temp->next == NULL)
		{
			free(new_temp->next);
			return (NULL);
		}
		new_temp = new_temp->next;
	}
	return (new_list);
}
