/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrome <marcrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 09:57:47 by marcrome          #+#    #+#             */
/*   Updated: 2024/08/27 10:31:56 by marcrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == '%')
		count += ft_print_char('%');
	else if (specifier == 'c')
		count += ft_print_char(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(ap, char *));
	else if (specifier == 'p')
		count += ft_print_pointer(va_arg(ap, void *));
	else if (specifier == 'i' || specifier == 'd')
		count += ft_print_digit_simple((long long int)(va_arg(ap, int)), 10);
	else if (specifier == 'u')
		count += ft_print_digit((unsigned long long int)
				(va_arg(ap, unsigned int)), 10, specifier);
	else if (specifier == 'x' || specifier == 'X')
		count += ft_print_digit((unsigned long long int)
				(va_arg(ap, unsigned int)), 16, specifier);
	else if (specifier == 'o')
		count += ft_print_digit((unsigned long long int)
				(va_arg(ap, unsigned int)), 8, specifier);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += ft_print_format(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
