/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvan-den <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 19:45:57 by dvan-den          #+#    #+#             */
/*   Updated: 2023/10/19 19:49:29 by dvan-den         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *smoll, size_t len)
{
	size_t	smoll_len;
	size_t	i;
	size_t	j;

	smoll_len = ft_strlen(smoll);
	i = 0;
	while (big[i] && i + smoll_len <= len)
	{
		j = 0;
		while (j < smoll_len && big[i + j] == smoll[j])
			j++;
		if (j == smoll_len)
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
