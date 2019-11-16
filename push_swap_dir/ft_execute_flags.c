/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:00:25 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/02 22:29:25 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_checker.h"

/*
** @descr: Counts the number of instructions in the output str.
*/

int			ft_count_words(char *final_str)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (final_str[i])
	{
		if (ft_isalpha(final_str[i]))
		{
			word_count++;
			while (final_str[i] && ft_isalpha(final_str[i]))
				i++;
		}
		while (final_str[i] && !ft_isalpha(final_str[i]))
			i++;
	}
	return (word_count);
}

static void	ft_large_test(int argc, int word_count)
{
	if (argc <= 500)
	{
		if (word_count < 5500)
			ft_putstr("5 points\n");
		else if (word_count < 7000)
			ft_putstr("4 points\n");
		else if (word_count < 8500)
			ft_putstr("3 points\n");
		else if (word_count < 10000)
			ft_putstr("2 points\n");
		else if (word_count < 11500)
			ft_putstr("1 points\n");
		else
			ft_putstr("No points\n");
	}
	else
		ft_putstr("No instruction limit for this amount of inputs!\n");
}

static void	ft_points_flag_cond(int argc, int word_count)
{
	if (argc <= 5)
	{
		if (word_count <= 12)
			ft_putstr("Max points\n");
		else
			ft_putstr("No points\n");
	}
	else if (argc <= 100)
	{
		if (word_count < 700)
			ft_putstr("5 points\n");
		else if (word_count < 900)
			ft_putstr("4 points\n");
		else if (word_count < 1100)
			ft_putstr("3 points\n");
		else if (word_count < 1300)
			ft_putstr("2 points\n");
		else if (word_count < 1500)
			ft_putstr("1 points\n");
		else
			ft_putstr("No points\n");
	}
	else
		ft_large_test(argc, word_count);
}

/*
** @descr: Checks if -c and -p flags are activated and executes them.
*/

void		ft_execute_flags(char *final_str, int flags, int argc)
{
	int		word_count;
	char	*count_str;

	word_count = ft_count_words(final_str);
	argc = ft_int_arg_count1(flags, argc);
	if (flags == 2 || flags == 3 || flags == 7)
	{
		ft_putstr("Instruction count: ");
		count_str = ft_itoa(word_count);
		ft_putstr(count_str);
		free(count_str);
		ft_putstr("\n");
	}
	if (flags == 1 || flags == 3 || flags == 7)
		ft_points_flag_cond(argc, word_count);
}
