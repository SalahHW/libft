/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int_compatible.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 06:40:44 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/07 06:43:02 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	is_convertible_to_int(char *str)
{
	int		digit_count;
	char	*str_ptr;

	str_ptr = str;
	digit_count = 0;
	if (*str_ptr == '-' || *str_ptr == '+')
		return (0);
	while (*str_ptr)
	{
		if (digit_count > 10 || !ft_isdigit(*str_ptr))
			return (0);
		digit_count++;
		str_ptr++;
	}
	if (digit_count == 0)
		return (0);
	if (ft_atol(str) < 1 || ft_atol(str) > 2147483647)
		return (0);
	return (1);
}
