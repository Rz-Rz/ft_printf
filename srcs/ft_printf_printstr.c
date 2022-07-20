/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printstr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:29:33 by kdhrif            #+#    #+#             */
/*   Updated: 2022/07/20 20:34:17 by kdhrif           ###   ########.fr       */
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
	i = 0;
	if (!str) 
		i = ft_print_nullstr(tab);
	if (i != -1)
		len = ft_strlen(str);
	if (tab->zero || tab->hash)
		ft_reset_str(tab);
	if (!tab->dash)
		ft_printstr_norm(tab, str, len);
	if (tab->maxwidth > len && tab->dash && i != -1)
		ft_strwidth(tab, tab->maxwidth - len);
}

void ft_printstr_norm(t_print *tab, char *str, int len)
{
	int i;

	i = 0;
	if (!tab->pnt)
	{
		if (tab->maxwidth > len)
		{
			ft_strwidth(tab, tab->maxwidth - len);
			tab->tl += ft_putstr(str);
		}
		else 
			tab->tl += ft_putstr(str);
	}
	else if (tab->pnt)
	{
		if (tab->maxwidth > len && tab->minwidth >= len)
		{
			ft_strwidth(tab, tab->maxwidth - len);
			tab->tl += ft_putstr(str);
			return;
		}
		else if (tab->minwidth < len)
		{
			ft_strwidth(tab, (tab->maxwidth) - (len - tab->minwidth));
			while (i < tab->minwidth)
				tab->tl += ft_putchar(str[i++]);
		}
		/* if (tab->minwidth >= len || (tab->minwidth == 0 && tab->pnt == 0)) */
	}
}

int ft_putstr(char *s)
{
	int i;

		i = 0;
		if (!s)
			return (0);
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

int ft_print_nullstr(t_print *tab)
{
	char str[6];

	ft_strcpy(str, "(null)", 6);
	if (!tab->minwidth && !tab->pnt)
		tab->minwidth = ft_strlen(str);
	if (tab->maxwidth && !tab->dash)
	{
		if (tab->minwidth >= 6)
			ft_strwidth(tab, tab->maxwidth - 6);
		else
			ft_strwidth(tab, tab->maxwidth);
	}
	if (tab->minwidth >= 6)
		tab->tl += ft_putstr(str);
	if (tab->dash && tab->maxwidth > 6)
	{
		if (tab->minwidth >= 6)
			ft_strwidth(tab, tab->maxwidth - 6);
		else
			ft_strwidth(tab, tab->maxwidth);
	}
	return (-1);
}
