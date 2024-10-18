/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 03:10:58 by jgomez-d          #+#    #+#             */
/*   Updated: 2024/10/18 04:23:51 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_linelen(int fd)
{
	size_t	count;
	char	*str;

	str = (char *)malloc(BUFFER_SIZE);
	if (!str)
		return (0);
	read(fd, str, BUFFER_SIZE);
	count = 0;
	while(*str != '\n' && count < BUFFER_SIZE)
	{
		str++;
		count++;
	}
	return count;
}