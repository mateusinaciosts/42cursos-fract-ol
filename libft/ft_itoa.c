/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:20:56 by matsanto          #+#    #+#             */
/*   Updated: 2023/05/16 19:15:25 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lenint(int n)
{
	int	len;

	len = 0;
	if (n == 0)
	{
		len = 1;
		return (len);
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*strwrite(char *str, int len, int sign, int n)
{
	while (len >= sign)
	{
		if ((n % 10) < 0)
			str[len] = -(n % 10) + '0';
		else
			str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	sign;
	int		lenstr;
	char	*str;

	sign = 0;
	lenstr = lenint(n);
	if (n < 0)
	{
		lenstr++;
		sign = 1;
	}
	str = malloc(sizeof(char) * (lenstr + 1));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	strwrite(str, lenstr - 1, sign, n);
	str[lenstr] = '\0';
	return (str);
}
