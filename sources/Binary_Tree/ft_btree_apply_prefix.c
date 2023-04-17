/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_prefix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:25:16 by adantas-          #+#    #+#             */
/*   Updated: 2023/04/17 16:30:43 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Call a function to apply a fix before going to the next node;
 * 
 * @param root The root of the tree;
 * @param applyf The function that will apply the fix;
**/
void	ft_btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL || applyf == NULL)
		return ;
	applyf(root->content);
	ft_btree_apply_prefix(root->left, applyf);
	ft_btree_apply_prefix(root->right, applyf);
}
