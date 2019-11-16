/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llintlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 16:46:47 by abumbier          #+#    #+#             */
/*   Updated: 2019/05/19 17:25:11 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_llintlen(long long int n)
{
	int						len;
	unsigned long long int	temp;

	len = 0;
	if (n < 0)
		temp = n * -1;
	else
		temp = n;
	if (n == 0)
		len++;
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	return (len);
}
