/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfmt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 20:02:13 by adantas-          #+#    #+#             */
/*   Updated: 2023/10/25 23:47:38 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	printf_get_flag(char byte)
{
	if (byte == 'c')
		return (1);
	else if (byte == 's')
		return (2);
	else if (byte == 'i' || byte == 'd')
		return (3);
	else if (byte == 'u')
		return (4);
	else if (byte == 'p')
		return (5);
	else if (byte == 'x')
		return (6);
	else if (byte == 'X')
		return (7);
	else if (byte == '%' || byte == 0)
		return (8);
	return (0);
}

int	ft_printf(t_str fmt, ...)
{
	va_list	ap;
	size_t	i;
	t_list	*lst;

	lst = NIL;
	if (fmt == NIL)
		return (-1);
	va_start(ap, fmt);
	i = 0;
	while (fmt[i] != 0)
	{
		if (fmt[i] == '%')
		{
			if (printf_copy_to_lst(&lst, fmt, i) \
			|| printf_add_flag_to_lst(&lst, ap, printf_get_flag(fmt[i + 1])))
				return (printf_clear_lst(&lst, ap));
			fmt = &fmt[i + 1 + (fmt[i + 1] != 0)];
			i = -1;
		}
		++i;
	}
	va_end(ap);
	return (printf_lst(&lst, fmt, i));
}
