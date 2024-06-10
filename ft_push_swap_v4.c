/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_v4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:39:04 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/10 17:56:12 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// algorito de ordenamiento V4
void	ft_push_swap_v4(t_push_swap *push_swap)
{
	int min;
	t_instructions	*instructions;

	instructions = 0;
	while(push_swap->a != 0)
	{
		min = ft_stack_min_num(push_swap->a)->content;
		if (push_swap->a->content <= min + 50)
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
	print_instructions(instructions);
	ft_free_instructions(instructions);
}
