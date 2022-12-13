/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstremove_if.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:04:44 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/13 09:13:37 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstremove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*current;
	t_list	*next;

	if (!begin_list || !data_ref || !cmp || !free_fct)
		return ;
	current = *begin_list;
	prev = 0x0;
	while (current)
	{
		next = current->next;
		if (cmp(current->content, data_ref) == 0)
		{
			if (!prev)
				*begin_list = next;
			else
				prev->next = next;
			free_fct(current->content);
			free(current);
		}
		else
			prev = current;
		current = next;
	}
}
