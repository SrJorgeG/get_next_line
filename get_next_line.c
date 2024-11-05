/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 03:10:54 by jgomez-d          #+#    #+#             */
/*   Updated: 2024/11/05 16:04:30 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
/*char	*read_lnjump(int fd, char	*aux)
{
	
	return ();
}*/

char	*get_line(int fd, t_list **lst, char	*aux)
{
	size_t	cont;
	size_t	sum;
	t_list	*str;
	char	*rest;
//	SI NO HAY CONTENIDO GUARDADO EN EL NODO DE LA LISTA
//	sum = ft_strlen(aux) - ft_strlen(ft_strchr(aux, '\n'));
	str = *lst;
	cont = read(fd, aux, BUFFER_SIZE);
	if (cont < 0)
		return (NULL);
	printf("reads\n");
	rest = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	//rest = ft_calloc(ft_strlen(ft_strchr(aux, '\n')) + 1, sizeof(char));
	printf("mallocs\n");
	rest = strchr(aux, '\n');
	printf("strchr\n");
	if (rest)
		ft_memcpy(str->content, aux,
			(ft_strlen(aux) - ft_strlen(rest)));
	else
		ft_memcpy(str->content, aux, ft_strlen(aux));
	printf("returns rest\n");
	return (rest);

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
}


char	*get_next_line(int fd)
{
	static t_list	*str_list;
	char			*nxt_ln;
	char			*buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	nxt_ln = get_line(fd, &str_list, buff);
	if (nxt_ln)
	{
		while (ft_strchr(nxt_ln, '\n'))
		{
			printf("gets here\n");
			ft_lstadd_back(&str_list, ft_lstnew(nxt_ln));
			ft_memcpy(nxt_ln, nxt_ln, ft_strlen(nxt_ln) - ft_strlen(ft_strchr(nxt_ln, '\n')));
		}
	}
	return (str_list->content);
}
