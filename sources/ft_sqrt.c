/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 22:54:36 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/08 00:02:36 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long double	ft_sqrt(long double n)
{
	long double	total;
	size_t		fat;

	fat = 2;
	total = 1;
	if (n <= 0 || n == 0x0)
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
		{
			++fat;
			while (fat % 2 != 0 || fat % 3 != 0 || fat % 5 != 0 || fat % 7 != 0)
				++fat;
		}
	}
	return (total * n);
}
