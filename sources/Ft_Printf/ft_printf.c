/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:34:50 by adantas-          #+#    #+#             */
/*   Updated: 2023/06/18 13:34:21 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	loop_through_string(const char *string, va_list arg_list);

/**
 * @brief My version of the printf function;
 * 			It accepts the following flags: cspdiuxX%;
 * 			Any invalid flag will print % plus the invalid flag;
 * @attention If too many characters are written it can cause an overflow;
 * 
 * @param string A pointer to the string to be printed;
 * @param ... The variables and/or functions return to be printed;
 * @return The total of characters printed (int); Or -1 if the string is NULL;
 */
int	ft_printf(const t_str str, ...)
{
	int		count;
	va_list	a_list;

	if (str == NIL)
		return (-1);
	va_start(a_list, str);
	count = loop_through_string(str, a_list);
	va_end(a_list);
	return (count);
}
