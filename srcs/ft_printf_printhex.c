/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printhex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:10:15 by kdhrif            #+#    #+#             */
/*   Updated: 2022/07/27 17:35:03 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_print_hex(t_print *tab)
{
	unsigned int nb;
	int len;

	nb = va_arg(tab->args, unsigned int);
	if (nb == 0 && ((tab->pnt && tab->minwidth == 0) || tab->maxwidth))
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
	printf("HERE\n");
	if (tab->pnt && tab->minwidth == 0 && !tab->dash)
	{
		if (tab->maxwidth > 1)
			while (i < tab->maxwidth)
				i += ft_print_spaces(tab);
		else
			return;
	}
	else if (tab->maxwidth && !tab->dash)
	{
		if (tab->maxwidth > 1)
			while (i < tab->maxwidth - 1)
				i += ft_print_spaces(tab);
		tab->tl += ft_putchar('0');

	}
	else if (tab->dash)
	{
		if (tab->maxwidth > 0 || tab->minwidth > 0)
			tab->tl += ft_putchar('0');
		if (tab->maxwidth > 2)
			while (i < tab->maxwidth - 1)
				i += ft_print_spaces(tab);

	}

}

void ft_print_hex_right(t_print *tab, int len, unsigned long long nb)
{
	int i;
	int hash;

	i = 0;
	hash = 0;
	if (tab->hash)
		hash = 2;
	if (tab->pnt && tab->minwidth > tab->maxwidth)
		while (i < tab->minwidth - (len + hash))
			i += ft_print_zero(tab);
	else if (tab->pnt && tab->minwidth < tab->maxwidth)
	{
		if (tab->minwidth > len)
			while (i < tab->maxwidth - (len + tab->is_neg + hash + (tab->minwidth - len)))
				i += ft_print_spaces(tab);
		else 
			while (i < tab->maxwidth - (len + tab->is_neg + hash))
				i += ft_print_spaces(tab);
		i = 0;
		while (i < tab->minwidth - (len + hash))
			i += ft_print_zero(tab);
	}
	else if (tab->zero)
	{
		while (i < tab->maxwidth - (len + tab->is_neg + hash))
			i += ft_print_zero(tab);
	}
	else
		while (i < tab->maxwidth - (len + tab->is_neg + hash))
			i += ft_print_spaces(tab);
	if (hash)
	{
		if (tab->upper && tab->hash && nb != 0)
			tab->tl += ft_putstr("0X");
		else if (nb != 0 && tab->hash)
			tab->tl += ft_putstr("0x");
	}
	ft_putnbr_hex(nb, tab);
	tab->tl += len;
}

void ft_print_hex_left(t_print *tab, int len, unsigned long long nb)
{
	int i;
	int hash;

	hash = 0;
	if (tab->hash)
		hash = 2;
	i = 0;
	if (tab->minwidth > len) 
	{
		if (hash)
		{
			if (tab->upper && tab->hash && nb != 0)
				tab->tl += ft_putstr("0X");
			else if (nb != 0 && tab->hash)
				tab->tl += ft_putstr("0x");
		}
		while (i < tab->minwidth - (len + hash))
			i += ft_print_zero(tab);
		ft_putnbr_hex(nb, tab);
		i = 0;
		while (i < tab->maxwidth - (tab->minwidth + tab->is_neg + hash))
			i += ft_print_spaces(tab);
	}
	else {
		if (hash)
		{
			if (tab->upper && tab->hash && nb != 0)
				tab->tl += ft_putstr("0X");
			else if (nb != 0 && tab->hash)
				tab->tl += ft_putstr("0x");
		}
		ft_putnbr_hex(nb, tab);
		if (tab->zero || (tab->pnt && tab->minwidth != 0))
		{
			while (i < tab->minwidth - (len + hash))
				i += ft_print_zero(tab);
			i = 0;
			if (tab->maxwidth > (len + hash))
				while (i < tab->maxwidth - (len + tab->is_neg + hash))
					i += ft_print_spaces(tab);
		}
		else
			while (i < tab->maxwidth - (len + tab->is_neg + hash))
				i += ft_print_spaces(tab);
	}
	tab->tl += len;
}
