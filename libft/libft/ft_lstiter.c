/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/12 18:16:54 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/12 18:22:18 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*d)(t_list *elem))
{
	t_list	*link;

	link = lst;
	while (lst != NULL)
	{
		d(lst);
		lst = lst->next;
	}
}
