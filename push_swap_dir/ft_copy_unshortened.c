/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_unshortened.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:47:36 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/01 18:51:19 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: copies the next operation from old str in to the new str.
*/

void	ft_copy_unshortened(char **old, char **new)
{
	while (**old)
	{
		if (**old == '\n')
		{
			**new = **old;
			(*new)++;
			(*old)++;
			break ;
		}
		**new = **old;
		(*new)++;
		(*old)++;
	}
}
