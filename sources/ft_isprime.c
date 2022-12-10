/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:06:28 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/09 22:15:18 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isprime(long long int nb)
{
	if (nb <= 1)
		return (0);
	else if (nb == 2 || nb == 3 || nb == 5 || nb == 7)
		return (1);
	else if (nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0 || nb % 7 == 0)
		return (0);
	return (1);
}
