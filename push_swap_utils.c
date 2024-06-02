/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:16:47 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/03 01:19:50 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min_int(int num_arg, ...)
{
	va_list	args;
	int		min;
	int		tmp;
	int		cont;

	va_start(args, num_arg);
	min = va_arg(args, int);
	cont = 1;
	while (cont < num_arg)
	{
		tmp = va_arg(args, int);
		if (tmp < min)
			min = tmp;
		cont++;
	}
	va_end(args);
	return (min);
}
