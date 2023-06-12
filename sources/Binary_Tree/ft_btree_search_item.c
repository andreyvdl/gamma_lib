/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search_item.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:20:45 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/10 21:48:56 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Search an item in the binary tree based on the data reference with the
 * 			function cmpf;
 * 
 * @param root A pointer to the root of the binary tree;
 * @param data_ref A pointer to the data reference;
 * @param cmpf A pointer to the function that will compare the data reference;
 * @returns NULL if the data reference can't be found or a pointer to the item
 * 			found (void *);
 */
void	*ft_btree_search_item(t_btree *root, void *data_ref, \
								int (*cmpf)(void *, void *))
{
	void	*content;

	content = 0x0;
	if (root == 0x0 || data_ref == 0x0 || cmpf == 0x0)
		return (0x0);
	content = ft_btree_search_item(root->left, data_ref, cmpf);
	if (content != 0x0)
		return (content);
	if (cmpf(root->content, data_ref) == 0)
		return (root->content);
	content = ft_btree_search_item(root->right, data_ref, cmpf);
	if (content != 0x0)
		return (content);
	return (0x0);
}
