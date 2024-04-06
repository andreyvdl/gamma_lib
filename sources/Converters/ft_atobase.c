/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atobase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:47:38 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/06 00:54:58 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int64_t	base2(char *str, bool neg);
static int64_t	base8(char *str, bool neg);
static int64_t	base16(char *str, bool neg);

int64_t	ft_atobase(char *str, char *chars, int base)
{
	bool	neg;
	int64_t	nbr;

	if (str == NIL || chars == NIL || base < 2 || base > 36)
		return (0);
	while (ft_isspace(*str))
		++str;
	neg = *str == '-';
	if (base == 2)
		return (base2(str + 1 * (neg || *str == '+'), neg));
	else if (base == 8)
		return (base8(str + 1 * (neg || *str == '+'), neg));
	else if (base == 16)
		return (base16(str + 1 * (neg || *str == '+'), neg));
	nbr = 0;
	while (ft_strchr(chars, *str))
		nbr = nbr * base + (ft_strchr(chars, *str++) - chars);
	if (neg)
		return (nbr * -1);
	return (nbr);
}

static int64_t	base2(char *str, bool neg)
{
	int64_t	nbr;

	if (*str == '0' && (*(str + 1) == 'b' || *(str + 1) == 'B'))
		str = str + 2;
	nbr = 0;
	while (*str == '0' || *str == '1')
		nbr = (nbr << 1) | (*str++ - '0');
	if (neg)
		return (nbr * -1);
	return (nbr);
}

static int64_t	base8(char *str, bool neg)
{
	int64_t	nbr;

	if (*str == '0' && (*(str + 1) == 'o' || *(str + 1) == 'O'))
		str = str + 2;
	nbr = 0;
	while (*str >= '0' && *str < '8')
		nbr = nbr * 8 + (*str++ - '0');
	if (neg)
		return (nbr * -1);
	return (nbr);
}

static int64_t	base16(char *str, bool neg)
{
	int64_t	nbr;

	if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
		str = str + 2;
	nbr = 0;
	while (ft_isxdigit(*str))
		nbr = nbr * 16 + (*str - ('0' + 17 * ft_isalpha(*str) + 32 \
			* ft_islower(*str)));
	if (neg)
		return (nbr * -1);
	return (nbr);
}
