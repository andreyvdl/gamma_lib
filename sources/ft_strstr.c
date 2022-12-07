/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:23:36 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/07 15:34:41 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t	i;
	size_t	j;

	if (!to_find[0])
		return ((char *)str);
	else if (!to_find[0] && !str[0])
		return ((char *)str);
	i = -1;
	while (str[++i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == 0)
				return (&((char *)str)[i]);
			j++;
		}
	}
	return (0x0);
}
