/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 03:10:54 by jgomez-d          #+#    #+#             */
/*   Updated: 2024/11/08 20:14:00 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t get_line(int fd, t_list **lst)
{
	ssize_t	cont;
	size_t	i;
	size_t	rest;
	t_list	*str;
	t_list	*nodo;
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
		rest = ft_strlen(ft_strchr(aux, '\n'));
		if (!rest)
		{	
			printf("Content [%s], Aux [%s], cont [%lu]\n", str->content, aux, cont);
			ft_memcpy(str->content, aux, cont);
			return (i);
		}
		ft_memcpy(str->content, aux, (cont - rest) + 1);
		i++;
		aux += (cont - rest + 1);
		nodo = ft_lstnew(NULL);
		if (!nodo)
			return (0);
		ft_lstadd_back(&str, nodo);
		if (!str->next)
			return (i);
		str = str->next;
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
