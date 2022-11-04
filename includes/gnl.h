/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:23:17 by adantas-          #+#    #+#             */
/*   Updated: 2022/11/04 10:00:09 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>

// gnl.c funcitons
char	*get_next_line(int fd);
void	cpy_1_line(char **rest, char **line);
char	*read_fd(char **rest, char **line, int fd);
char	*until_newline(char **line, char *buf, char **rest);
void	secret_trick(char **rest, char *buf, size_t n);

// gnl_utils.c functions
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, int c);
void	*ft_realloc_mod(char **ptr);
char	*ft_strjoin_mod(char *s1, char *s2);

#endif
