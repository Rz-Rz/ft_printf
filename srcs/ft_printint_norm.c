/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint_norm.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 22:03:38 by kdhrif            #+#    #+#             */
/*   Updated: 2022/07/28 17:08:55 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_printint_checker(t_print *tab, int *nb, int *len)
{
	if (*nb == 0 && tab->pnt && !tab->minwidth)
		*len = 0;
	if (tab->zero && tab->dash)
		tab->zero = 0;
	if (tab->zero && tab->pnt)
		tab->zero = 0;
	if (*nb < 0)
		tab->is_neg = 1;
	if (tab->is_neg && tab->space_flag)
		tab->space_flag = 0;
	if (tab->space_flag && tab->sign)
		tab->space_flag = 0;
	if (tab->space_flag)
		tab->maxwidth--;
	if (tab->is_neg && !tab->sign)
		tab->maxwidth--;
	if (tab->sign)
		tab->maxwidth--;
}

void	ft_printflags(t_print *tab, int nb)
{
	if (nb < 0)
		ft_print_minus(tab);
	if (tab->sign && !tab->is_neg)
		ft_print_plus(tab);
	if (tab->space_flag && !tab->is_neg)
		ft_print_spaceflag(tab);
}

void	ft_printhex_flags(t_print *tab, int nb)
{
	if (tab->space_flag && !tab->is_neg)
		ft_print_spaceflag(tab);
	if (tab->hash && nb != 0)
		ft_printhex_hash(tab);
}
