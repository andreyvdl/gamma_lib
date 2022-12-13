/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 08:45:39 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/13 08:59:27 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstfind(t_list *begin_list, void *data_ref, int (*cmp)())
{
	if (!begin_list || !data_ref || !cmp)
		return (0x0);
	while (begin_list != 0x0)
	{
		if (cmp(begin_list->content, data_ref) == 0)
			return (begin_list);
		begin_list = begin_list->next;
	}
	return (0x0);
}
