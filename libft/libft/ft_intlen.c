/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_intlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: abumbier <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/19 16:46:47 by abumbier      #+#    #+#                 */
/*   Updated: 2019/02/19 16:46:55 by abumbier      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_intlen(int n)
{
	int			len;
	unsigned	temp;

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
