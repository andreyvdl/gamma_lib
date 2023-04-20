/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 14:53:24 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/20 15:05:48 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_itoo(size_t n)
{
	char	*octal;
	size_t	i;

	if (n >= 0 && n <= 7)
		return (ft_itoa(n));
	octal = (char *)ft_calloc(22 + 1, sizeof(char));
	if (!octal)
		return (0x0);
	i = 0;
	while (n != 0)
	{
		octal[i] = n % 8 + '0';
		n /= 8;
		i++;
	}
	return (ft_strrev(octal));
}

char	*ft_itoo(int n)
{
	int	size;

	if (n < 0)
		return (NULL);
	size = get_size(n);
	return (allocate_and_fill(n, size));
}

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

static char	*allocate_and_fill(int number, int size)
{
	char	*array;

	array = (char *)malloc(sizeof(char) * (size + 1));
	if (array == NULL)
		return (NULL);
	array[size] = '\0';
	size--;
	while (size > -1)
	{
		array[size] = number % 8 + '0';
		number /= 8;
		size--;
	}
	return (array);
}
