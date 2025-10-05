/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwafi <kwafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:55:20 by kwafi             #+#    #+#             */
/*   Updated: 2025/10/05 12:55:20 by kwafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr_len(uintptr_t num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

int	ft_put_ptr(uintptr_t num)
{
	int	length;

	length = 0;
	if (num >= 16)
	{
		length += ft_put_ptr(num / 16);
		length += ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			length += ft_printchar(num + '0');
		else
			length += ft_printchar(num - 10 + 'a');
	}
	return (length);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_length;

	print_length = 0;
	print_length += write(1, "0x", 2);
	if (ptr == 0)
		print_length += write(1, "0", 1);
	else
		print_length += ft_put_ptr(ptr);
	return (print_length);
}
