/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorge <jorge@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 03:10:47 by jgomez-d          #+#    #+#             */
/*   Updated: 2024/11/15 16:34:52 by jorge            ###   ########.fr       */
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
# include <stdint.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;
char	*get_next_line_2(int fd);
char    *get_line_2(int fd, t_list **str_list);
size_t	ft_strlen(char *s);
t_list	*ft_lstnew(char *content);
size_t	ft_lstnewadd_back(t_list **lst, char *content);
char	*ft_strchr(char *s, int c);
void	*ft_memcpy(char *dst,char *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_lstclear(t_list **lst);

#endif
