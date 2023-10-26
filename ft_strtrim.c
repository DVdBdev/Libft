/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:35:46 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/19 16:28:11 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_is_in_set(unsigned char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	find_start(char const *str, char const *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!char_is_in_set(str[i], set))
			return (i);
		i++;
	}
	return (i);
}

/*static int	find_start(char const *str, char const *set)
{
	int	i;
	int	j;
	int	set_len;

	i = 0;
	set_len = ft_strlen(set);
	while (str[i])
	{
		j = 0;
		while (set[j])
		{
			if (str[i + j] != set[j])
				return (i);
			j++;
		}
		i = i + j;
	}
	return (i);
}*/

static int	find_end(char const *str, char const *set)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0)
	{
		if (!char_is_in_set(str[i], set))
			return (i);
		i--;
	}
	return (i);
}

/*static int	find_end(char const *str, char const *set)
{
	int	i;
	int	j;
	int	k;
	int	set_len;

	i = ft_strlen(str) - 1;
	set_len = ft_strlen(set);
	while (i >= 0)
	{
		j = set_len - 1;
		k = 0;
		while (j >= 0)
		{
			if (str[i - k] != set[j])
				return (i);
			j--;
			k++;
		}
		i = i - k;
	}
	return (i);
}*/

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str;
	int		len;

	start = find_start(s1, set);
	end = find_end(s1, set);
	i = 0;
	len = ft_strlen(s1);
	str = (char *)malloc(end - start + 2);
	if (!str)
		return (NULL);
	while (start <= end && start != len)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}

/*int     main(int argc, char *argv[])
{
        if (argc != 3)
                return (0);
        printf("%s\n", ft_strtrim(argv[1], argv[2]));
        //printf("%d\n", find_end(argv[1], argv[2]));
        return (0);
}*/
