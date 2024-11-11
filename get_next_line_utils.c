/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 03:10:58 by jgomez-d          #+#    #+#             */
/*   Updated: 2024/11/11 23:18:14 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

size_t	*ft_lstnewadd_back(t_list **lst, char *content)
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

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = ft_strlen(s);
	while ((++i) < len)
		if ((char)s[i] == (char)c)
			return ((char *)&s[i]);
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*a;
	unsigned char	*z;

	if (!dest && !src)
		return (dest);
	a = (unsigned char *)src;
	z = (unsigned char *)dest;
	while (n--)
		*(z++) = *(a++);
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
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

	len = nmemb * size;
	z = malloc(len);
	if (z)
		while (len--)
			*z++ = '\0';
	return (z);
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
