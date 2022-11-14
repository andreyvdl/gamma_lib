/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:51:38 by adantas-          #+#    #+#             */
/*   Updated: 2022/11/04 15:24:06 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gnl.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s && s[i] != 0 && s[i] <= 127)
			i++;
	}
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*arr;
	size_t	i;
	size_t	memlmt;

	memlmt = nmemb * size;
	if (memlmt / size != nmemb || memlmt / nmemb != size)
		return (0x0);
	arr = malloc(nmemb * size);
	if (arr == 0x0)
		return (0x0);
	i = 0;
	while (nmemb * size != i)
	{
		arr[i] = '\0';
		i++;
	}
	return ((void *)arr);
}

void	*ft_realloc_mod(char **ptr)
{
	size_t	i;
	size_t	j;
	char	*new_ptr;

	i = 0;
	if (!ptr)
		return (0x0);
	while ((*ptr)[i] != '\n' && (*ptr)[i] != 0)
		i++;
	j = ft_strlen(*ptr);
	if (j - i <= 0)
	{
		new_ptr = ft_calloc(sizeof(char), 1);
		free(*ptr);
		return ((void *)new_ptr);
	}
	else
		new_ptr = ft_calloc(sizeof(char), j - i + 1);
	i++;
	j = 0;
	while ((*ptr)[i] != 0)
		new_ptr[j++] = (*ptr)[i++];
	free(*ptr);
	*ptr = 0x0;
	return ((void *)new_ptr);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while ((char)c != s[i] && s[i] != '\0')
		i++;
	if ((char)c == s[i])
		return (&((char *)s)[i]);
	return (0x0);
}

char	*ft_strjoin_mod(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	sz;

	if (s1 == 0x0 || s2 == 0x0)
		return (0x0);
	sz = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(sizeof(char) * sz);
	if (str == 0x0)
		return (0x0);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	free(s1);
	s1 = 0x0;
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
