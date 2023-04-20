/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:11:54 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/20 16:22:22 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_otoi(const char *octal)
{
	int		number;
	size_t	index;

	if (octal == NULL)
		return (0);
	index = 0;
	walk_on_whitespaces(octal, &index);
	number = 0;
	while (octal[index] != '\0' \
			&& (octal[index] >= '0' && octal[index] <= '7'))
	{
		number = number * 8 + (octal[index] - '0');
		index++;
	}
	return (number);
}

static void	walk_on_whitespcaes(const char *octal, size_t *index)
{
	while (octal[*index] == ' ' || octal[*index] == '\t' || \
			octal[*index] == '\n' || octal[*index] == '\v' || \
			octal[*index] == '\f' || octal[*index] == '\r')
	{
		if (octal[*index] == '\0')
			break ;
		else if (octal[*index] >= '0' && octal[*index] <= '7')
			break ;
		(*index)++;
	}
}
