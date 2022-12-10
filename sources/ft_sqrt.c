/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:54:36 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/09 22:44:42 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long double ft_sqrt(long double n)
{
	long double		total;
	long long int	fat;

	fat = 2;
	total = 1;
	if (n <= 0)
		return (0);
	while (n != 1)
	{
		if (n <= fat)
			break ;
		else if (n % fat == 0)
		{
			total *= fat;
			n /= fat;
		}
		else
			fat = ft_next_prime(fat);
	}
	return (total * n);
}
