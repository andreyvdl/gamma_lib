/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_infix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:23:52 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/10 21:45:23 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Call a function that apply a fix after going through all left nodes;
 * 
 * @param root A pointer to the root of the tree;
 * @param applyf A pointer to the function that will apply the fix;
**/
void	ft_btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (root == 0x0 || applyf == 0x0)
		return ;
	ft_btree_apply_infix(root->left, applyf);
	applyf(root->content);
	ft_btree_apply_infix(root->right, applyf);
}
