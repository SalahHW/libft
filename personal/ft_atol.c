/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouheni <sbouheni@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 06:37:13 by sbouheni          #+#    #+#             */
/*   Updated: 2023/11/07 06:38:17 by sbouheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

long	ft_atol(char *str)
{
	long	number;
	int		sign;

	number = 0;
	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number * sign);
}
