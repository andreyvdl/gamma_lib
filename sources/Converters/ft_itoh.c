/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:49:09 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/24 23:00:05 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int number)
{
	int	size;

	size = 1;
	while (number > 15)
	{
		number /= 16;
		size++;
	}
	return (size);
}

static char	get_hexadecimal(int number)
{
	if (number > 9)
		return (number - 10 + 'A');
	return (number + '0');
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
		*(array + size) = get_hexadecimal(number % 16);
		number /= 16;
	}
	return (array);
}

t_str	ft_itoh(int n)
{
	int	size;

	if (n < 0)
		return (NIL);
	size = get_size(n);
	return (allocate_and_fill(n, size));
}
