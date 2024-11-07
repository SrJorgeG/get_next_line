/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 03:10:54 by jgomez-d          #+#    #+#             */
/*   Updated: 2024/11/07 02:24:11 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t get_line(int fd, t_list **lst, char	*aux)
{
	ssize_t	cont;
	size_t	i;
	t_list	*str;
	char	*rest;

	str = *lst;
	cont = 0;
	i = 0;
	rest = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!rest)
		return (0);
	while (!ft_strchr(aux, '\n') || cont <= 0)
	{
		cont = read(fd, aux, BUFFER_SIZE);
		if (cont < 0)
			return (0);
		rest = (ft_strchr(aux, '\n'));
		if (!rest)
		{
			ft_memcpy(str->content, aux, ft_strlen(aux));
			return (i);
		}
		ft_memcpy(str->content, aux,
			(ft_strlen(aux) - ft_strlen(rest++)));
	}
	while (rest)
	{
		aux += (ft_strlen(aux) - ft_strlen(rest) + 1);
		ft_lstadd_back(&str, ft_lstnew(aux));
		if (!str->next)
			return (i);
		str = str->next;
		rest = ft_strchr(aux, '\n') + 1;
	}
	free(rest);
	return (i);
}	

char	*get_next_line(int fd)
{
	static t_list	*str_list;
	char			*ln;
	char			*buff;
	size_t			counter;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (NULL);
	counter = get_line(fd, &str_list, buff);
	if (!counter)
		return (NULL);
	ln = (char *)ft_calloc((counter * BUFFER_SIZE) + 1, sizeof(char));
	if (!ln)
		return (NULL);
	counter = get_line(fd, &str_list, buff);
	while (counter--)
	{
		ln = ft_strjoin(ln, str_list->content);
		str_list->content = NULL;
		free(str_list);
		str_list = str_list->next;
	}
	free(buff);
	free(ln);
	return (ln);
}
