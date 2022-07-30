/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printhex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:10:15 by kdhrif            #+#    #+#             */
/*   Updated: 2022/07/30 13:35:29 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_hex(t_print *tab)
{
	unsigned int	nb;
	int				len;

	nb = va_arg(tab->args, unsigned int);
	ft_printhex_checker(tab, nb);
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
		ft_printhex_flags(tab, nb);
		ft_putnbr_hex(nb, tab);
		tab->tl += len;
	}
}

void	ft_printhex_checker(t_print *tab, int nb)
{
	if (tab->hash && nb != 0)
		tab->maxwidth -= 2;
	if (tab->is_neg)
		tab->maxwidth--;
}

void	ft_printhex_zero(t_print *tab)
{
	int	i;

	i = 0;
	if (tab->maxwidth >= 1)
		while (i < tab->maxwidth)
			i += ft_print_spaces(tab);
	else
		return ;
}

void	ft_print_hex_right(t_print *tab, int len, unsigned long long nb)
{
	if (tab->pnt && tab->minwidth > tab->maxwidth)
		ft_printhex_flagsplusminwidth(tab, nb, len);
	else if (tab->pnt && tab->minwidth < tab->maxwidth)
	{
		if (tab->minwidth > len)
			ft_print_maxwidthmin(tab);
		if (tab->minwidth < len)
			ft_print_maxwidth(tab, len, ' ');
		ft_printhex_flags(tab, nb);
		ft_print_minwidth(tab, len);
	}
	else if (tab->zero)
	{
		ft_printhex_flags(tab, nb);
		ft_print_maxwidth(tab, len, '0');
	}
	else
	{
		ft_print_maxwidth(tab, len, ' ');
		ft_printhex_flags(tab, nb);
	}
	ft_putnbr_hex(nb, tab);
	tab->tl += len;
}

void	ft_print_hex_left(t_print *tab, int len, unsigned long long nb)
{
	if (tab->minwidth > len)
	{
		ft_printhex_flags(tab, nb);
		ft_print_minwidth(tab, len);
		ft_putnbr_hex(nb, tab);
		ft_print_maxwidthmin(tab);
	}
	else
	{
		ft_printhex_flags(tab, nb);
		ft_putnbr_hex(nb, tab);
		if (tab->zero || (tab->pnt && tab->minwidth != 0))
		{
			ft_print_minwidth(tab, len);
			if (tab->maxwidth > len)
				ft_print_maxwidth(tab, len, ' ');
		}
		else
			ft_print_maxwidth(tab, len, ' ');
	}
	tab->tl += len;
}
