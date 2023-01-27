/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:00:37 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/27 17:18:56 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

double	ft_pow(double n, double exp)
{
	double	total;

	if (exp == 0 || n == 1)
		return (1);
	else if (n == 0)
		return (0);
	else if (exp < 0)
		return (ft_neg_pow(n, exp));
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
