/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:36:36 by kdhrif            #+#    #+#             */
/*   Updated: 2022/07/30 14:03:48 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_printint_flagsplusminwidth(t_print *tab, int nb, int len)
{
	ft_printflags(tab, nb);
	ft_print_minwidth(tab, len);
}

void	ft_printptr_nil(t_print *tab)
{
	int	i;

	i = 0;
	while (i < tab->maxwidth - 5)
		i += ft_print_spaces(tab);
	tab->tl += ft_putstr("(nil)");
}

void	ft_printstr_putstrwidth(t_print *tab, char *str, int len)
{
	if (tab->dash)
	{
		tab->tl += ft_putstr(str);
		ft_strwidth(tab, tab->maxwidth - len);
	}
	else
	{
		ft_strwidth(tab, tab->maxwidth - len);
		tab->tl += ft_putstr(str);
	}
}
