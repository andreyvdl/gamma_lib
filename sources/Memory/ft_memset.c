/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:18:53 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/11 17:42:42 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Fills the first n bytes of the memory area pointed to by s with the
 * 			byte c;
 * 
 * @param s A pointer to the memory area to be filled;
 * @param c The byte to fill the memory area with;
 * @param n The maximum number of bytes to be filled;
 * @return A pointer to the filled memory area s (void *);
 */
void	*ft_memset(void *s, int c, size_t n)
{
	char	*temp;

	if (n == 0 || s == 0x0)
		return (s);
	temp = (char *)s;
	while (n--)
		*temp++ = c;
	return (s);
}
