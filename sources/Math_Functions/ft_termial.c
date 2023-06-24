/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 23:48:39 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/23 19:36:42 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Calculates the termial of a given number;
 * @warning Big numbers can cause an overflow;
 * 
 * @param n The number to calculate the termial;
 * @return The total of the termial (unsigned int);
 */
__u_int	ft_termial(__u_int n)
{
	__u_int	total;

	total = 1;
	while (n > 1)
	{
		total += n;
		n--;
	}
	return (total);
}
