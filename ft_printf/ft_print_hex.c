/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwafi <kwafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:13:07 by kwafi             #+#    #+#             */
/*   Updated: 2025/10/05 17:13:07 by kwafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned int num)
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

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_printchar(num + '0');
		else
		{
			if (format == 'x')
				ft_printchar(num - 10 + 'a');
			if (format == 'X')
				ft_printchar(num - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	int		result;
	char	*hex;

	if (format == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (num >= 16)
	{
		result = ft_print_hex(num / 16, format);
		if (result == -1)
			return (-1);
		result += ft_printchar(hex[num % 16]);
		if (result == -1)
			return (-1);
		return (result);
	}
	result = ft_printchar(hex[num % 16]);
	return (result);
}
