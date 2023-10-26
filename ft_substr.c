/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:26:58 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/17 11:23:57 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*substr;

	i = 0;
	j = 0;
	substr = (char *)malloc(sizeof(*s) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			substr[j] = s[i];
			j++;
		}
		i++;
	}
	substr[j] = '\0';
	return (substr);
}

/*int     main(int argc, char *argv[])
{
	if (argc != 4)
		return (0);
        printf("%s", ft_substr(argv[1], atoi(argv[2]), atoi(argv[3])));
        return (0);
}*/
