/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_arg_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 21:45:50 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/02 19:14:13 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

/*
** @descr: Calculates the argc for the push_swap flags.
*/

int	ft_int_arg_count1(int flags, int argc)
{
	if (flags == ALL_FLAGS)
		argc -= 3;
	else if (flags != STATE && flags > 2)
		argc -= 2;
	else
		argc--;
	return (argc);
}
