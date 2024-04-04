/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprime.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:35:43 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/24 22:26:28 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

bool	ft_isprime(int nb)
{
	if (nb < 0 || nb == 0 || nb == 1)
		return (false);
	else if (nb == 2 || nb == 3 || nb == 5 || nb == 7 || nb == 11)
		return (true);
	else if (nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0 || nb % 7 == 0)
		return (false);
	return (true);
}
