/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag_output.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 19:14:35 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/02 22:04:37 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: Checks if failed instruction is push_swap flag output.
*/

int	ft_check_flag_output(char *str)
{
	if (ft_strstr(str, " points") != 0)
		return (1);
	else if (ft_strequ(str, "No instruction limit for this amount of inputs!"))
		return (1);
	else if (ft_strstr(str, "Instruction count: ") != 0)
		return (1);
	return (0);
}
