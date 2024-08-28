/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit_simple.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrome <marcrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 21:40:25 by marcrome          #+#    #+#             */
/*   Updated: 2024/08/27 09:51:59 by marcrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_digit_simple(long long n, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789";
	count = 0;
	if (n < 0)
	{
		count += ft_print_char('-');
		n = -n;
	}
	if (n < base)
	{
		count += ft_print_char(symbols[n]);
	}
	else
	{
		count += ft_print_digit_simple(n / base, base);
		count += ft_print_digit_simple(n % base, base);
	}
	return (count);
}
