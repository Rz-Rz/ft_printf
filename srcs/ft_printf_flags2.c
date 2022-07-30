/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:16:16 by kdhrif            #+#    #+#             */
/*   Updated: 2022/07/30 13:48:32 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_maxwidth(t_print *tab, int len, char opt)
{
	int	i;

	i = 0;
	if (opt == ' ')
		while (i < tab->maxwidth - len)
			i += ft_print_spaces(tab);
	else if (opt == '0')
		while (i < tab->maxwidth - len)
			i += ft_print_zero(tab);
}

void	ft_print_minwidth(t_print *tab, int len)
{
	int	i;

	i = 0;
	while (i < tab->minwidth - len)
		i += ft_print_zero(tab);
}

void	ft_print_maxwidthmin(t_print *tab)
{
	int	i;

	i = 0;
	while (i < tab->maxwidth - tab->minwidth)
		i += ft_print_spaces(tab);
}

void	ft_printhex_hash(t_print *tab)
{
	if (tab->hash && tab->upper)
		tab->tl += ft_putstr("0X");
	else if (tab->hash && !tab->upper)
		tab->tl += ft_putstr("0x");
}

void	ft_printhex_flagsplusminwidth(t_print *tab, int nb, int len)
{
	ft_printhex_flags(tab, nb);
	ft_print_minwidth(tab, len);
}
