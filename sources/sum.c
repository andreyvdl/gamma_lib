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

long long int	sum(long long unsigned int n, ...)
{
	va_list					al;
	long long int			total;
	long long unsigned int	i;

	va_start(al, n);
	i = 0;
	total = 0;
	while (i < n)
	{
		total += va_arg(al, long long int);
		i++;
	}
	va_end(al);
	return (total);
}
