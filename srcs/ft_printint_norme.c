/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint_norme.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:01:47 by kdhrif            #+#    #+#             */
/*   Updated: 2022/07/22 13:01:17 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_printint_zero(t_print *tab, int nb, int len)
{
	if (!tab->pnt)
	{
		if ((tab->maxwidth > 0 && tab->maxwidth > len))
		{
			if (tab->dash == 1)
				ft_print_int_left(tab, nb, len);
			else
				ft_print_int_right(tab, nb, len);
		}
		else 
			ft_putnbr(nb, tab);
	}
	else if (tab->pnt)
	{

	}


}
