/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_prime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:12:47 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/27 10:31:19 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long	ft_next_prime(long long nb)
{
	if (nb <= 1)
		return (2);
	else if (nb == 2)
		return (3);
	else if (nb == 3)
		return (5);
	else if (nb == 5)
		return (7);
	else if (nb == 7)
		return (11);
	while (nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0 || nb % 7 == 0)
	{
		if (nb < 0)
			return (-1);
		++nb;
	}
	return (nb);
}
