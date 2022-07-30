/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:07:10 by kdhrif            #+#    #+#             */
/*   Updated: 2022/07/30 16:19:48 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_strlen(char *s)
{
	char	*str;

	str = s;
	while (*str)
		str++;
	return (str - s);
}

int	ft_checkflags_zero(const char *format, int i)
{
	if (format[i - 1] == '%')
		return (1);
	if (format[i - 1] == '+')
		return (1);
	if (format[i - 1] == ' ')
		return (1);
	if (format[i - 1] == '#')
		return (1);
	return (0);
}
