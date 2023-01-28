/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:22:36 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/28 10:01:01 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	print_hex_low(size_t hex)
{
	if (hex >= 16)
		return (hex_lwr(hex / 16) + (int)write(1, &HEX_L[hex % 16], 1));
	else
		return ((int)write(1, &HEX_L[hex % 16], 1));
}

int	print_hex_cap(size_t hex)
{
	if (hex >= 16)
		return (hex_uppr(hex / 16) + (int)write(1, &HEX_U[hex % 16], 1));
	else
		return ((int)write(1, &HEX_U[hex % 16], 1));
}

int	print_ptr_hex(size_t ptr)
{
	if (ptr == 0)
		return ((int)write(1, "(nil)", 5));
	else
		return ((int)write(1, "0x", 2) + hex_lwr(ptr));
}
