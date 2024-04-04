/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:12:40 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/25 23:53:58 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_btree_insert_data(t_btree **root, void *item, \
							int (*cmpf)(void *, void *))
{
	t_btree	*current;
	t_btree	*previous;

	if (item == NIL || cmpf == NIL || root == NIL)
		return ;
	if (*root == NIL)
	{
		*root = ft_btree_create_node(item);
		return ;
	}
	current = *root;
	while (current != NIL)
	{
		previous = current;
		if (cmpf(item, current->content) >= 0)
			current = current->right;
		else
			current = current->left;
	}
	if (cmpf(item, previous->content) >= 0)
		previous->right = ft_btree_create_node(item);
	else
		previous->left = ft_btree_create_node(item);
}
