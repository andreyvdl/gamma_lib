/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 23:35:18 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/01 23:35:18 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/outside.h"

double	ft_sum(size_t n, ...)
{
	va_list	al;
	double	total;
	size_t	i;

	va_start(al, n);
	i = 0;
	total = 0;
	while (i < n)
	{
		total += va_arg(al, double);
		i++;
	}
	va_end(al);
	return (total);
}
