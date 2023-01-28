/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:30:01 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/27 22:46:02 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_factorial(size_t n)
{
	size_t	total;

	if (n == 1 || n == 0)
		return (1);
	total = 1;
	while (n > 1)
	{
		total *= n;
		--n;
	}
	return (total);
}
