/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printchar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:54:19 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/30 11:06:10 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_print_char(t_print *tab)
{
	char a;

	a = va_arg(tab->args, int);
	if (tab->zero)
		tab->zero = 0;
	if (tab->space_flag)
		tab->space_flag = 0;
	if (tab->pnt)
		tab->pnt = 0;
	if (tab->dash && tab->maxwidth)
	{
		tab->maxwidth--;
		tab->tl += ft_putchar(a);
		ft_strwidth(tab);
		return;
	}
	else if (!tab->dash && tab->maxwidth)
	{
		tab->maxwidth--;
		ft_strwidth(tab);
		tab->tl += ft_putchar(a);
		return;
	}
	tab->tl += ft_putchar(a);
}

void ft_strwidth(t_print *tab)
{
	int i;
	int j;
	char *str;

	i = 0;
	j = 0;
	str = ft_strnew(tab->maxwidth);
	while (i < tab->maxwidth)
	{
		str[i] = ' ';
		i++;
	}
	if (tab->zero)
	{
		while (j < tab->maxwidth)
		{
			str[j] = '0';
			j++;
		}
	}
	tab->tl += ft_putstr(str);
	free(str);
}
