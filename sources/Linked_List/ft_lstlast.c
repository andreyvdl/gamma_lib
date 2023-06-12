/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:23:29 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/11 14:32:57 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Find the last node of the list;
 * 
 * @param lst A pointer to the first node of the list;
 * @return The last node (t_list *) of the list; If the list is empty, then
 * 			return NULL;
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (lst == 0x0)
		return (0x0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
