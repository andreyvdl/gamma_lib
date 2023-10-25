/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:11:54 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/24 23:02:03 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	walk_on_whitespaces(t_str *octal)
{
	while (**octal == ' ' || **octal == '\t' || **octal == '\n' || \
	**octal == '\v' || **octal == '\f' || **octal == '\r')
		(*octal)++;
}

int	ft_otoi(t_str octal)
{
	int	number;

	if (octal == NIL)
		return (0);
	walk_on_whitespaces(&octal);
	number = 0;
	while (*octal != '\0' && (*octal >= '0' && *octal <= '7'))
		number = number * 8 + (*octal++ - '0');
	return (number);
}
