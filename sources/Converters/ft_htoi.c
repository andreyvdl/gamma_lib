/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:03:31 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/24 22:53:10 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	walk_on_whitespaces(t_str *string)
{
	while (**string == ' ' || **string == '\t' || **string == '\n' || \
	**string == '\v' || **string == '\f' || **string == '\r')
		(*string)++;
}

static int	get_decimal_value(char byte)
{
	if (byte >= '0' && byte <= '9')
		return (byte - '0');
	else if (byte >= 'a' && byte <= 'f')
		return (byte - 'a' + 10);
	else if (byte >= 'A' && byte <= 'F')
		return (byte - 'A' + 10);
	return (-1);
}

static int	convert_hexadecimal(t_str hexadecimal)
{
	int	decimal;
	int	number;

	number = 0;
	while (*hexadecimal)
	{
		decimal = get_decimal_value(*hexadecimal++);
		if (decimal == -1)
			break ;
		number = number * 16 + decimal;
	}
	return (number);
}

int	ft_htoi(t_str hexadecimal)
{
	if (hexadecimal == NIL)
		return (0);
	walk_on_whitespaces(&hexadecimal);
	if (*hexadecimal == '0' && \
	(*(hexadecimal + 1) == 'x' || *(hexadecimal + 1) == 'X'))
		hexadecimal += 2;
	return (convert_hexadecimal(hexadecimal));
}
