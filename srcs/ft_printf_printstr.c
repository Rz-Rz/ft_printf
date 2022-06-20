/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:29:33 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/20 12:26:56 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>


void ft_printstr(t_print *tab)
{
	int i;
	int len;
	char *str;

	str = va_arg(tab->args, char*);
	if (!str) 
		str = "(null)";
	len = ft_strlen(str);
	i = 0;
	if (tab->zero || tab->hash)
	{
		tab->zero = 0;
		tab->hash = 0;
	}
	if (tab->minwidth && tab->minwidth < len)
		len = tab->minwidth;
	if (tab->maxwidth > len && !tab->dash)
	{
		tab->maxwidth -= len;
		ft_strwidth(tab);
	}
	while (i < len)
	{
		tab->tl += ft_putchar(str[i]);
		i++;
	}
	if (tab->maxwidth > len && tab->dash)
	{
		tab->maxwidth -= len;
		ft_strwidth(tab);
	}
}

int ft_putchar(char c)
{
	return	(write(1, &c, 1));
}

int ft_putstr(char *s)
{
		int i;

		i = 0;
		while (s[i])
				write(1, &s[i++], 1);
		return (i);
}

int ft_strlen(char *s)
{
	char *str;

	str = s;
		while (*str)
				str++;
		return (str - s);
}
