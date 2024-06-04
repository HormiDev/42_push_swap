/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_v2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 03:31:54 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/04 13:42:42 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_ordered_to_b(t_push_swap *push_swap, t_instructions **instructions)
{
	t_stack	*min;

	while (push_swap->a != 0)
	{
		min = ft_stack_min_num(push_swap->a);
		if (ft_stack_position(push_swap->a, min) < ft_stack_size(min))
		{
			while (push_swap->a != min)
			{
				ra(push_swap);
				ft_add_last_instruction(instructions, ft_new_instruction(5));
			}
		}
		else
		{
			while (push_swap->a != min)
			{
				rra(push_swap);
				ft_add_last_instruction(instructions, ft_new_instruction(8));
			}
		}
		pb(push_swap);
		ft_add_last_instruction(instructions, ft_new_instruction(4));
	}
}

// algorito de ordenamiento V2
void	ft_push_swap_v2(t_push_swap *push_swap)
{
	t_instructions	*instructions;

	instructions = 0;
	push_ordered_to_b(push_swap, &instructions);
	while (push_swap->b != 0)
	{
		pa(push_swap);
		ft_add_last_instruction(&instructions, ft_new_instruction(3));
	}
	print_instructions(instructions);
	ft_free_instructions(instructions);
}
