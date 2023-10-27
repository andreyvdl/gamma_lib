/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 16:03:31 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/26 22:16:27 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	convert_hexadecimal(t_str hex)
{
	int	nbr;

	nbr = 0;
	while (ft_isxdigit(*hex))
	{
		if (ft_isdigit(*hex))
			nbr = nbr * 16 + (*hex++ - '0');
		if (*hex >= 'a' && *hex <= 'f')
			nbr = nbr * 16 + (*hex++ - 'a' + 10);
		if (*hex >= 'A' && *hex <= 'F')
			nbr = nbr * 16 + (*hex++ - 'A' + 10);
	}
	return (nbr);
}

int	ft_htoi(t_str hex)
{
	if (hex == NIL)
		return (0);
	while (ft_isspace(*hex))
		++hex;
	if (*hex == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		hex += 2;
	return (convert_hexadecimal(hex));
}
