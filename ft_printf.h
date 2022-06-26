/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdhrif <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:31:59 by kdhrif            #+#    #+#             */
/*   Updated: 2022/06/26 15:08:54 by kdhrif           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_struct {
  va_list args;
  int maxwidth;
  int minwidth;
  int precision;
  int zero;
  int pnt;
  int dash;
  int tl;
  int sign;
  int is_neg;
  int is_zero;
  int perc;
  int space_flag;
  int hash;

} t_print;

void ft_print_char(t_print *tab);
void choose_conversion(t_print *tab, const char *format, int i);
void	ft_bzero(char *s, size_t n);
void	*ft_memset(char *s, int c, size_t n);
void ft_strwidth(t_print *tab);
void ft_printstr(t_print *tab);
void ft_print_integer(t_print *tab);
void ft_print_int_right(t_print *tab, int nb, int len);
void ft_print_int_left(t_print *tab, int nb, int len);
void ft_putnbr(int nb, t_print *tab);
void ft_print_ptr(t_print *tab);
void ft_putnbr_hex(unsigned long long n);
void ft_print_hex_left(t_print *tab, int len, unsigned long long ptr);
void ft_print_hex_right(t_print *tab, int len, unsigned long long ptr);
void ft_print_uint(t_print *tab);
void ft_print_uint_right(t_print *tab, unsigned int nb, int len);
void ft_print_uint_left(t_print *tab, unsigned int nb, int len);
void ft_putunbr(unsigned int nb, t_print *tab);

int ft_uintlen(unsigned int nb);
int ft_hexlen(unsigned long long n);
int ft_printf(const char *format, ...);
int ft_eval_format(t_print *tab, const char *format, int i);
int check_flags(char c);
int ft_putstr(char *s);
int ft_putchar(char c);
int ft_isnum(char c);
int	ft_atoi(const char *nptr);
int ft_strlen(char *s);
int ft_intlen(int nb);
int ft_print_spaces(t_print *tab);
int ft_print_zero(t_print *tab);

char *ft_strnew(size_t size);
