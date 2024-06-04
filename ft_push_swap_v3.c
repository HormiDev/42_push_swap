/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_v3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 23:34:29 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/04 00:07:24 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// algorito de ordenamiento V3
void	ft_push_swap_v3(t_push_swap *push_swap)
{
	t_instructions	*instructions;

	if (push_swap == 0 || is_stack_ordered_min_MAX(push_swap->a) == 1)
		return ;
	else
		instructions = ft_new_instruction(0);
	while (is_stack_ordered_min_MAX(push_swap->a) == 0)
	{
		if (push_swap->a->content > push_swap->a->next->content && 
		push_swap->a->next != ft_stack_min_num(push_swap->a))
			ft_add_last_instruction(instructions, ft_new_instruction(5));
			
		else
			ra(push_swap);
	}
}