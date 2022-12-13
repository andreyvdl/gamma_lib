/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply_prefix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:41:41 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/13 12:57:54 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root || !applyf)
		return ;
	applyf(root->content);
	ft_btree_apply_prefix(root->left, applyf);
	ft_btree_apply_prefix(root->right, applyf);
}
