/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:05:12 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/14 13:10:07 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** @desc: Checks if flags apply, then adds temp_str of respective % to the \
** ret_str. Resets the flags to their original state.
*/

void		ft_reset_flag(t_sbox *sb)
{
	sb->min = 0;
	sb->wid = 0;
	sb->pre = -1;
	sb->has = 0;
	sb->plu = 0;
	sb->zer = 0;
	sb->spe = 0;
	sb->l = 0;
	sb->ll = 0;
	sb->h = 0;
	sb->hh = 0;
	sb->ld = 0;
}

void		ft_check_flags(t_sbox *sb)
{
	if (sb->wid > 0)
		ft_width(sb);
	if (sb->has > 0)
		ft_hash_flag(sb);
	if (sb->spe == 1)
		ft_space(sb);
	if (sb->plu == 1)
		ft_plus(sb);
}

int			ft_fin(t_sbox *sb)
{
	ft_check_flags(sb);
	ft_put_ret_str(sb->temp_str);
	if (sb->nul == 1)
		ft_putchar(0);
	if (sb->temp_str)
		sb->ret_len += ft_strlen(sb->temp_str);
	ft_strdel(&sb->temp_str);
	sb->temp_str = ft_strdup("");
	ft_reset_flag(sb);
	return (ST_TERM);
}
