/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:20:07 by matsanto          #+#    #+#             */
/*   Updated: 2023/05/16 19:12:40 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	const char	*s_empty;

	s_empty = "";
	len = ft_strlen(s1);
	if (!s1 || !set)
		return (0);
	else if (s1 == s_empty || set == s_empty)
	{
		return (ft_substr(s1, 0, len + 1));
	}
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
	}
	len = ft_strlen(s1);
	while (len && ft_strchr(set, s1[len]))
	{
		len--;
	}
	return (ft_substr(s1, 0, len + 1));
}
