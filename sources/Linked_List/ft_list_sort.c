/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:22:31 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/11 14:11:16 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static void	swap_content(t_list **current, t_list **next)
{
	void	*temporary;

	temporary = (*current)->content;
	(*current)->content = (*next)->content;
	(*next)->content = temporary;
}

/**
 * @brief Sorts a list from smallest to biggest using the cmp function; If any
 * 			of the parameters are NULL the function does nothing; If the list is
 * 			in order the function will just iterate through the list;
 * 
 * @param begin_list A pointer to the address of the first node of a list;
 * @param cmp A pointer the function that will be used to compare the content of
 * 			the nodes;
 */
void	ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *))
{
	t_list	*current;
	t_list	*next;

	if (begin_list == 0x0 || *begin_list == 0x0 || cmp == 0x0)
		return ;
	current = *begin_list;
	while (current->next)
	{
		next = current->next;
		while (next)
		{
			if (cmp(current->content, next->content) > 0)
				swap_content(&current, &next);
			next = next->next;
		}
		current = current->next;
	}
}
