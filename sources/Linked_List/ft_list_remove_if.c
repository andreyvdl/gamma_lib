/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:00:28 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/11 14:10:38 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Removes nodes from the list if the content of the node matches the
 * 			data_ref; If any of the parameters is NULL, the function does
 * 			nothing;
 * 
 * @param begin_list The address of the pointer to the first node of the list;
 * @param data_ref The data to be compared with the content of the nodes;
 * @param cmp The function that will be used to compare the content of the nodes
 * 			with the data_ref;
 * @param free_fct The function that will be used to free the content of the
 * 			nodes that will be removed;
 */
void	ft_list_remove_if(t_list **begin_list, void *data_ref, \
							int (*cmp)(void *, void *), \
							void (*free_fct)(void *))
{
	t_list	*previous;
	t_list	*current;
	t_list	*next;

	if (begin_list == 0x0 || *begin_list == 0x0 || data_ref == 0x0 || \
		cmp == 0x0 || free_fct == 0x0)
		return ;
	current = *begin_list;
	previous = 0x0;
	while (current != 0x0)
	{
		next = current->next;
		if (cmp(current->content, data_ref) == 0)
		{
			if (previous == 0x0)
				*begin_list = next;
			else
				previous->next = next;
			free_fct(current->content);
			free(current);
		}
		else
			previous = current;
		current = next;
	}
}
