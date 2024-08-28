/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrome <marcrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:32:49 by marcrome          #+#    #+#             */
/*   Updated: 2024/08/27 10:33:23 by marcrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	ft_print_digit(unsigned long long int n,
		int base, char specifier)
{
	int		count;
	char	*symbols;

	if (specifier == 'x')
		symbols = "0123456789abcdef";
	else if (specifier == 'X')
		symbols = "0123456789ABCDEF";
	else if (specifier == 'u')
		symbols = "0123456789";
	else
		return (-1);
	if (n < (unsigned long long)base)
		return (ft_print_char(symbols[n]));
	else
	{
		count = ft_print_digit(n / base, base, specifier);
		return (count + ft_print_digit(n % base, base, specifier));
	}
}
