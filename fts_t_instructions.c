/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:34:00 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/03 00:26:35 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instructions	*ft_new_instruction(char instruction)
{
	t_instructions	*new;

	new = malloc(sizeof(t_instructions));
	if (new == 0)
		return (0);
	new->instruction = instruction;
	new->f = &sa;
	new->next = 0;
	new->prev = 0;
	return (new);
}

void	ft_add_last_instruction(t_instructions *instructions,
		t_instructions *new)
{
	if (instructions == 0)
		return ;
	while (instructions->next != 0)
		instructions = instructions->next;
	instructions->next = new;
	new->prev = instructions;
}

void	ft_free_instructions(t_instructions *instructions)
{
	t_instructions	*tmp;

	while (instructions != 0)
	{
		tmp = instructions;
		instructions = instructions->next;
		free(tmp);
	}
}

void	ft_execute_instructions(t_push_swap *push_swap,
		t_instructions *instructions)
{
	while (instructions != 0)
	{
		instructions->f(push_swap);
		instructions = instructions->next;
	}
}
