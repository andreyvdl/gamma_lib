/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:12:40 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/24 21:47:30 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static t_btree	*new_node(void *item)
{
	t_btree	*node;

	node = (t_btree *)malloc(sizeof(t_btree));
	if (node == NIL)
		return (NIL);
	node->content = item;
	node->left = NIL;
	node->right = NIL;
	return (node);
}

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
		*root = new_node(item);
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
	new = new_node(item);
	if (new == NIL)
		return ;
	connect_new_node(previous, new, cmpf(new->content, previous->content));
}
