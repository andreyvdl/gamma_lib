/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:56:17 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/06 03:01:43 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	get_size(int number)
{
	int	size;

	size = 1;
	if (number < 0)
	{
		while (number < -9)
		{
			number /= 10;
			size++;
		}
	}
	while (number > 9)
	{
		number /= 10;
		size++;
	}
	return (size);
}

static char	*allocate_and_fill(int number, int size)
{
	char	*array;

	array = malloc(sizeof(char) * (size + 1));
	if (array == NIL)
		return (NIL);
	array[size] = 0;
	while (size--)
	{
		array[size] = number % 10 + '0';
		number /= 10;
	}
	return (array);
}

static char	*allocate_and_fill_negative(int number, int size)
{
	char	*array;

	array = malloc(sizeof(char) * (size + 2));
	if (array == NIL)
		return (NIL);
	*array = '-';
	array[size + 1] = 0;
	while (size)
	{
		array[size] = (number % 10) * -1 + '0';
		number /= 10;
		size--;
	}
	return (array);
}

char	*ft_itoa(int n)
{
	int	size;

	if (n < 0)
	{
		size = get_size(n);
		return (allocate_and_fill_negative(n, size));
	}
	size = get_size(n);
	return (allocate_and_fill(n, size));
}
