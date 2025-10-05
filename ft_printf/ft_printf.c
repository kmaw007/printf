/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwafi <kwafi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 17:19:05 by kwafi             #+#    #+#             */
/*   Updated: 2025/10/05 17:19:05 by kwafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	int	result;

	result = write(1, &c, 1);
	return (result);
}

int	ft_formats(va_list args, const char format)
{
	int	result;

	result = 0;
	if (format == 'c')
		result = ft_printchar(va_arg(args, int));
	else if (format == 's')
		result = ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		result = ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		result = ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		result = ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		result = ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		result = ft_printchar('%');
	if (result == -1)
		return (-1);
	return (result);
}

static int	handle_format(va_list args, const char *str, int *i, int *total)
{
	int	result;

	result = ft_formats(args, str[++(*i)]);
	if (result == -1)
		return (-1);
	*total += result;
	return (0);
}

static int	print_char_and_update(char c, int *total)
{
	int	result;

	result = ft_printchar(c);
	if (result == -1)
		return (-1);
	*total += result;
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		total;
	va_list	args;

	i = 0;
	total = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (handle_format(args, str, &i, &total) == -1)
				return (-1);
		}
		else if (print_char_and_update(str[i], &total) == -1)
			return (-1);
		i++;
	}
	va_end(args);
	return (total);
}
