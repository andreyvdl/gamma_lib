/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 20:39:15 by adantas-          #+#    #+#             */
/*   Updated: 2022/11/04 15:16:06 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*free_this;

	while (*lst != 0x0)
	{
		free_this = *lst;
		*lst = (*lst)->next;
		del(free_this->content);
		free(free_this);
	}
	lst = 0x0;
}
