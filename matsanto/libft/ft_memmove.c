/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:48:51 by matsanto          #+#    #+#             */
/*   Updated: 2023/05/23 08:53:48 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned long int	count;

	if (src == NULL && dest == NULL)
	{
		return (NULL);
	}
	if (dest < src)
	{
		count = 0;
		while (count < n)
		{
			((char *) dest)[count] = ((char *) src)[count];
			count++;
		}
	}
	else
	{
		count = n;
		while (count > 0)
		{
			((char *) dest)[count - 1] = ((char *) src)[count - 1];
			count--;
		}
	}
	return (dest);
}
