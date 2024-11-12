/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgomez-d <jgomez-d@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 03:10:47 by jgomez-d          #+#    #+#             */
/*   Updated: 2024/11/12 22:34:53 by jgomez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>

char	*get_next_line(int fd);
typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;
size_t	ft_strlen(char *s);
t_list	*ft_lstnew(void);
size_t	ft_lstnewadd_back(t_list **lst, char *content);
char	*ft_strchr(char *s, int c);
void	*ft_memcpy(char *dst,char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
