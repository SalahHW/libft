/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 03:27:29 by sbouheni          #+#    #+#             */
/*   Updated: 2023/07/24 22:47:38 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	get_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*get_strdup(char **str)
{
	char	*new_string;
	char	*new_string_ptr;
	char	*str_ptr;

	new_string = malloc(sizeof(char) * get_strlen(*str) + 1);
	if (!new_string)
	{
		ft_free(str);
		return (NULL);
	}
	str_ptr = *str;
	new_string_ptr = new_string;
	while (*str_ptr)
		*new_string_ptr++ = *str_ptr++;
	*new_string_ptr = '\0';
	ft_free(str);
	return (new_string);
}

char	*join_strings(char **dst, char *src)
{
	char	*new_string;
	char	*new_string_ptr;
	char	*dst_ptr;

	if (!dst || !src)
		return (NULL);
	new_string = malloc(get_strlen(*dst) + get_strlen(src) + 1);
	if (!new_string)
		return (ft_free(dst));
	new_string_ptr = new_string;
	dst_ptr = *dst;
	while (*dst_ptr)
		*new_string_ptr++ = *dst_ptr++;
	while (*src)
		*new_string_ptr++ = *src++;
	*new_string_ptr = '\0';
	ft_free(dst);
	return (new_string);
}

char	*find_cr(char **str)
{
	char	*str_ptr;

	if (!*str)
		return (NULL);
	str_ptr = *str;
	while (*str_ptr)
	{
		if (*str_ptr == '\n')
			return (str_ptr);
		str_ptr++;
	}
	return (NULL);
}

char	*ft_free(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}
