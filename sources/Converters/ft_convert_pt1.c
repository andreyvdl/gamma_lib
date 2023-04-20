/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pt1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:46:27 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/19 21:56:44 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	decimal(int nbr);



static int	decimal(int nbr)
{
	int	house;

	house = 0;
	if (nbr <= 0)
		house = 1;
	while (nbr != 0)
	{
		nbr /= 10;
		house++;
	}
	return (house);
}





char	*ft_itob(size_t nbr)
{
	char	*bin;
	size_t	i;

	if (nbr == 0 || nbr == 1)
		return (ft_itoa(nbr));
	bin = (char *)ft_calloc(64 + 1, sizeof(char));
	if (!bin)
		return (0x0);
	i = 0;
	while (nbr != 0)
	{
		bin[i] = nbr % 2 + '0';
		nbr /= 2;
		i++;
	}
	return (ft_strrev(bin));
}
