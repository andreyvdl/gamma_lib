/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termial.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:26:15 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/27 11:11:59 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

unsigned long long	ft_termial(unsigned long long n)
{
	long long	total;

	total = n;
	while (n > 1)
	{
		total += (n - 1);
		n--;
	}
	return (total);
}
