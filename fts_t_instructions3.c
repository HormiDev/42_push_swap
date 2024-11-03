/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_instructions3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:55:48 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/11/03 02:14:15 by ide-dieg         ###   ########.fr       */
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

void	ft_compress_instructions(t_instructions *in)
{
	if (in == 0)
		return ;
	while (in->next != 0)
	{
		if ((in->instruction == 0 && in->next->instruction == 1)
			|| (in->instruction == 1 && in->next->instruction == 0))
		{
			ft_change_instruction(in, 2);
			ft_delete_instruction(in->next);
		}
		else if ((in->instruction == 5 && in->next->instruction == 6)
			|| (in->instruction == 6 && in->next->instruction == 5))
		{
			ft_compress_rotates(in, in->next);
		}
		else if ((in->instruction == 8 && in->next->instruction == 9)
			|| (in->instruction == 9 && in->next->instruction == 8))
		{
			ft_compress_rotates(in, in->next);
		}
		else
			in = in->next;
	}
}
