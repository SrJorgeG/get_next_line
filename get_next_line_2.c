/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:36:57 by jorge             #+#    #+#             */
/*   Updated: 2024/11/14 03:42:45 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// LEER UNA LINEA 

size_t	ft_lstnewadd_back(t_list **lst, char *content)
{
	t_list	*new;
	t_list	*aux;
	
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	ft_memcpy(new->content, content, ft_strlen(content));
	new->next = NULL;
	aux = *lst;
	if (*lst)
	{
		while (aux->next)
			aux = aux->next;
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

char    *get_line2(int fd, t_list **str_list)
{
    char    *aux;
	char	*rest;
    size_t  cont;
	t_list	*str;
	char    *lastnode;

	str = *str_list;
	rest = NULL;
	while (!rest)
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
	return (++rest);
}

char    *get_next_line_2(int fd)
{
    static t_list	*str_list;
    char            *line;
	char			*rest;

    if (fd < 0)
        return (NULL);
	rest = get_line_2(fd, &str_list);
    while (str_list->next)
	{
		ft_strjoin(line, str_list->content);
		ft_lstclear(&str_list);
	}
	if (rest)
		ft_lstnewadd_back(&str_list, rest);
	return (line);
}
