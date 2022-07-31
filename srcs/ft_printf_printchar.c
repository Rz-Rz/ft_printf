/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_printchar.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:54:19 by kdhrif            #+#    #+#             */
/*   Updated: 2022/07/31 17:51:31 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_print_char(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	if (tab->zero)
		tab->zero = 0;
	if (tab->space_flag)
		tab->space_flag = 0;
	if (tab->pnt)
		tab->pnt = 0;
	if (tab->dash && tab->maxwidth)
	{
		tab->maxwidth--;
		tab->tl += ft_putchar(a);
		ft_strwidth(tab, tab->maxwidth);
		return ;
	}
	else if (!tab->dash && tab->maxwidth)
	{
		tab->maxwidth--;
		ft_strwidth(tab, tab->maxwidth);
		tab->tl += ft_putchar(a);
		return ;
	}
	tab->tl += ft_putchar(a);
}

void	ft_strwidth(t_print *tab, int max)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (max < 0)
		max = 0;
	str = ft_strnew(max);
	while (i < max)
	{
		str[i] = ' ';
		i++;
	}
	if (tab->zero)
	{
		while (j < max)
		{
			str[j] = '0';
			j++;
		}
	}
	tab->tl += ft_putstr(str);
	free(str);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
