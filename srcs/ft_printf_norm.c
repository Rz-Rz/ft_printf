/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_norm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 16:13:18 by kdhrif            #+#    #+#             */
/*   Updated: 2022/07/30 13:27:17 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_checkflags(t_print *tab, int i, const char *format)
{
	if (format[i] == '.' && i++)
		tab->pnt = 1;
	if (format[i] == '-' && i++)
		tab->dash = 1;
	if (format[i] == '0' && i++)
		tab->zero = 1;
	if (format[i] == ' ' && i++)
		tab->space_flag = 1;
	if (format[i] == '+' && i++)
		tab->sign = 1;
	if (format[i] == '#' && i++)
		tab->hash = 1;
	return (i);
}

int	ft_printf_checkflagint(t_print *tab, int i, char *nb, const char *format)
{
	int	j;

	j = 0;
	ft_bzero(nb, 11);
	while (ft_isnum(format[i]))
		nb[j++] = format[i++];
	tab->minwidth = ft_atoi(nb);
	return (i);
}

int	ft_printf_checkflagint2(t_print *tab, int i, char *nb, const char *format)
{
	int	j;

	j = 0;
	while (ft_isnum(format[i]))
		nb[j++] = format[i++];
	tab->maxwidth = ft_atoi(nb);
	return (i);
}
