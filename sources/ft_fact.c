/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fact.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:30:01 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/27 10:31:02 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long	ft_fact(long long n)
{
	long long	total;

	if (n < 0)
		return (0);
	if (n == 1 || n == 0)
		return (1);
	total = 0;
	while (n > 1)
	{
		total *= n;
		--n;
	}
	return (total);
}
