/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 02:49:57 by sbouheni          #+#    #+#             */
/*   Updated: 2023/09/20 04:23:32 by joakoeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_print_integer(int ap)
{
	int		count;
	char	*integer_str;

	integer_str = ft_itoa(ap);
	if (!(integer_str) || (ft_print_string(integer_str) < 0))
	{
		free(integer_str);
		return (-2147483648);
	}
	count = ft_strlen(integer_str);
	free(integer_str);
	return (count);
}
