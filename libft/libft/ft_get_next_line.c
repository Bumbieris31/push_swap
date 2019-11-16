/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abumbier <abumbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 18:37:06 by abumbier          #+#    #+#             */
/*   Updated: 2019/06/29 16:34:14 by abumbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @desc: ft_strjoin which return value overwrites s1. (without leaks)
*/

char			*ft_gnl_add(char *s1, char const *s2)
{
	char	*str_temp;

	str_temp = ft_strdup(s1);
	if (s1 != NULL && ft_strcmp(s1, "") != 0)
		ft_strdel(&s1);
	s1 = ft_strjoin(str_temp, s2);
	ft_strdel(&str_temp);
	return (s1);
}

/*
** @desc: Creates a new node and fills necessary values.
** @param: fd - file descriptor for which the node is created.
** @var: lst - pointer to the created node.
** @return: lst pointer or 0 if malloc failed.
*/

t_gnl_list		*new_lst(const int fd)
{
	t_gnl_list	*lst;

	lst = (t_gnl_list*)malloc(sizeof(t_gnl_list));
	if (lst == NULL)
		return (0);
	lst->next = NULL;
	lst->fd = fd;
	lst->len = 0;
	lst->str_main = "";
	lst->temp = NULL;
	return (lst);
}

/*
** @desc: Fills the lst->main_str with full line, fills the lst->temp with \
** everything left after \n in buffer.
** @param: fd - from file which chould be read.
** @param: t_gnl_list **lst - lst that holds correct lines read for each fd.
** @param: minivan - buffer holding the chars read.
** @param: a - the amount of chars read.
** @return: 1 if something is being read; 0 if reading has been completed; \
** -1 if reading failed.
*/

int				gnl_magic(const int fd, t_gnl_list **lst, char *minivan, int a)
{
	(*lst)->str_main = ft_gnl_add((*lst)->str_main, minivan);
	if ((*lst)->str_main == NULL)
		return (-1);
	while (ft_memchr(minivan, '\n', BUFF_SIZE) == NULL && a > 0)
	{
		a = read(fd, minivan, BUFF_SIZE);
		minivan[a] = '\0';
		if (a > 0)
			(*lst)->str_main = ft_gnl_add((*lst)->str_main, minivan);
		if ((*lst)->str_main == NULL)
			return (-1);
	}
	(*lst)->len = ft_wordlen((*lst)->str_main, '\n');
	a = ft_strlen((*lst)->str_main);
	if ((*lst)->len + 1 < a)
	{
		(*lst)->temp = (char*)malloc(a - (*lst)->len);
		if ((*lst)->temp == NULL)
			return (-1);
		(**lst).temp[a - (*lst)->len - 1] = '\0';
		(*lst)->temp = ft_memcpy((*lst)->temp, \
		&(*lst)->str_main[(*lst)->len + 1], a - (*lst)->len - 1);
	}
	(*lst)->str_main[(*lst)->len] = '\0';
	return (1);
}

/*
** @desc: Reads from fd into minivan, checks if lst->temp has any value, \
** calls gnl_magic for a line.
** @param: fd from file which chould be read.
** @param: t_gnl_list **lst - lst that holds correct lines read for each fd.
** @var: int a - holds the amount of chars read.
** @var: minivan - buffer holding the chars read.
** @var: feed_in - new string which will be passed into gnl_magic.
** @return: 1 if something is being read; 0 if reading has been completed; \
** -1 if reading failed.
*/

int				read_from_fd(const int fd, t_gnl_list **lst)
{
	int		a;
	char	minivan[BUFF_SIZE + 1];

	a = 0;
	ft_bzero(minivan, BUFF_SIZE + 1);
	if ((*lst)->temp != NULL)
	{
		if (ft_strchr((*lst)->temp, '\n') == NULL)
			a = read(fd, minivan, BUFF_SIZE);
		(*lst)->str_main = ft_strjoin((*lst)->str_main, (*lst)->temp);
		ft_strdel(&(*lst)->temp);
	}
	else
	{
		a = read(fd, minivan, BUFF_SIZE);
		if (a == 0 && (*lst)->temp == NULL)
			return (0);
	}
	if (a == -1 || (*lst)->str_main == NULL)
		return (-1);
	if (a > 0 || !(ft_strcmp((*lst)->str_main, "") == 0))
		if (gnl_magic(fd, lst, minivan, a) >= 0)
			return (1);
	return (0);
}

/*
** @desc: Finds the correct node for fd, calls read_from_fd, copies \
** necessary string in *line.
** @param: fd from file which chould be read.
** @param: char **line - adress of a pointer which will point to a \
** line read from fd.
** @var: int a - holds the return value of a read_from_fd function.
** @var: static t_gnl_list *head - pointer to the first node in lst.
** @var: t_gnl_lst *lst - pointer which will iterate through the list.
** @return: a - return value of a read_from_fd.
*/

int				ft_get_next_line(const int fd, char **line)
{
	int					a;
	t_gnl_list			*lst;
	static t_gnl_list	*head;

	lst = head;
	if (lst == NULL)
	{
		lst = new_lst(fd);
		head = lst;
	}
	if (fd < 0 || line == NULL || lst == NULL)
		return (-1);
	while (lst->next != NULL && fd != lst->fd)
		lst = lst->next;
	if (lst->next == NULL && fd != lst->fd)
	{
		lst->next = new_lst(fd);
		lst = lst->next;
	}
	a = read_from_fd(fd, &lst);
	*line = ft_strdup(lst->str_main);
	if (ft_strcmp(lst->str_main, "") != 0)
		ft_strdel(&(lst->str_main));
	lst->str_main = "";
	return (a);
}
