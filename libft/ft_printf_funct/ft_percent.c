/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:16:50 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/09 14:35:03 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_percent(t_sbox *sb)
{
	sb->spe = 0;
	sb->plu = 0;
	sb->has = 0;
	sb->temp_str = ft_strcadd(sb->temp_str, '%');
	return (ST_FIN);
}
