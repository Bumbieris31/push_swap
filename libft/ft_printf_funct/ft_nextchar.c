/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:17:01 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/15 14:28:33 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** descr - Functions read the next char and returns event.
*/

static int	ft_next_char_continue(t_sbox *sb)
{
	if (sb->str[sb->ind] == 'p')
		return (EV_PTR);
	else if (sb->str[sb->ind] == 'f')
		return (EV_FLOAT);
	else if (sb->str[sb->ind] == 'c')
		return (EV_CHAR);
	else if (sb->str[sb->ind] == 'o')
		return (EV_OCT);
	else if (sb->str[sb->ind] == 'x' || sb->str[sb->ind] == 'X')
		return (EV_HEX);
	else if (sb->str[sb->ind] == 'u')
		return (EV_UNS);
	else if (sb->str[sb->ind] == '\0')
		return (EV_TERM);
	else
		return (EV_WC);
}

int			ft_next_char(t_sbox *sb)
{
	sb->ind++;
	if (sb->str[sb->ind] == '%')
		return (EV_PERCENT);
	else if (sb->str[sb->ind] == 'd' || sb->str[sb->ind] == 'i')
		return (EV_INT);
	else if (sb->str[sb->ind] == 's')
		return (EV_STR);
	else if (sb->str[sb->ind] == '+' || sb->str[sb->ind] == '0' ||\
	sb->str[sb->ind] == ' ' || sb->str[sb->ind] == '-' ||\
	sb->str[sb->ind] == '#' || sb->str[sb->ind] == '.' ||\
	(sb->str[sb->ind] >= '0' && sb->str[sb->ind] <= '9'))
		return (EV_FLAG);
	else if (sb->str[sb->ind] == 'h' || sb->str[sb->ind] == 'l'\
	|| sb->str[sb->ind] == 'L')
		return (EV_LS);
	else
		return (ft_next_char_continue(sb));
}
