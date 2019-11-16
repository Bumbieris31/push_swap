/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:48:02 by abumbier          #+#    #+#             */
/*   Updated: 2019/11/02 21:23:40 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

static void	ft_correct_usage(void)
{
	ft_putstr("Error - available flags:\n\
	-p - display the amount of points earned(push_swap);\n\
	-c - display the amount of instructions generated(push_swap);\n\
	-s - display the state of stacks after each instruction(checker);\n");
	exit(1);
}

/*
** @descr: Encoding of the flags is the same as for chmod. 1 = -p; 2 = -c; \
** 4 = -s.
*/

static void	ft_check_flags(char **argv, int i, int *flags)
{
	if (ft_strequ(argv[i], "-p"))
	{
		if (*flags != POINTS && *flags != (POINTS + COUNT))
			(*flags) += POINTS;
	}
	else if (ft_strequ(argv[i], "-c"))
	{
		if (*flags != COUNT && *flags != (COUNT + POINTS))
			(*flags) += COUNT;
	}
	else if (ft_strequ(argv[i], "-s"))
	{
		if (*flags != STATE && *flags != (STATE + POINTS) \
		&& *flags != (STATE + COUNT))
			(*flags) += STATE;
	}
	else
		ft_correct_usage();
}

static void	ft_check_numbers(char **argv, int i, int *j, int *flags)
{
	while (argv[i][*j])
	{
		if (ft_isdigit(argv[i][*j]))
			(*j)++;
		else
		{
			if (argv[i][*j] != '-')
			{
				if (*j == 1)
					ft_check_flags(argv, i, flags);
				else
					ft_error_msg();
			}
			(*j)++;
		}
		if (!ft_isint(argv[i]))
			ft_error_msg();
	}
}

/*
** @descr: Checks if values belong to S int and what falgs are passed.
*/

int			ft_valid_numbers(int argc, char **argv)
{
	int		i;
	int		j;
	int		flags;

	i = 1;
	flags = 0;
	while (argc > i)
	{
		j = 0;
		ft_check_numbers(argv, i, &j, &flags);
		i++;
	}
	return (flags);
}
