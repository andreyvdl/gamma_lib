/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:16:08 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/24 22:49:27 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	walk_on_whitespaces(t_str *string)
{
	while (**string == ' ' || **string == '\t' || **string == '\n' || \
	**string == '\v' || **string == '\f' || **string == '\r')
		(*string)++;
}

static int	negative_integer(t_str string)
{
	int	number;

	number = 0;
	while (*string >= '0' && *string <= '9')
		number = number * 10 + (*string++ - '0');
	return (number * -1);
}

static int	positive_integer(t_str str)
{
	int	number;

	number = 0;
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		number = number * 10 + (*str++ - '0');
	return (number);
}

int	ft_atoi(t_str nptr)
{
	if (nptr == NIL)
		return (0);
	walk_on_whitespaces(&nptr);
	if (*nptr == '-')
		return (negative_integer(nptr));
	else if (*nptr == '+' || (*nptr >= '0' && *nptr <= '9'))
		return (positive_integer(nptr));
	return (0);
}
