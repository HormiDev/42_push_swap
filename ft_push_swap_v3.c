/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_v3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 13:44:18 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/04 23:06:17 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// algorito de ordenamiento V3
void	ft_push_swap_v3(t_push_swap *push_swap)
{
	t_stack	*min;
	t_stack	*max;
	int min_position;
	int min_size;
	int max_position;
	int max_size;
	int min_dintance;
	t_instructions	*instructions;

	instructions = 0;
	while (push_swap->a != 0)
	{
		//print_push_swap(push_swap);
		min = ft_stack_min_num(push_swap->a);
		max = ft_stack_max_num(push_swap->a);
		min_position = ft_stack_position(push_swap->a, min);
		min_size = ft_stack_size(min);
		max_position = ft_stack_position(push_swap->a, max) + 2;
		max_size = ft_stack_size(max) + 2;
		min_dintance = ft_get_min_int(4, min_position, min_size, max_position, max_size);
		if (min_dintance == min_position)
		{
			while (push_swap->a != min)
			{
				ra(push_swap);
				ft_add_last_instruction(&instructions, ft_new_instruction(5));
			}
			pb(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(4));
		}
		else if (min_dintance == min_size)
		{
			while (push_swap->a != min)
				{
					rra(push_swap);
					ft_add_last_instruction(&instructions, ft_new_instruction(8));
				}
			pb(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(4));
		}
		else if (min_dintance == max_position)
		{
			while (push_swap->a != max)
				{
					ra(push_swap);
					ft_add_last_instruction(&instructions, ft_new_instruction(5));
				}
			pb(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(4));
			rb(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(6));
		}
		else
		{
			while (push_swap->a != max)
				{
					rra(push_swap);
					ft_add_last_instruction(&instructions, ft_new_instruction(8));
				}
			pb(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(4));
			rb(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(6));
		}
	}
	//print_push_swap(push_swap);
	max = ft_stack_max_num(push_swap->b);
	if (ft_stack_position(push_swap->b, max) < ft_stack_size(max))
	{
		while (push_swap->b != max)
		{
			rb(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(6));
		}
	}
	else
	{
		while (push_swap->b != max)
		{
			rrb(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(9));
		}
	}
	//print_push_swap(push_swap);
	while (push_swap->b != 0)
	{
		pa(push_swap);
		ft_add_last_instruction(&instructions, ft_new_instruction(3));
	}
	print_instructions(instructions);
	ft_free_instructions(instructions);
}
