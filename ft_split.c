/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 20:20:00 by sbouheni          #+#    #+#             */
/*   Updated: 2022/12/02 22:50:52 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_counter(const char *str, char separation)
{
	size_t	i;
	size_t	words;

	i = 0;
	while (str[i])
	{
		if (str[i] == separation)
			words++;
		i++;
	}
	if (i > 0)
		words++;
	return (words);
}

char	*allocate_substring(char const *str, size_t start, size_t i)
{
	char	*allocated_substring;

	allocated_substring = malloc(sizeof(ft_substr(str, start, i - start)));
	if (allocated_substring)
	{
		allocated_substring = ft_substr(str, start, i - start);
		return (allocated_substring);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	start;
	size_t	i;
	size_t	k;
	char	**substring;

	if (s && c)
	{
		i = 0;
		start = 0;
		k = 0;
		substring = malloc(word_counter(s, c)+ 1);
		if (substring)
		{
			while (s[i])
			{
				if (s[i] != c)
				{
					i++;
					continue;
				}
				*substring = allocate_substring(s, start, i);
				start = i + 1;
				*substring += 1;
				k++;
				i++;
			}
			*substring += 1;
			*substring = allocate_substring(s, start, i);
			*substring += 1;
			*substring = NULL;
			return (substring - k - 2);
		}
	}
	return (NULL);
}
