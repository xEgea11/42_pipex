/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 01:54:34 by regea-go          #+#    #+#             */
/*   Updated: 2023/04/28 03:30:48 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		counter;
	int		index;
	int		flag;

	index = 0;
	flag = 1;
	counter = 0;
	while (s[index] != '\0')
	{
		if (s[index] == c && flag == 0)
		{
			flag = 1;
			counter++;
		}
		if (s[index] != c && flag == 1)
			flag = 0;
		index++;
	}
	if (s[index] == '\0' && flag == 0)
		counter++;
	return (counter);
}

static int	count_chars(const char *s, char c)
{
	int	index;

	index = 0;
	while (s[index] != c && s[index] != '\0')
		index++;
	return (index);
}

char	**ft_split(const char *s, char c)
{
	char	**str_arr;
	int		i;
	int		arr_i;
	int		flag;

	i = 0;
	arr_i = 0;
	flag = 1;
	str_arr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !str_arr)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && flag == 1)
		{
			flag = 0;
			str_arr[arr_i] = ft_substr(s, i, count_chars(&s[i], c));
			arr_i++;
		}
		else if (s[i] == c)
			flag = 1;
		i++;
	}
	str_arr[arr_i] = 0;
	return (str_arr);
}
