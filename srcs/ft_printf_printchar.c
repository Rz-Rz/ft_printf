/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printchar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:54:19 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/12 18:15:23 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void ft_print_char(t_print *tab)
{
	char a;

	a = va_arg(tab->args, int);
	if (tab->zero_flag)
		tab->zero_flag = 0;
	if (tab->space_flag)
		tab->space_flag = 0;
	if (tab->pnt)
		tab->pnt = 0;
	if (tab->dash && tab->maxwidth)
	{
		tab->tl += ft_putchar(a);
		ft_strwidth(tab);
		return;
	}
	else if (tab->maxwidth && !tab->dash)
	{
		ft_strwidth(tab);
		tab->tl += ft_putchar(a);
		return;
	}
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
	int i;
	int j;
	int k;
	char *str;

	i = 0;
	j = 0;
	k = 0;
	str = ft_strnew(tab->maxwidth - 1);
	while (i < tab->maxwidth - 1)
	{
		str[i] = ' ';
		i++;
	}
	if (tab->zero_flag)
	{
		while (j < tab->maxwidth - 1)
		{
			str[j] = '0';
			j++;
		}
	}
	tab->tl += ft_putstr(str);
	free(str);
}
