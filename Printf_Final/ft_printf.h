/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrome <marcrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:17:31 by marcrome          #+#    #+#             */
/*   Updated: 2024/08/27 09:29:18 by marcrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int				ft_printf(const char *format, ...);
int				ft_print_str(char *str);
int				ft_print_char(int c);
long long int	ft_print_pointer(void *ptr);
long long int	ft_print_digit(unsigned long long int n,
					int base, char specifier);
int				ft_print_digit_simple(long long n, int base);

#endif