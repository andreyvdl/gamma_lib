/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 21:56:17 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/19 21:56:52 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_itoa(int n)
{
	char	*arr;
	int		size;

	size = decimal(n);
	arr = (char *)malloc(sizeof(char) * size + 1);
	if (arr == 0x0)
		return (0x0);
	if (n == 0)
		arr[0] = '0';
	else if (n < 0)
		arr[0] = '-';
	arr[size--] = '\0';
	while (n != 0 && size >= 0)
	{
		arr[size--] = ft_absolute(n % 10) + '0';
		n /= 10;
	}
	return (arr);
}
