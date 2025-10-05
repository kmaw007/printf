/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwafi <kwafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:14:33 by kwafi             #+#    #+#             */
/*   Updated: 2025/10/05 17:14:33 by kwafi            ###   ########.fr       */
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
	int	result;
	int	total;

	total = 0;
	result = write(1, "0x", 2);
	if (result == -1)
		return (-1);
	total += result;
	if (ptr == 0)
	{
		result = write(1, "0", 1);
		if (result == -1)
			return (-1);
		return (total + result);
	}
	result = ft_put_ptr(ptr);
	if (result == -1)
		return (-1);
	return (total + result);
}
