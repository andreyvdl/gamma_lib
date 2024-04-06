/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basetoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 23:49:16 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/06 02:45:31 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char	*convert_it(int64_t, int base, char *chars, bool neg);
static size_t	count_it(int64_t nbr, int base);

char	*ft_basetoa(int64_t nbr, char *chars, int base)
{
	static char	*values = "0123456789abcdefghijklmnopqrstuvwxyz";
	char		*choice;

	choice = values;
	if (base < 2 || base > 36)
		return (NIL);
	if (chars != NIL)
		choice = chars;
	return (convert_it(nbr, base, choice, nbr < 0));
}

static char	*convert_it(int64_t nbr, int base, char *chars, bool neg)
{
	char	*ret;
	int64_t	i;

	i = count_it(nbr, base) + (1 * neg);
	ret = malloc(sizeof(char) * (1 + i));
	if (ret == NIL)
		return (NIL);
	else if (neg)
		ret[0] = '-';
	while (nbr / base != 0)
	{
		if (neg)
			ret[i--] = chars[-(nbr % base)];
		else
			ret[i--] = chars[nbr % base];
		nbr = nbr / base;
	}
	return (ret);
}

static size_t	count_it(int64_t nbr, int base)
{
	size_t	size;

	size = 1;
	while (nbr / base != 0)
	{
		++size;
		nbr = nbr / base;
	}
	return (size);
}
