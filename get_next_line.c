/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 03:10:54 by jgomez-d          #+#    #+#             */
/*   Updated: 2024/10/26 14:37:37 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(int fd, t_list *str)
{
	size_t	cont;
	char	*aux;
	
	
	cont = read(fd, aux, BUFFER_SIZE);
	if (cont < 0)
		return (NULL);
	if (!ft_strchr(aux, '\n'))
	{
		if (str->content)
		{
			str->next = ft_lstnew(aux);
			if (!str->next)
				return (NULL);
		}
		else
			str->content = aux;
		return (NULL);
	}
	else
		return (ft_strchr(aux, '\n'));
}

char	*get_next_line(int fd)
{
	static t_list	*str_list;
	char			*nxt_ln;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	if (get_line())
	{
		/* code */
	}
	
	
	
}
