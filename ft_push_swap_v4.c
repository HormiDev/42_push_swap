/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_v4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:39:04 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/12 01:58:18 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_to_a(t_push_swap *push_swap, t_instructions *instructions)
{
	t_stack	*min;
	t_stack	*max;
	int		min_position;
	int		min_size;
	int		max_position;
	int		max_size;
	int		min_dintance;
	while (push_swap->b != 0)
	{
		min = ft_stack_min_num(push_swap->b);
		max = ft_stack_max_num(push_swap->b);
		min_position = ft_stack_position(push_swap->b, min) + 2;
		min_size = ft_stack_size(min) + 2;
		max_position = ft_stack_position(push_swap->b, max);
		max_size = ft_stack_size(max);
		min_dintance = ft_get_min_int(4, min_position, min_size, max_position, max_size);
		if (min_dintance == max_position)
		{
			while (push_swap->b != max)
			{
				rb(push_swap);
				ft_add_last_instruction(&instructions, ft_new_instruction(6));
			}
			pa(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(3));
		}
		else if (min_dintance == max_size)
		{
			while (push_swap->b != max)
			{
				rrb(push_swap);
				ft_add_last_instruction(&instructions, ft_new_instruction(9));
			}
			pa(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(3));
		}
		else if (min_dintance == min_position)
		{
			while (push_swap->b != min)
			{
				rb(push_swap);
				ft_add_last_instruction(&instructions, ft_new_instruction(6));
			}
			pa(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(3));
			ra(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(5));
		}
		else
		{
			while (push_swap->b != min)
			{
				rrb(push_swap);
				ft_add_last_instruction(&instructions, ft_new_instruction(9));
			}
			pa(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(3));
			ra(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(5));
		}
	}
	min = ft_stack_min_num(push_swap->a);
	if (ft_stack_position(push_swap->a, min) < ft_stack_size(min))
	{
		while (push_swap->a != min)
		{
			ra(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(5));
		}
	}
	else
	{
		while (push_swap->a != min)
		{
			rra(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(8));
		}
	}
	
}

t_instructions	*ft_move_to_b(t_push_swap *push_swap, int range)
{
	t_instructions	*instructions;
	int				min;

	instructions = 0;
	while(push_swap->a != 0)
	{
		min = ft_stack_min_num(push_swap->a)->content;
		if (push_swap->a->content <= min + range)
		{
			pb(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(4));
		}
		else
		{
			ra(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(5));
		}
	}
	return (instructions);
}

// algorito de ordenamiento V4
void	ft_push_swap_v4(t_push_swap *push_swap)
{
	t_instructions	*instructions;
	int				range;
	
	range = ft_stack_size(push_swap->a) / 20;
	instructions = ft_move_to_b(push_swap, range);
	ft_move_to_a(push_swap, instructions);
	print_instructions(instructions);
	ft_free_instructions(instructions);
}
