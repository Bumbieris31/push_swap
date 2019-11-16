/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fsm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:16:55 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/15 14:27:56 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_incr(t_sbox *sb, int state)
{
	if (state == ST_FIN)
		return (EV_TERM);
	return (ft_next_char(sb));
}

int			ft_fsm(t_sbox *sb)
{
	int	i;
	int	state;
	int	event;

	i = 0;
	state = ST_INIT;
	while (state != ST_TERM)
	{
		event = ft_incr(sb, state);
		while (1)
		{
			if (state == sb->trans[i].st || ST_WC == sb->trans[i].st)
			{
				if (event == sb->trans[i].ev || EV_WC == sb->trans[i].ev)
				{
					state = (sb->trans[i].fn)(sb);
					i = 0;
					break ;
				}
			}
			i++;
		}
	}
	return (state);
}
