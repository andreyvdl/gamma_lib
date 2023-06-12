/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:40:26 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/11 16:01:11 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Writes n zeroed bytes to the memory area s;
 * 
 * @param s A pointer to the memory area;
 * @param n The number of bytes to be written;
 */
void	ft_bzero(void *s, size_t n)
{
	char	*temporary;

	if (s == 0x0 || n == 0)
		return ;
	temporary = (char *)s;
	while (n--)
		*temporary++ = '\0';
}
