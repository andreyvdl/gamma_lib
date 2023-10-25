/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:53:24 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/24 23:01:16 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int number)
{
	int	size;

	size = 1;
	while (number > 7)
	{
		number /= 8;
		size++;
	}
	return (size);
}

static t_str	allocate_and_fill(int number, int size)
{
	t_str	array;

	array = (t_str)malloc(sizeof(char) * (size + 1));
	if (array == NIL)
		return (NIL);
	*(array + size) = '\0';
	while (size--)
	{
		*(array + size) = number % 8 + '0';
		number /= 8;
	}
	return (array);
}

t_str	ft_itoo(int n)
{
	int	size;

	if (n < 0)
		return (NIL);
	size = get_size(n);
	return (allocate_and_fill(n, size));
}
