/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:31:59 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/06 13:46:49 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_struct {
  va_list args;
  int maxwidth;
  int minwidth;
  int precision;
  int zero_pdg;
  int pnt;
  int dash;
  int tl;
  int sign;
  int is_zero;
  int perc;
  int space_flag;
  int hash;

} t_print;

void ft_print_char(t_print *tab);
void choose_conversion(t_print *tab, const char *format, int i);
void	ft_bzero(char *s, size_t n);
void	*ft_memset(char *s, int c, size_t n);

int ft_printf(const char *format, ...);
int ft_eval_format(t_print *tab, const char *format, int i);
int check_flags(char c);
int ft_putstr(char *s);
int ft_putchar(char c);
int ft_isnum(char c);
int	ft_atoi(const char *nptr);

