/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 03:10:54 by jgomez-d          #+#    #+#             */
/*   Updated: 2024/10/26 02:02:39 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t get_line(int fd, t_list *str)
{
	ssize_t	cont;
	void	*aux;
	
	
	cont = read(fd, aux,BUFFER_SIZE);
	str->content = ft_strchr(aux, '\n');
	if (!str->content)
		return (NULL);
}

char	*get_next_line(int fd)
{
	static t_list	*str_list;
	ssize_t	cont;
	
	
}
