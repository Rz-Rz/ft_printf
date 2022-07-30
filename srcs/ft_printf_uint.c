/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:30:41 by kdhrif            #+#    #+#             */
/*   Updated: 2022/07/30 17:07:05 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_uint(t_print *tab)
{
	int				len;
	unsigned int	nb;

	nb = va_arg(tab->args, unsigned int);
	len = ft_uintlen(nb);
	if (tab->zero && tab->dash)
		tab->zero = 0;
	if (tab->zero && tab->pnt)
		tab->zero = 0;
	if (tab->sign)
		tab->minwidth--;
	if ((tab->maxwidth > 0 && tab->maxwidth > len) || (tab->minwidth > 0
			&& tab->minwidth > len))
	{
		if (tab->dash)
			ft_print_uint_left(tab, nb, len);
		else
			ft_print_uint_right(tab, nb, len);
	}
	else
		ft_putunbr(nb, tab);
}

void	ft_putunbr(unsigned int nb, t_print *tab)
{
	if (tab->sign == 1 && !tab->is_neg)
	{
		tab->tl += ft_putchar('+');
		tab->sign--;
	}
	if (tab->space_flag == 1 && !tab->is_neg)
	{
		tab->tl += ft_putchar(' ');
		tab->space_flag--;
	}
	if (tab->pnt && tab->minwidth == 0 && nb == 0)
	{
		if (tab->maxwidth > 0)
			ft_print_spaces(tab);
		return ;
	}
	if (nb >= 10)
	{
		ft_putunbr(nb / 10, tab);
		tab->tl += ft_putchar(nb % 10 + '0');
	}
	else
		tab->tl += ft_putchar(nb + '0');
}

int	ft_uintlen(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

void	ft_print_uint_left(t_print *tab, unsigned int nb, int len)
{
	int	i;

	i = 0;
	if (tab->minwidth > len)
	{
		ft_print_minwidth(tab, len);
		ft_putunbr(nb, tab);
		ft_print_maxwidthmin(tab);
	}
	else
	{
		ft_putunbr(nb, tab);
		if (tab->zero || (tab->pnt && tab->minwidth != 0))
		{
			while (i < tab->minwidth - len)
				i += ft_print_zero(tab);
			i = 0;
			if (tab->maxwidth > len)
				while (i < tab->maxwidth - len)
					i += ft_print_spaces(tab);
		}
		else
			ft_print_maxwidth(tab, len, ' ');
	}
}

void	ft_print_uint_right(t_print *tab, unsigned int nb, int len)
{
	int	i;

	i = 0;
	if (tab->minwidth > len)
	{
		ft_print_maxwidthmin(tab);
		ft_print_minwidth(tab, len);
		ft_putunbr(nb, tab);
	}
	else
	{
		if (tab->zero || (tab->pnt && tab->minwidth != 0))
		{
			if (tab->pnt && tab->minwidth != 0)
				ft_print_minwidth(tab, len);
			else if (tab->zero && tab->maxwidth > len)
				ft_print_maxwidth(tab, len, '0');
			if (tab->maxwidth > len && !tab->zero)
				ft_print_maxwidth(tab, len, ' ');
		}
		else
			while (i < tab->maxwidth - len)
				i += ft_print_spaces(tab);
		ft_putunbr(nb, tab);
	}
}
