/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_data_structs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:37:16 by abumbier          #+#    #+#             */
/*   Updated: 2019/10/08 16:08:49 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: Deletes created data structures.
*/

void	ft_delete_data_structs(t_pls_box *pls_box, \
char **del_str, char **final_str)
{
	ft_strdel(del_str);
	ft_strdel(final_str);
	ft_delete_list(*pls_box->stack_a);
	ft_delete_list(*pls_box->sorted);
	free(pls_box);
}
