/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 03:10:58 by jgomez-d          #+#    #+#             */
/*   Updated: 2024/11/14 19:33:53 by jorge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	i;
	
	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = ft_strlen(s);
	if (!s)
		return ((char *)s);
	while ((++i) < len)
		if ((char)s[i] == (char)c)
			return ((char *)&s[i]);
	return (NULL);
}

void	*ft_memcpy(char *dst, char *src, size_t n)
{
	if (!src)
		return (NULL);
	while (n--)
	{
		*dst = *src;
		dst++;
		src++;
	}
	return (dst);
}


char	*ft_strjoin(char *s1, char *s2)
{
	char	*sd;

	if (!s1 || !s2)
		return (NULL);
	sd = ft_calloc(sizeof(char), (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!sd)
		return (NULL);
	ft_memcpy(sd, s1, ft_strlen(s1));
	ft_memcpy(sd + ft_strlen(s1), s2, ft_strlen(s2));
	return (sd);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*z;
	size_t	len;
	size_t	i;
	
	i = 0;
	len = nmemb * size;
	z = malloc(len);
	if (z)
		while (i < len)
			z[i++] = '\0';
	//printf("len: [%lu] ft_calloc:[%s]\n", len, z);
	return (z);
}

t_list	*ft_lstnew(char *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

/*
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
*/
