/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:19:28 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/14 22:27:18 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Converts all uppercase letters of a string to lowercase;
 * 
 * @param str A pointer to the string;
 * @return the string converted (char *);
 */
char	*ft_strlowcase(char *str)
{
	size_t	index;

	if (str == 0x0)
		return (0x0);
	index = 0;
	while (str[index])
	{
		if (str[index] >= 'A' && str[index] <= 'Z')
			str[index] += 32;
		index++;
	}
	return (str);
}
