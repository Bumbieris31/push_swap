/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 16:16:44 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/17 16:10:15 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define ST_INIT		0
# define ST_FLAG		1
# define ST_LS			2
# define ST_PTR			3
# define ST_CONVERSION	4
# define ST_PERCENT		5
# define ST_FIN			6
# define ST_WC			7
# define ST_TERM		8

# define EV_FLAG 		1
# define EV_HEX			2
# define EV_PTR			3
# define EV_UNS			4
# define EV_LS			5
# define EV_PERCENT		6
# define EV_STR			7
# define EV_INT			8
# define EV_FLOAT		9
# define EV_CHAR		10
# define EV_OCT			11
# define EV_WC			12
# define EV_TERM		13

struct s_transition;

typedef struct	s_sbox
{
	int					len;
	int					ind;
	int					min;
	int					wid;
	int					pre;
	int					has;
	int					plu;
	int					zer;
	int					spe;
	int					l;
	int					ll;
	int					h;
	int					hh;
	int					ld;
	int					nul;
	int					ret_len;
	char				*str;
	char				*ret_str;
	char				*temp_str;
	va_list				ap;
	struct s_transition	*trans;
}				t_sbox;

typedef struct	s_transition
{
	int	st;
	int ev;
	int	(*fn)(t_sbox*);
}				t_transition;

/*
** Convertion functions:
*/

int				ft_str(t_sbox *sb);
int				ft_int(t_sbox *sb);
int				ft_ptr(t_sbox *sb);
int				ft_char(t_sbox *sb);
int				ft_conv(t_sbox *sb);
int				ft_lint(t_sbox *sb);
int				ft_octal(t_sbox *sb);
int				ft_llint(t_sbox *sb);
int				ft_hhint(t_sbox *sb);
int				ft_double(t_sbox *sb);
int				ft_loctal(t_sbox *sb);
int				ft_lloctal(t_sbox *sb);
int				ft_hexadec(t_sbox *sb);
int				ft_ldouble(t_sbox *sb);
int				ft_percent(t_sbox *sb);
int				ft_lhexadec(t_sbox *sb);
int				ft_unsigned(t_sbox *sb);
int				ft_llhexadec(t_sbox *sb);
int				ft_unsignedl(t_sbox *sb);
int				ft_unsignedll(t_sbox *sb);

/*
** State machine functions:
*/

int				ft_fin(t_sbox *sb);
int				ft_fsm(t_sbox *sb);
int				ft_error(t_sbox *sb);
int				ft_next_char(t_sbox *sb);

/*
** Flag functions:
*/

int				ft_ls(t_sbox *sb);
int				ft_flag(t_sbox *sb);
int				ft_plus(t_sbox *sb);
int				ft_space(t_sbox *sb);
int				ft_width(t_sbox *sb);
void			ft_negative(t_sbox *sb);
int				ft_update_ls(t_sbox *sb);
void			ft_precision(t_sbox *sb);
void			ft_hash_flag(t_sbox *sb);
void			ft_reset_flag(t_sbox *sb);
void			ft_conf_flag(t_sbox *sb, int *add, int *len, char *ch);

/*
** Main functions:
*/

int				ft_printf(const char *str, ...);
void			ft_store_char(t_sbox *sb);
void			ft_put_ret_str(char *s);
t_sbox			*ft_make_struct(char const *str);

/*
** Convertion functions:
*/

int				ft_hint(t_sbox *sb);
int				ft_hhint(t_sbox *sb);
char			*ft_utoa(unsigned n);
char			*ft_hitoa(short n);
char			*ft_itoha(unsigned int num, int cap);
char			*ft_hhitoa(char n);
char			*ft_llutoa(unsigned long long n);
char			*ft_lltoha(unsigned long long int num, int cap);
char			*ft_itooa(unsigned int num);
char			*ft_lltooa(unsigned long long num);

#endif
