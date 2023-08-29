/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:20:50 by matsanto          #+#    #+#             */
/*   Updated: 2023/05/16 19:13:34 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		str1;
	int		str2;
	char	*result;

	str1 = ft_strlen(s1);
	str2 = ft_strlen(s2);
	result = malloc(sizeof(char) * (str1 + str2 + 1));
	if (!result)
		return (0);
	ft_memcpy(result, s1, str1);
	ft_memcpy(result + str1, s2, str2);
	result[str1 + str2] = '\0';
	return (result);
}
