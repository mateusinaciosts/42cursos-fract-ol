/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 10:52:00 by matsanto          #+#    #+#             */
/*   Updated: 2023/05/23 11:08:34 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	count_dst;
	size_t	count_src;
	size_t	i;
	size_t	value_expect;

	i = 0;
	value_expect = 0;
	count_dst = ft_strlen(dst);
	count_src = ft_strlen(src);
	if (size > count_dst)
	{
		value_expect = (count_dst + count_src);
		while (src[i] && count_dst < size -1)
		{
			dst[count_dst++] = src[i++];
		}
		dst[count_dst] = 0;
		return (value_expect);
	}
	else
		return (size + count_src);
}
