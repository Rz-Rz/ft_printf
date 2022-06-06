/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printfunc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:54:19 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/04 17:19:54 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_print_char(t_print *tab)
{
	char a;

	a = va_arg(tab->args, int);
	if (tab->pnt)
			ft_strwidth(tab);
	tab->tl += ft_putchar(a);

	/* ft_update_tab(tab, 1); //calculate special cases and length */
	/* if (tab->width && !tab->dash) //if width and not - flag */ 
	/* 	ft_right_cs(tab, 0); //Handle right alignment */
	/* tab->tl += write(1, &a, 1); //print char */
	/* if (tab->width && tab->dash) //if width and - flag */
	/* 	ft_left_cs(tab, 0); */

}

void ft_strwidth(t_print *tab)
{

}
