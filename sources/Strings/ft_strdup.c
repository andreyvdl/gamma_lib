/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:42:23 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/14 21:55:19 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	get_string_size(const char *string)
{
	size_t	index;

	index = 0;
	while (string[index])
		index++;
	return (index);
}

/**
 * @brief Duplicates a string;
 * 
 * @param s A pointer to the string to be duplicated;
 * @return A pointer to the new string (char *); Or NULL if the allocation fails;
 */
char	*ft_strdup(const char *s)
{
	char	*copy;
	char	*temp;

	if (s == 0x0)
		return (0x0);
	copy = (char *)malloc((get_string_size(s) + 1) * sizeof(char));
	if (copy == 0x0)
		return (0x0);
	temp = copy;
	while (*s)
		*temp++ = *s++;
	*temp = '\0';
	return (copy);
}
