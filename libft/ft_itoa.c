/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:06:51 by regea-go          #+#    #+#             */
/*   Updated: 2023/04/28 01:46:43 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_chars(int i)
{
	int	sign;
	int	counter;

	sign = 0;
	counter = 0;
	if (i == -2147483648)
		return (11);
	if (i < 0)
	{
		i = -i;
		sign = -1;
	}
	while (i >= 10)
	{
		i = i / 10;
		counter++;
	}
	counter ++;
	if (sign == -1)
		counter++;
	return (counter);
}

static void	rev_string(char *s)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	while (s[j] != '\0' && s[j + 1] != '\0')
		j++;
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}

static int	is_negative(int n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		sign;
	int		index;
	long	number;

	number = n;
	index = 0;
	sign = is_negative(n);
	if (sign == -1)
		number = -number;
	s = malloc(count_chars(n) * sizeof(char) + 1);
	if (!s)
		return (0);
	while (number >= 10 && s)
	{
		s[index++] = (number % 10) + '0';
		number = number / 10;
	}
	s[index++] = number + '0';
	if (sign == -1)
		s[index++] = '-';
	s[index] = '\0';
	rev_string(s);
	return (s);
}
