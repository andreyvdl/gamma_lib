/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:55:19 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/24 22:52:23 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	walk_on_whitespaces(t_str *string)
{
	while (**string == ' ' || **string == '\t' || **string == '\n' || \
	**string == '\v' || **string == '\f' || **string == '\r')
		(*string)++;
}


int	ft_btoi(t_str binary)
{
	int		number;

	if (binary == NIL)
		return (0);
	walk_on_whitespaces(&binary);
	number = 0;
	while (*binary == '0' || *binary == '1')
	{
		number <<= 1;
		if (*binary++ == '1')
			number |= 1;
	}
	return (number);
}
