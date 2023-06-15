/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:53:42 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/14 22:33:58 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	get_string_size(char const *string)
{
	size_t	index;

	index = 0;
	while (string[index] != '\0')
		index++;
	return (index);
}

/**
 * @brief Applies the function f to each character of the string s to create a
 * 			new string resulting from successive applications of f;
 * 
 * @param s A pointer to the string to be iterated;
 * @param f A pointer to the function to be applied to each character;
 * @return The string created from the successive applications of f (char *);
 * 			NULL if allocation fails;
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_string;
	unsigned int	index;

	if (s == 0x0 || f == 0x0)
		return (0x0);
	new_string = (char *)malloc(sizeof(char) * (get_string_size(s) + 1));
	if (new_string == 0x0)
		return (0x0);
	index = 0;
	while (s[index])
	{
		new_string[index] = (*f)(index, s[index]);
		index++;
	}
	new_string[index] = '\0';
	return (new_string);
}




