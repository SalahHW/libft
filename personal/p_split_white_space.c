/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_split_white_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <salah.bouheniche@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 17:41:07 by sbouheni          #+#    #+#             */
/*   Updated: 2023/07/19 22:17:39 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static long	word_counter(const char *str)
{
	int		state;
	size_t	i;
	size_t	word_count;

	state = 0;
	i = 0;
	word_count = 0;
	while (str[i])
	{
		if (is_white_space(str[i]))
		{
			state = 0;
		}
		else if (state == 0)
		{
			state = 1;
			word_count++;
		}
		i++;
	}
	return (word_count);
}

static char	*substr_bis(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	i = 0;
	substring = malloc(sizeof(char) * len + 1);
	if (substring)
	{
		while (i < len)
		{
			substring[i] = s[start];
			i++;
			start++;
		}
		substring[i] = '\0';
		return (substring);
	}
	free(substring);
	return (NULL);
}

static char	**free_strings(char **substring, long count)
{
	long	i;

	if (count == -1)
		count = 0;
	i = 0;
	substring -= count;
	while (i < count)
	{
		free(substring[i]);
		i++;
	}
	free(substring);
	return (NULL);
}

static size_t	get_word_end(char *str, size_t i, size_t *start)
{
	while (is_white_space(str[i]))
		i++;
	*start = i;
	while (!is_white_space(str[i]) && str[i])
		i++;
	return (i);
}

char	**ft_split_white_space(char const *s)
{
	size_t	start;
	size_t	i;
	long	count;
	char	**substring;

	i = 0;
	start = 0;
	count = -1;
	if (!s)
		return (NULL);
	substring = malloc((word_counter(s) + 1) * sizeof(char *));
	if (substring)
	{
		while (++count < word_counter(s))
		{
			i = get_word_end((char *)s, i, &start);
			*substring = substr_bis(s, start, i - start);
			if (!*substring)
				return (free_strings(substring, count));
			substring += 1;
		}
		*substring = NULL;
		return (substring -= count);
	}
	return (free_strings(substring, count));
}
