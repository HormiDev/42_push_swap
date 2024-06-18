/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:40:34 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/18 19:44:31 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	num;
	int		cont;
	int		mult;

	num = 0;
	cont = 0;
	mult = 1;
	while (str[cont] == ' ' || (str[cont] >= '\t' && str[cont] <= '\r'))
		cont++;
	if (str[cont] == '-')
		mult = -1;
	if (str[cont] == '-' || str[cont] == '+')
		cont++;
	while (ft_isdigit(str[cont]))
	{
		num = num * 10 + (str[cont] - 48);
		cont++;
	}
	return (num * mult);
}