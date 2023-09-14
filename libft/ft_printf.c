/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:46:43 by regea-go          #+#    #+#             */
/*   Updated: 2023/05/30 19:17:04 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	format(char const *fmt, va_list args, int i)
{
	int	size;

	size = 0;
	if (fmt[i] == 'c')
		size += ft_putchar_fd_printf(va_arg(args, int), 1);
	else if (fmt[i] == 's')
		size += ft_putstr_fd_printf(va_arg(args, char *), 1);
	else if (fmt[i] == 'p')
		size += ptrhx_printf(va_arg(args, unsigned long int));
	else if (fmt[i] == 'd')
		size += ft_putnbr_fd_printf(va_arg(args, int), 1);
	else if (fmt[i] == 'i')
		size += ft_putnbr_fd_printf(va_arg(args, int), 1);
	else if (fmt[i] == 'u')
		size += ft_putunbr_fd_printf(va_arg(args, unsigned int), 1);
	else if (fmt[i] == 'x')
		size += to_hex_printf(va_arg(args, unsigned int));
	else if (fmt[i] == 'X')
		size += to_hex_up_printf(va_arg(args, unsigned int));
	else if (fmt[i] == '%')
		size += ft_putchar_fd_printf(fmt[i], 1);
	return (size);
}

int	ft_printf(char const *fmt, ...)
{
	va_list		args;
	int			i;
	int			size;

	i = 0;
	size = 0;
	va_start(args, fmt);
	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			i++;
			size += format(fmt, args, i);
		}
		else if ((unsigned char)fmt[i] >= 0 && (unsigned char)fmt[i] <= 255)
			size += ft_putchar_fd_printf(fmt[i], 1);
		i++;
	}
	va_end(args);
	return (size);
}
