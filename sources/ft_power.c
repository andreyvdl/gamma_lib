/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:00:37 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/27 22:36:18 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

double	ft_power(double n, long int exp)
{
	double	total;

	if (exp == 0 || n == 1)
		return (1);
	else if (n == 0)
		return (0);
	else if (exp < 0)
		return (ft_neg_power(n, exp));
	else if (exp == 1)
		return (n);
	total = n;
	while (exp > 1)
	{
		total *= n;
		exp--;
	}
	return (total);
}

double	ft_neg_pow(double n, double exp)
{
	double	total;

	exp *= -1;
	total = n;
	while (exp > 1)
	{
		total *= n;
		exp--;
	}
	return (1 / total);
}
