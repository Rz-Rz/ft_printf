/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <kdhrif@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:00:47 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/29 15:44:25 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	neg;

	nb = 0;
	neg = 0;
	while ((*nptr >= 9 && *nptr <= 13) || (*nptr == ' '))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			neg++;
	while (*nptr >= '0' && *nptr <= '9')
		nb = nb * 10 + *nptr++ - '0';
	if (neg)
		nb *= -1;
	return (nb);
}
