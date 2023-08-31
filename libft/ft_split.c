/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matsanto <matsanto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:58:12 by matsanto          #+#    #+#             */
/*   Updated: 2023/05/24 11:20:22 by matsanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	int	cont_words;

	cont_words = 0;
	if (*s == '\0')
		return (cont_words);
	if (c == '\0')
		return (1);
	while (*s == c && *s)
		s++;
	while (*s)
	{
		cont_words++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (cont_words);
}

void	*clear(char **array)
{
	while (*array)
		free(*array);
	free(array);
	return (NULL);
}

char	**ctor_array(char const *s, char c, char **matriz)
{
	int	i;
	int	len_word;

	i = 0;
	len_word = 0;
	while (*s)
	{
		while (s[len_word] != c && s[len_word])
			len_word++;
		matriz[i] = (char *)malloc((len_word + 1) * sizeof(char));
		if (matriz[i] == NULL)
			return (clear(matriz));
		matriz[i][len_word] = '\0';
		while (len_word > 0)
		{
			matriz[i][len_word - 1] = s[len_word - 1];
			len_word--;
		}
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
		i++;
	}
	return (matriz);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		qty_array;

	qty_array = count_words(s, c);
	array = (char **)malloc((qty_array + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (*s == c && *s)
		s++;
	array = ctor_array(s, c, array);
	array[qty_array] = NULL;
	return (array);
}
