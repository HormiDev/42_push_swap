/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_fb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 19:06:16 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/02 21:13:20 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// algorito de ordenamiento V4 fuerza bruta
void	ft_push_swap_fb(t_push_swap *push_swap)
{
	t_push_swap		*tmp;
	t_instructions	*instructions;

	tmp = ft_duplicate_push_swap(push_swap);
	instructions = ft_new_instruction(0);
	if (tmp == 0 || instructions == 0 || is_stack_ordered_min_MAX(tmp->a))
	{
		ft_free_push_swap(tmp);
		ft_free_instructions(instructions);
		return ;
	}
	while (tmp != 0 && (is_stack_ordered_min_MAX(tmp->a) == 0
			|| ft_stack_size(tmp->b) != 0))
	{
		ft_free_push_swap(tmp);
		tmp = ft_duplicate_push_swap(push_swap);
		ft_next_instruction(instructions);
		ft_execute_instructions(tmp, instructions);
	}
	print_instructions(instructions);
	ft_free_push_swap(tmp);
	ft_free_instructions(instructions);
}
