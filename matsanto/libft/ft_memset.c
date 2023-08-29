/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:00:06 by matsanto          #+#    #+#             */
/*   Updated: 2023/05/08 11:15:41 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t n)
{
	size_t		i;
	char		*valueptr;

	i = 0;
	valueptr = (char *) ptr;
	while (i < n)
	{
		valueptr[i] = value;
		i++;
	}
	return (valueptr);
}
