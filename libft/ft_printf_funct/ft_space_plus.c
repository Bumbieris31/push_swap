/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_plus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:42:12 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/17 16:09:57 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** @desc: Adds space and/or plus before the number based on flags.
*/

int		ft_space(t_sbox *sb)
{
	sb->temp_str = ft_prefix_char(' ', sb->temp_str);
	return (0);
}

int		ft_plus(t_sbox *sb)
{
	int		i;

	i = 0;
	while (sb->temp_str[i] == ' ')
		i++;
	if (i == 0)
		sb->temp_str = ft_prefix_char('+', sb->temp_str);
	else
	{
		sb->temp_str[i - 1] = '+';
		sb->temp_str = ft_prefix_char(' ', sb->temp_str);
	}
	return (0);
}

void	ft_negative(t_sbox *sb)
{
	if (sb->temp_str[0] == '-')
	{
		sb->spe = 0;
		sb->plu = 0;
	}
}
