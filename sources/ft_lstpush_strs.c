/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush_strs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:51:22 by adantas-          #+#    #+#             */
/*   Updated: 2022/12/12 21:01:53 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstpush_strs(int size, char **strs)
{
	t_list	*lst;
	t_list	*tmp;

	lst = 0x0;
	while (size >= 0)
	{
		tmp = ft_lstnew(strs[size]);
		ft_lstadd_back(&lst, tmp);
		size--;
	}
	return (&lst);
}
