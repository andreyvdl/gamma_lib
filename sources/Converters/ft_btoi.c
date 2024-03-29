/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:55:19 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/26 22:06:12 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_btoi(t_str bin)
{
	int	nbr;

	if (bin == NIL)
		return (0);
	while (ft_isspace(*bin))
		++bin;
	nbr = 0;
	while (*bin == '0' || *bin == '1')
	{
		nbr <<= 1;
		if (*bin++ == '1')
			nbr |= 1;
	}
	return (nbr);
}
