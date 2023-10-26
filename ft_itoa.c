/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:08:58 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/19 15:39:11 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_digits(int num)
{
	int	tmp;
	int	dig;

	tmp = num;
	dig = 1;
	while (tmp > 9)
	{
		tmp /= 10;
		dig++;
	}
	return (dig);
}

static void	make_str(int num, int i, char *str, int is_neg)
{
	while (i >= is_neg)
	{
		str[i] = num % 10 + '0';
		num /= 10;
		i--;
	}
}

char	*ft_itoa(int num)
{
	int		is_neg;
	int		dig;
	char	*str;
	int		i;
	char	*min_str;

	min_str = "-2147483648";
	if (num == INT_MIN)
		return (min_str);
	is_neg = 0;
	if (num < 0)
	{
		is_neg = 1;
		num = -num;
	}
	dig = num_digits(num);
	str = (char *)malloc(dig + is_neg + 1);
	if (!str)
		return (NULL);
	i = dig + is_neg - 1;
	make_str(num, i, str, is_neg);
	if (is_neg)
		str[0] = '-';
	str[dig + is_neg] = '\0';
	return (str);
}
