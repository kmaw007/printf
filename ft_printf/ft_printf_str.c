/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwafi <kwafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:33:15 by kwafi             #+#    #+#             */
/*   Updated: 2025/10/05 17:13:48 by kwafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_printstr(char *str)
{
	int	i;
	int	result;

	if (!str)
	{
		result = write(1, "(null)", 6);
		return (result);
	}
	i = 0;
	while (str[i])
	{
		result = write(1, &str[i], 1);
		if (result == -1)
			return (-1);
		i++;
	}
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
