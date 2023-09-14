/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:06:00 by regea-go          #+#    #+#             */
/*   Updated: 2023/04/21 13:56:38 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	sign;
	int	value;

	sign = 1;
	value = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 45)
	{
		sign = -1;
		str++;
	}
	else if (*str == 43)
	{
		sign = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		value = value * 10 + *str - '0';
		str++;
	}
	value = value * sign;
	return (value);
}
