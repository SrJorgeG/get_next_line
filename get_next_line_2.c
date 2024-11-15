/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:36:57 by jorge             #+#    #+#             */
/*   Updated: 2024/11/15 17:35:42 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

// LEER UNA LINEA 

size_t	ft_lstnewadd_back(t_list **lst, char *content)
{
	t_list	*new;
	t_list	*aux;
	
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->content = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!new->content)
		return (0);
	printf("%s \n", content);
	ft_memcpy(new->content, content, ft_strlen(content));
	new->next = NULL;
	aux = *lst;
	if (*lst)
	{
		while (aux->next)
		{
			printf("Hola\n");
			aux = aux->next;
		}
		aux->next = new;
	}
	else
		*lst = new;
	return (1);
}

void	ft_lstclear(t_list **lst)
{
	t_list	*temp;
	t_list	*aux;

	aux = *lst;
	if (!aux)
		return ;
	if (aux)
	{
		temp = aux->next;
 		free(aux->content);
		free(aux);
		aux = temp;
	}
}

char    *get_line_2(int fd, t_list **str_list)
{
    char    *aux;
	char	*rest;
    ssize_t  cont;
	t_list	*str;
	char    *lastnode;

	str = *str_list;
	rest = NULL;
	while (!rest && cont)	
	{
		aux = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!aux)
			return (NULL);
		cont = read(fd, aux, BUFFER_SIZE);
		if (cont < 0)
			return (NULL);
		rest = ft_strchr(aux, '\n');
		if (!rest)
		{	
			ft_lstnewadd_back(&str, aux);
			str = str->next;
			free(aux);
		}
	}
	lastnode = ft_calloc(cont - ft_strlen(rest) + 1, sizeof(char));	
	if (!lastnode)
		return (NULL);
	ft_memcpy(lastnode, aux, cont - ft_strlen(rest));
	free(aux);
	ft_lstnewadd_back(&str, lastnode);
	free(lastnode);
	return (rest);
}

char    *get_next_line_2(int fd)
{
    static t_list	*str_list;
    char            *line;
	char			*rest;

    if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	str_list = ft_lstnew(NULL);
	if (!str_list)
		return (NULL);
	rest = get_line_2(fd, &str_list);
	while (str_list)
	{
		printf("Loop\n");
		line = ft_strjoin(line, str_list->content);
		ft_lstclear(&str_list);
		str_list = str_list->next;
	}
	while (rest)        
	{
		ft_lstnewadd_back(&str, aux);
		ft_lstnewadd_back(&str_list, rest + 1);
	}
	return (line);
}
