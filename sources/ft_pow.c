/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:00:37 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/07 17:38:09 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long int	ft_pow(long long int n, long long int exp)
{
	long long int	total;

	if (n == 0)
		return (0);
	if (exp == 0)
		return (1);
	if (exp == 1 || n == 1)
		return (n);
	total = n;
	while (exp > 1)
	{
		total *= n;
		--exp;
	}
	return (total);
}
