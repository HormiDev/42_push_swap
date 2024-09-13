/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_rg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:19:26 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/09/14 00:07:02 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap_rg(t_push_swap *push_swap)
{
	t_instructions	*instructions;
	t_instructions	*tmp;
	int				range;
	int				return_range;
	int				range_max;
	int				range_min;

	range = 5;
	range_min = ft_stack_size(push_swap->a) / 7.5 - range;
	range_max = ft_stack_size(push_swap->a) / 7.5 + range;
	return_range = 2;
	instructions = ft_push_swap_v7_rg(ft_duplicate_push_swap(push_swap),
					range, return_range);
	while (return_range >= 0)
	{
		range = range_min;
		while (range <= range_max)
		{
			tmp = ft_push_swap_v7_rg(ft_duplicate_push_swap(push_swap),
			range, return_range);
			if (ft_len_instructions(tmp) < ft_len_instructions(instructions))
			{
				ft_free_instructions(instructions);
				instructions = tmp;
			}
			else
				ft_free_instructions(tmp);
			range++;
		}
		return_range--;
	}
	print_instructions(instructions);
	ft_free_instructions(instructions);
}
