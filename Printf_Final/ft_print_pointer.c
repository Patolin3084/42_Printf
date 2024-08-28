/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcrome <marcrome@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 18:17:20 by marcrome          #+#    #+#             */
/*   Updated: 2024/08/27 09:42:24 by marcrome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int	ft_print_pointer(void *ptr)
{
	unsigned long long	address;
	char				specifier;

	specifier = 'x';
	if (!ptr)
	{
		return (write(1, "(nil)", 5));
	}
	address = (unsigned long long)ptr;
	return (write(1, "0x", 2) + ft_print_digit(address, 16, specifier));
}
