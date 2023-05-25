/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 03:27:29 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/25 05:11:01 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_strings(char **dst, char *src)
{
	char	*new_string;
	char	*new_string_ptr;
	char	*dst_ptr;

	if (!dst || !src)
		return (NULL);
	new_string = malloc(ft_strlen(*dst) + ft_strlen(src) + 1);
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
