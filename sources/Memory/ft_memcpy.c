/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:24:06 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/11 17:01:45 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Copies n bytes from memory area src to memory area dst;
 * 
 * @param dst A pointer to the destiny memory area;
 * @param src A pointer to the source memory area;
 * @param n The maximum number of bytes to copy;
 * @return A pointer to the destination memory area (void *);
 */
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*temp_dst;
	unsigned char	*temp_src;

	if (dst == 0x0 || src == 0x0)
		return (dst);
	temp_dst = (unsigned char *)dst;
	temp_src = (unsigned char *)src;
	while (n--)
		*temp_dst++ = *temp_src++;
	return (dst);
}
