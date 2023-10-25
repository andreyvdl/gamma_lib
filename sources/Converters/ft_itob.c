/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itob.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:47:02 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/24 22:58:25 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int number)
{
	int	size;

	size = 1;
	while (number > 1)
	{
		number /= 2;
		size++;
	}
	return (size);
}

static t_str	allocate_and_fill(int nbr, int size)
{
	t_str	array;

	array = (t_str)malloc(sizeof(char) * (size + 1));
	if (array == NIL)
		return (NIL);
	*(array + size) = '\0';
	while (size--)
	{
		*(array + size) = (nbr & 1) + '0';
		nbr >>= 1;
	}
	return (array);
}

t_str	ft_itob(int nbr)
{
	int	size;

	if (nbr < 0)
		return (NIL);
	size = get_size(nbr);
	return (allocate_and_fill(nbr, size));
}
