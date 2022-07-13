/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printhex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:10:15 by kdhrif            #+#    #+#             */
/*   Updated: 2022/07/13 19:10:09 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_print_downhex(t_print *tab)
{
	unsigned int nb;
	int len;

	nb = va_arg(tab->args, unsigned int);
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
		ft_putnbr_hex(nb, tab);
		tab->tl += len;
	}
	
}

void ft_print_upperhex(t_print *tab) 
{
	unsigned int nb;
	int len;
	
	nb = va_arg(tab->args, unsigned int);
	len = ft_hexlen(nb);
	tab->upper = 1;
	if (tab->maxwidth > len)
	{
		if (tab->dash)
			ft_print_hex_left(tab, len, nb);
		else
			ft_print_hex_right(tab, len, nb);
	}
	else 
	{
		ft_putnbr_hex(nb, tab);
		tab->tl += len;
	}
}
