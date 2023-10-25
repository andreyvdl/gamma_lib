/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search_item.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:20:45 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/24 22:11:07 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_btree_search_item(t_btree *root, void *data_ref, \
							int (*cmpf)(void *, void *))
{
	void	*content;

	if (root == NIL || data_ref == NIL || cmpf == NIL)
		return (NIL);
	content = NIL;
	content = ft_btree_search_item(root->left, data_ref, cmpf);
	if (content != NIL)
		return (content);
	if (cmpf(root->content, data_ref) == 0)
		return (root->content);
	content = ft_btree_search_item(root->right, data_ref, cmpf);
	if (content != NIL)
		return (content);
	return (NIL);
}
