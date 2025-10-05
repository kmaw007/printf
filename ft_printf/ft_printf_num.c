/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwafi <kwafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:33:15 by kwafi             #+#    #+#             */
/*   Updated: 2025/10/05 17:26:34 by kwafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	get_num_len(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	num = n;
	len = get_num_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		len--;
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

static int	put_number(long n)
{
	int		result;
	char	c;

	if (n >= 10)
		if (put_number(n / 10) == -1)
			return (-1);
	c = (n % 10) + '0';
	result = write(1, &c, 1);
	return (result);
}

static int	handle_negative(int n, int *len)
{
	*len = 1;
	if (write(1, "-", 1) == -1)
		return (-1);
	if (n == -2147483648)
		return (put_number(2147483648L));
	return (put_number(-((long)n)));
}

int	ft_printnbr(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		return (handle_negative(n, &len));
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	return (put_number(n));
}
