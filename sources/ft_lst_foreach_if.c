/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_foreach_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:46:31 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/13 14:35:42 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lst_foreach_if(t_list *begin_list, void (*f)(void *),
void *data_ref, int (*cmp)())
{
	if (!f || !data_ref || !cmp)
		return ;
	while (begin_list != 0x0)
	{
		if (cmp(begin_list->content, data_ref) == 0)
			f(begin_list->content);
		begin_list = begin_list->next;
	}
}
