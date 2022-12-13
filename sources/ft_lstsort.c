/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:39:30 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/13 10:42:55 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstsort(t_list **begin_list, int (*cmp)())
{
	t_list	*current;
	t_list	*next;
	void	*temp;

	if (!begin_list || !cmp)
		return ;
	current = *begin_list;
	while (current->next)
	{
		next = current->next;
		while (next)
		{
			if (cmp(current->content, next->content) > 0)
			{
				temp = current->content;
				current->content = next->content;
				next->content = temp;
			}
			next = next->next;
		}
		current = current->next;
	}
}
