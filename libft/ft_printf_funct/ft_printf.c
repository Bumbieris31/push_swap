/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:14:28 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/16 16:16:32 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_make_transitions(t_transition **ptr)
{
	static t_transition trans[] = {{ST_INIT, EV_PERCENT, &ft_percent},
		{ST_WC, EV_PERCENT, &ft_percent},
		{ST_FIN, EV_TERM, &ft_fin},
		{ST_WC, EV_FLAG, &ft_flag},
		{ST_LS, EV_LS, &ft_update_ls}, {ST_WC, EV_LS, &ft_ls},
		{ST_LS, EV_INT, &ft_conv}, {ST_WC, EV_INT, &ft_int},
		{ST_LS, EV_FLOAT, &ft_conv}, {ST_WC, EV_FLOAT, &ft_double},
		{ST_LS, EV_OCT, &ft_conv}, {ST_WC, EV_OCT, &ft_octal},
		{ST_WC, EV_CHAR, &ft_char},
		{ST_LS, EV_UNS, &ft_conv}, {ST_WC, EV_UNS, &ft_unsigned},
		{ST_LS, EV_HEX, &ft_conv}, {ST_WC, EV_HEX, &ft_hexadec},
		{ST_WC, EV_PTR, &ft_ptr},
		{ST_WC, EV_STR, &ft_str},
		{ST_WC, EV_TERM, &ft_fin},
		{ST_WC, EV_WC, &ft_error}
		};

	*ptr = trans;
}

t_sbox	*ft_make_struct(char const *str)
{
	t_sbox	*sb;

	sb = (t_sbox*)malloc(sizeof(t_sbox));
	sb->ind = 0;
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
	sb->nul = 0;
	sb->ret_len = 0;
	sb->trans = 0;
	sb->temp_str = 0;
	sb->str = ft_strdup(str);
	sb->ret_str = 0;
	return (sb);
}

void	ft_free_struct(t_sbox *sb)
{
	ft_strdel(&sb->ret_str);
	ft_strdel(&sb->temp_str);
	ft_strdel(&sb->str);
	free(sb);
}

void	ft_put_ret_str(char *s)
{
	int	i;

	i = 0;
	if (s != 0)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

int		ft_printf(const char *str, ...)
{
	char			len;
	static t_sbox	*sb;

	sb = ft_make_struct(str);
	va_start(sb->ap, str);
	ft_make_transitions(&(sb->trans));
	while (str[sb->ind])
	{
		ft_store_char(sb);
		if (str[sb->ind])
		{
			ft_fsm(sb);
			sb->ind++;
		}
	}
	va_end(sb->ap);
	len = sb->ret_len;
	ft_free_struct(sb);
	return (len);
}
