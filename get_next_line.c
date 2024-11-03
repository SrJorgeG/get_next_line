/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 03:10:54 by jgomez-d          #+#    #+#             */
/*   Updated: 2024/11/04 00:50:47 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_lnjump(int fd, char	*aux)
{
	
	return ();
}

char	*get_line(int fd, t_list **lst, char	*aux)
{
	size_t	cont;
	t_list *str;
	char	*rest;
//	SI NO HAY CONTENIDO GUARDADO EN EL NODO DE LA LISTA
	str = *lst;
	if (!str->content)
	{
		cont = read(fd, aux, BUFFER_SIZE);
		if (cont < 0)
			return (NULL);
		while (ft_strchr(aux, '\n'))
		{
			ft_memcpy(str->content, aux, ft_strlen(aux)
				- ft_strlen(ft_strchr(aux, '\n')));
			ft_memcpy(aux, (ft_strchr(aux, '\n') + 1), ft_strlen(rest));
			str = str->next;
		}
		str->content = aux;
		return (ft_strchr(aux, '\n'));
	}
//	SI HAY UN SALTO DE LINEA EN LA PRIMERA POSICION (SON RESTOS)
/*
	if (str->content[0] == '\n')
	{
		cont = read(fd, aux, (BUFFER_SIZE - ft_strlen(str->content)));
		if (cont < 0)
			return (NULL);
		str->content = ft_strjoin(str->content, aux);
	}
//	EL NODO ESTA LLENO
	else
	{
		str->next = ft_lstnew(aux);
		if (!str->next)
			return (NULL);
	} 
*/
	return (NULL);
}


char	*get_next_line(int fd)
{
	static t_list	*str_list;
	char			*nxt_ln;
	char			*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nxt_ln = get_line(fd, str_list, buff);
	if (nxt_ln)
	{
		while (ft_strchr(&nxt_ln[1], '\n'))
		{
			ft_lstadd_back(&str_list, ft_lstnew(ft_strchr(nxt_ln[1], '\n')));
			ft_memcpy(nxt_ln, buff, (buff - ft_strchr(buff, '\n')));
		}
	}
	return (str_list->content);
}
