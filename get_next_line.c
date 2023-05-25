/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 17:11:31 by sbouheni          #+#    #+#             */
/*   Updated: 2023/05/25 04:38:54 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_file(fd, &stash);
	if (!stash || !*stash)
	{
		ft_free(&stash);
		return (NULL);
	}
	if (!find_cr(&stash))
	{
		line = ft_strdup(stash);
		return (line);
	}
	line = extract_line(&stash);
	stash = keep_remainder(&stash);
	return (line);
}

char	*read_file(int fd, char **stash)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_state;

	read_state = 1;
	while (read_state > 0)
	{
		read_state = read(fd, buffer, BUFFER_SIZE);
		if (read_state < 0 || (read_state == 0 && !*stash))
		{
			ft_free(stash);
			return (NULL);
		}
		buffer[read_state] = '\0';
		if (!*stash && read_state > 0)
		{
			*stash = malloc(sizeof(char) * read_state + 1);
			if (!*stash)
				return (NULL);
			**stash = '\0';
		}
		*stash = join_strings(stash, buffer);
		if (find_cr(stash))
			break ;
	}
	return (*stash);
}

char	*extract_line(char **stash)
{
	char	*line;
	char	*line_ptr;
	char	*stash_ptr;

	stash_ptr = *stash;
	while (*stash_ptr != '\n' && *stash_ptr)
		stash_ptr++;
	line = malloc((sizeof(char) * (stash_ptr - *stash)) + 2);
	if (!line)
		return (ft_free(stash));
	stash_ptr = *stash;
	line_ptr = line;
	while (*stash_ptr != '\n' && *stash_ptr)
		*line_ptr++ = *stash_ptr++;
	*line_ptr = '\n';
	*++line_ptr = '\0';
	return (line);
}

char	*keep_remainder(char **stash)
{
	char	*new_stash;
	char	*stash_ptr;
	char	*cr_ptr;
	char	*new_stash_ptr;

	new_stash = NULL;
	if (find_cr(stash))
	{
		cr_ptr = find_cr(stash);
		stash_ptr = find_cr(stash);
		while (*stash_ptr)
			stash_ptr++;
		new_stash = malloc((sizeof(char) * (stash_ptr - cr_ptr) + 1));
		if (!new_stash)
			return (ft_free(stash));
		new_stash_ptr = new_stash;
		stash_ptr = find_cr(stash) + 1;
		while (*stash_ptr)
			*new_stash_ptr++ = *stash_ptr++;
		*new_stash_ptr = '\0';
	}
	ft_free(stash);
	return (new_stash);
}
