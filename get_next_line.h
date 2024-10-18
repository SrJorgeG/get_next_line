/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 03:10:47 by jgomez-d          #+#    #+#             */
/*   Updated: 2024/10/18 04:17:01 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 1

#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
size_t	ft_linelen(char *line);
