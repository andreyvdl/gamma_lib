/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_insert_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:12:40 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/17 17:10:39 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static t_btree	*start_new_tree(void *item);

/**
 * @brief Insert new data in the position
 * 
 * @par gahgjahgjahgjsahgja
 */
void	ft_btree_insert_data(t_btree **root, void *item, \
int (*cmpf)(void *, void *))
{
	t_btree	*current;

	if (item == NULL || cmpf == NULL)
		return ;
	if (root == NULL)
	{
		*root = start_new_tree(item);
		return ;
	}
	current = *root;
	if (cmpf(item, current->content) >= 0)
		ft_btree_insert_data(&current->right, item, cmpf);
	else
		ft_btree_insert_data(&current->left, item, cmpf);
}

static t_btree	*start_new_tree(void *item)
{
	t_btree	*node;

	node = (t_btree)malloc(sizeof(t_btree));
	if (node == NULL)
		return (NULL);
	node->content = item;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
