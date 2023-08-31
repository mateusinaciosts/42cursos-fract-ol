/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:58:20 by matsanto          #+#    #+#             */
/*   Updated: 2023/05/23 11:33:06 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	len_s;

	len_s = ft_strlen(s);
	if (!s || start >= len_s)
	{
		sub = malloc(sizeof(char) * 1);
		sub[0] = '\0';
		return (sub);
	}
	if (start + len > len_s)
		len = len_s - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	ft_memcpy(sub, s + start, len);
	sub[len] = '\0';
	return (sub);
}
