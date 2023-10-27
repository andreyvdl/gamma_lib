/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:16:08 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/26 22:04:30 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	negative_integer(t_str str)
{
	int	nbr;

	nbr = 0;
	while (ft_isdigit(*str))
		nbr = nbr * 10 + (*str++ - '0');
	return (nbr * -1);
}

static int	positive_integer(t_str str)
{
	int	nbr;

	nbr = 0;
	if (*str == '+')
		str++;
	while (ft_isdigit(*str))
		nbr = nbr * 10 + (*str++ - '0');
	return (nbr);
}

int	ft_atoi(t_str nptr)
{
	if (nptr == NIL)
		return (0);
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-')
		return (negative_integer(nptr));
	if (*nptr == '+' || ft_isdigit(*nptr))
		return (positive_integer(nptr));
	return (0);
}
