/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_instructions3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:55:48 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/09/12 18:52:48 by ide-dieg         ###   ########.fr       */
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
	prev->next = next;
	next->prev = prev;
	free(instruction);
}

void	ft_compress_instructions(t_instructions **instructions)
{
	t_instructions	*tmp;

	tmp = *instructions;
	while (tmp->next != 0)
	{
		if ((tmp->instruction == 0 && tmp->next->instruction == 1)
			|| (tmp->instruction == 1 && tmp->next->instruction == 0))
		{
			ft_change_instruction(tmp, 2);
			ft_delete_instruction(tmp->next);
		}
		else if ((tmp->instruction == 5 && tmp->next->instruction == 6)
			|| (tmp->instruction == 6 && tmp->next->instruction == 5))
		{
			ft_change_instruction(tmp, 7);
			ft_delete_instruction(tmp->next);
		}
		else if ((tmp->instruction == 8 && tmp->next->instruction == 9)
			|| (tmp->instruction == 9 && tmp->next->instruction == 8))
		{
			ft_change_instruction(tmp, 10);
			ft_delete_instruction(tmp->next);
		}
		else
		tmp = tmp->next;
	}
}
