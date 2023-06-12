/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:16:27 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/11 18:08:12 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Prints a string to the standard output;
 * 
 * @param str A pointer to the string to be printed;
 */
void	ft_putstr(char *str)
{
	if (str == 0x0)
		return ;
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}
