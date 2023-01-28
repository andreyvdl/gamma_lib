/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:16:43 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/28 13:49:37 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new == 0x0)
		return ;
	else if (*lst == 0x0)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new == 0x0)
		return ;
	new->next = *lst;
	*lst = new;
}

void	ft_lstmerge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current;

	if (!begin_list1 || !begin_list2)
		return ;
	current = ft_lstlast(*begin_list1);
	current->next = begin_list2;
}
