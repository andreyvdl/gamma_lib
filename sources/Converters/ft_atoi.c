/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 10:16:08 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/06 00:51:01 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_atoi(char *nptr)
{
	bool	neg;
	int		nbr;

	if (nptr == NIL)
		return (0);
	while (ft_isspace(*nptr))
		nptr++;
	neg = *nptr == '-';
	nptr = nptr + 1 * (neg || *nptr == '+');
	while (ft_isdigit(*nptr))
		nbr = nbr * 10 + (*nptr - '0');
	if (neg)
		return (nbr * -1);
	return (nbr);
}
