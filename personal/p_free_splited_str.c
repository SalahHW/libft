/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_free_splited_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 23:23:49 by sbouheni          #+#    #+#             */
/*   Updated: 2023/07/19 23:35:43 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	p_free_splited_str(char **splited_str)
{
	char	**splited_str_ptr;

	splited_str_ptr = splited_str;
	while (*splited_str_ptr)
	{
		free(*splited_str_ptr);
		splited_str_ptr++;
	}
	free(splited_str);
}
