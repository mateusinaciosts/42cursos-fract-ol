/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 17:40:28 by matsanto          #+#    #+#             */
/*   Updated: 2023/05/23 09:11:12 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	slength;
	int				i;
	char			*s2;

	slength = 0;
	i = 0;
	while (s[slength])
		slength++;
	s2 = malloc((slength + 1) * sizeof(const char));
	if (s2 == 0)
		return (0);
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
