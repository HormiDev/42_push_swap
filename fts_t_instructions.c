/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:34:00 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/04 03:42:29 by ide-dieg         ###   ########.fr       */
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
	new->f = select_function_for_instruction(instruction);
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

void	*select_function_for_instruction(char instruction)
{
	if (instruction == 0)
		return (&sa);
	else if (instruction == 1)
		return (&sb);
	else if (instruction == 2)
		return (&ss);
	else if (instruction == 3)
		return (&pa);
	else if (instruction == 4)
		return (&pb);
	else if (instruction == 5)
		return (&ra);
	else if (instruction == 6)
		return (&rb);
	else if (instruction == 7)
		return (&rr);
	else if (instruction == 8)
		return (&rra);
	else if (instruction == 9)
		return (&rrb);
	else if (instruction == 10)
		return (&rrr);
	return (0);
}
