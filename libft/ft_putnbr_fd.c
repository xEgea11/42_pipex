/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 02:24:29 by regea-go          #+#    #+#             */
/*   Updated: 2023/05/09 20:30:34 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		dash;
	char	modulo;

	if (n == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2", 1);
		n = 147483648;
	}
	if (n < 0)
	{
		n = -n;
		dash = '-';
		write (fd, &dash, 1);
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	modulo = n % 10 + 48;
	write(fd, &modulo, 1);
}
