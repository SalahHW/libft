/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:51:55 by sbouheni          #+#    #+#             */
/*   Updated: 2023/07/24 22:48:18 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*get_strdup(char **str);
char	*join_strings(char **dst, char *src);
char	*find_cr(char **str);
char	*read_file(int fd, char **str);
char	*extract_line(char **str);
char	*keep_remainder(char **str);
size_t	get_strlen(const char *str);
char	*ft_free(char **str);
#endif
