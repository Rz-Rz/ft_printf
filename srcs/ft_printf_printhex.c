/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printhex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:10:15 by kdhrif            #+#    #+#             */
/*   Updated: 2022/07/28 15:52:02 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_print_hex(t_print *tab)
{
	unsigned int nb;
	int len;

	nb = va_arg(tab->args, unsigned int);
	if (tab->hash && nb != 0)
		tab->maxwidth -= 2;
	if (tab->is_neg)
		tab->maxwidth--;
	if (nb == 0 && tab->pnt && tab->minwidth == 0)
	{
		ft_printhex_zero(tab);
		return ;
	}
	len = ft_hexlen(nb);
	if (tab->maxwidth > len || tab->minwidth > len)
	{
		if (tab->dash)
			ft_print_hex_left(tab, len, nb);
		else
			ft_print_hex_right(tab, len, nb);
	}
	else 
	{
		if (tab->hash && tab->upper && nb != 0)
			tab->tl += ft_putstr("0X");
		else if (tab->hash && !tab->upper && nb != 0)
			tab->tl += ft_putstr("0x");
		ft_putnbr_hex(nb, tab);
		tab->tl += len;
	}
}

void ft_printhex_zero(t_print *tab)
{
	int i;

	i = 0;
	if (tab->maxwidth >= 1)
		while (i < tab->maxwidth)
			i += ft_print_spaces(tab);
	else
		return;
}

void ft_print_hex_right(t_print *tab, int len, unsigned long long nb)
{
	int i;

	i = 0;
	if (tab->pnt && tab->minwidth > tab->maxwidth)
	{
		ft_printhex_flags(tab, nb);
		while (i < tab->minwidth - len)
			i += ft_print_zero(tab);
	}
	else if (tab->pnt && tab->minwidth < tab->maxwidth)
	{
		if (tab->minwidth > len)
			while (i < tab->maxwidth - tab->minwidth)
				i += ft_print_spaces(tab);
		if (tab->minwidth < len) 
			while (i < tab->maxwidth - len)
				i += ft_print_spaces(tab);
		ft_printhex_flags(tab, nb);
		i = 0;
		while (i < tab->minwidth - len)
			i += ft_print_zero(tab);
	}
	else if (tab->zero)
	{
		ft_printhex_flags(tab, nb);
		while (i < tab->maxwidth - len)
			i += ft_print_zero(tab);
	}
	else
	{
		while (i < tab->maxwidth - len)
			i += ft_print_spaces(tab);
		ft_printhex_flags(tab, nb);
	}
	ft_putnbr_hex(nb, tab);
	tab->tl += len;
}

void ft_print_hex_left(t_print *tab, int len, unsigned long long nb)
{
	int i;

	i = 0;
	if (tab->minwidth > len) 
	{
		ft_printhex_flags(tab, nb);
		while (i < tab->minwidth - len)
			i += ft_print_zero(tab);
		ft_putnbr_hex(nb, tab);
		i = 0;
		while (i < tab->maxwidth - (tab->minwidth + tab->is_neg))
			i += ft_print_spaces(tab);
	}
	else {
		ft_printhex_flags(tab, nb);	
		ft_putnbr_hex(nb, tab);
		if (tab->zero || (tab->pnt && tab->minwidth != 0))
		{
			while (i < tab->minwidth - len )
				i += ft_print_zero(tab);
			i = 0;
			if (tab->maxwidth > (len))
				while (i < tab->maxwidth - (len + tab->is_neg))
					i += ft_print_spaces(tab);
		}
		else
			while (i < tab->maxwidth - (len + tab->is_neg))
				i += ft_print_spaces(tab);
	}
	tab->tl += len;
}
