/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 22:48:17 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/06 22:48:17 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcpy(char *dst, char *src)
{
	size_t	i;

	i = -1;
	if (!dst || !src)
		return (NULL);
	while (src[++i])
		dst[i] = src[i];
	dst[i] = 0;
	return (dst);
}