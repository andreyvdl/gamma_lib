/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_suffix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:35:48 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/17 16:38:06 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/**
 * @brief Call a function to apply a fix after going through all nodes;
 * 
 * @param root The root of the tree;
 * @param applyf The function to apply the fix;
**/
void	ft_btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL || applyf == NULL)
		return ;
	ft_btree_apply_suffix(root->left, applyf);
	ft_btree_apply_suffix(root->right, applyf);
	applyf(root->content);
}
