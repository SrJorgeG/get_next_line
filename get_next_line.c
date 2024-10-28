/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 03:10:54 by jgomez-d          #+#    #+#             */
/*   Updated: 2024/10/28 06:40:30 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, t_list *str)
{
	size_t	cont;
	char	*aux;
	
//	SI HAY CONTENIDO GUARDADO EN EL NODO DE LA LISTA
	if (str->content)
//		SI HAY UN SALTO DE LINEA EN LA PRIMERA POSICION (SON RESTOS)
		if (str->content[0] == '\n')
		{
			cont = read(fd, aux, BUFFER_SIZE - ft_strlen(str->content));
			if (cont < 0)
				return (NULL);
			str->content = ft_strjoin(str->content, aux);
		}
//		EL NODO ESTA LLENO
		else
		{
			str->next = ft_lstnew(aux);
			if (!str->next)
				return (NULL);	
		}
//	NO HAY NADA EN EL CONTENIDO DEL NODO
	else
	{
		cont = read(fd, aux, BUFFER_SIZE);
		if (cont < 0)
			return (NULL);
		ft_memcpy(str->content, aux, (aux - ft_strchr(aux, '\n')));
		str->content = aux;
		return (ft_strchr(aux, '\n'));
	}
	return (NULL);
	
}

char	*get_next_line(int fd)
{
	static t_list	*str_list;
	char			*nxt_ln;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	nxt_ln = get_line(str);
	if (nxt_ln)
	{
		while (ft_strchr(nxt_ln, '\n'))
		{
			ft_lstadd_back(&str_list, ft_lstnew(ft_strchr(nxt_ln, '\n')));
			ft_memcpy(nxt_ln, aux, (aux - ft_strchr(aux, '\n')));
		}
		
	}
	return (str_list->content);
}
