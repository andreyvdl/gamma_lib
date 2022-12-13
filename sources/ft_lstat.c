/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:08:28 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/12 21:12:03 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstat(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (i < nbr)
	{
		begin_list = begin_list->next;
		if (begin_list == 0x0)
			return (0x0);
		i++;
	}
	return (begin_list);
}