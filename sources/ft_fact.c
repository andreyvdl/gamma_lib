/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fact.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:30:01 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/07 16:59:16 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long long int	ft_fact(long long int n)
{
	long long int	total;

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
