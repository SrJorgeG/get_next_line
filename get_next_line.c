/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 03:10:54 by jgomez-d          #+#    #+#             */
/*   Updated: 2024/11/11 23:47:19 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
if (!rest)
{	
	ft_memcpy(str->content, aux, cont);
	return (i);
}
*/

size_t get_line(int fd, t_list **lst)
{
	ssize_t	cont;
	size_t	i;
	size_t	rest;
	t_list	*str;
	char	*aux;

	str = *lst;
	cont = 1;
	i = 0;
	aux = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!aux)
		return (0);
	while (!ft_strchr(aux, '\n') || cont > 0)
	{
		cont = read(fd, aux, BUFFER_SIZE);
		if (cont < 0)
			return (0);
		rest = ft_strchr(aux, '\n') + 1;
		while (rest > 1)
		{
			ft_memcpy(str->content, aux, (cont - ft_strlen(rest)) + 1);
			if(!ft_lstnewadd_back(lst, aux + (cont - ft_strlen(rest))))
				return (0);
			str = str->next;
			rest = ft_strchr(rest, '\n') + 1;
			i++;
		}
	}
	return (i);
}	

char	*get_next_line(int fd)
{
	static t_list	*str_list;
	char			*ln;
	size_t			counter;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str_list = ft_lstnew(NULL);
	if (!str_list)
		return (NULL);
	counter = get_line(fd, &str_list);
	if (!counter)
		return (NULL);
	ln = (char *)ft_calloc((counter * BUFFER_SIZE) + 1, sizeof(char));
	if (!ln)
		return (NULL);
	counter = get_line(fd, &str_list);
	while (counter--)
	{
		ln = ft_strjoin(ln, str_list->content);
		str_list->content = NULL;
		free(str_list);
		str_list = str_list->next;
	}
	return (ln);
}
