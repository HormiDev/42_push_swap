/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_instructions3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:55:48 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/09/13 19:50:28 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_instructions	*ft_last_instruction(t_instructions *instructions)
{
	if (instructions == 0)
		return (0);
	while (instructions->next != 0)
		instructions = instructions->next;
	return (instructions);
}

int	ft_cont_instruction_rotates(t_instructions *instructions)
{
	int	cont;

	if (instructions == 0)
		return (0);
	cont = 0;
	instructions = ft_last_instruction(instructions);
	if (instructions->instruction == 5 || instructions->instruction == 6)
	{
		while (instructions->instruction == 5 || instructions->instruction == 6)
		{
			cont++;
			instructions = instructions->prev;
		}
		return (cont);
	}
	else if (instructions->instruction == 8 || instructions->instruction == 9)
	{
		while (instructions->instruction == 8 || instructions->instruction == 9)
		{
			cont--;
			instructions = instructions->prev;
		}
		return (cont);
	}
	return (0);
}

void	ft_change_instruction(t_instructions *instruction, char new)
{
	instruction->instruction = new;
	instruction->f = select_function_for_instruction(new);
}

void	ft_delete_instruction(t_instructions *instruction)
{
	t_instructions	*prev;
	t_instructions	*next;

	if (instruction == 0)
		return ;
	prev = instruction->prev;
	next = instruction->next;
	if (prev != 0)
		prev->next = next;
	if (next != 0)
		next->prev = prev;
	free(instruction);
}

void	ft_compress_instructions(t_instructions *instructions)
{
	if (instructions == 0)
		return ;
	while (instructions->next != 0)
	{
		if ((instructions->instruction == 0 && instructions->next->instruction == 1)
			|| (instructions->instruction == 1 && instructions->next->instruction == 0))
		{
			ft_change_instruction(instructions, 2);
			ft_delete_instruction(instructions->next);
		}
		else if ((instructions->instruction == 5 && instructions->next->instruction == 6)
			|| (instructions->instruction == 6 && instructions->next->instruction == 5))
		{
			ft_compress_rotates(instructions, instructions->next);
		}
		else if ((instructions->instruction == 8 && instructions->next->instruction == 9)
			|| (instructions->instruction == 9 && instructions->next->instruction == 8))
		{
			ft_change_instruction(instructions, 10);
			ft_delete_instruction(instructions->next);
		}
		else
		instructions = instructions->next;
	}
}
