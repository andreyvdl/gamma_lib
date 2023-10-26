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

#include "libft.h"

static void	connect_new_node(t_btree *previous, t_btree *new, int result)
{
	if (result >= 0)
		previous->right = new;
	else
		previous->left = new;
}

void	ft_btree_insert_data(t_btree **root, void *item, \
							int (*cmpf)(void *, void *))
{
	t_btree	*current;
	t_btree	*previous;
	t_btree	*new;

	if (item == NIL || cmpf == NIL)
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
	new = ft_btree_create_node(item);
	if (new == NIL)
		return ;
	connect_new_node(previous, new, cmpf(new->content, previous->content));
}
