/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwafi <kwafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:25:16 by kwafi             #+#    #+#             */
/*   Updated: 2025/10/05 17:25:16 by kwafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n)
{
	char	c;
	int		result;

	if (n >= 10)
	{
		result = ft_print_unsigned(n / 10);
		if (result == -1)
			return (-1);
		c = (n % 10) + '0';
		if (write(1, &c, 1) == -1)
			return (-1);
		return (result + 1);
	}
	c = n + '0';
	return (write(1, &c, 1));
}
