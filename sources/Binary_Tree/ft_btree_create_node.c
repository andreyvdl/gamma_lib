/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_create_node.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:29:04 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/06 02:00:39 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

t_btree	*ft_btree_create_node(void *item)
{
	t_btree	*new;

	new = malloc(sizeof(t_btree));
	if (new == NIL)
		return (NIL);
	new->content = item;
	new->left = NIL;
	new->right = NIL;
	return (new);
}
