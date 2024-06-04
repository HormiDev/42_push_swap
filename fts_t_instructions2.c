/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_instructions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 23:47:24 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/04 13:02:22 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_instruction(t_instructions *instructions)
{
	if (instructions->instruction == 0)
		write(1, "sa\n", 3);
	else if (instructions->instruction == 1)
		write(1, "sb\n", 3);
	else if (instructions->instruction == 2)
		write(1, "ss\n", 3);
	else if (instructions->instruction == 3)
		write(1, "pa\n", 3);
	else if (instructions->instruction == 4)
		write(1, "pb\n", 3);
	else if (instructions->instruction == 5)
		write(1, "ra\n", 3);
	else if (instructions->instruction == 6)
		write(1, "rb\n", 3);
	else if (instructions->instruction == 7)
		write(1, "rr\n", 3);
	else if (instructions->instruction == 8)
		write(1, "rra\n", 4);
	else if (instructions->instruction == 9)
		write(1, "rrb\n", 4);
	else if (instructions->instruction == 10)
		write(1, "rrr\n", 4);
}

void	print_instructions(t_instructions *instructions)
{
	while (instructions != 0)
	{
		print_instruction(instructions);
		instructions = instructions->next;
	}
}

static void	ft_next_instruction3(t_instructions *instruction)
{
	if (instruction->instruction == 8)
	{
		instruction->instruction = 9;
		instruction->f = &rrb;
	}
	else if (instruction->instruction == 9)
	{
		instruction->instruction = 10;
		instruction->f = &rrr;
	}
	else if (instruction->instruction == 10)
	{
		instruction->instruction = 0;
		instruction->f = &sa;
		if (instruction->next != 0)
			ft_next_instruction(instruction->next);
		else
			ft_add_last_instruction(&instruction, ft_new_instruction(0));
	}
}

static void	ft_next_instruction2(t_instructions *instruction)
{
	if (instruction->instruction == 4)
	{
		instruction->instruction = 5;
		instruction->f = &ra;
	}
	else if (instruction->instruction == 5)
	{
		instruction->instruction = 6;
		instruction->f = &rb;
	}
	else if (instruction->instruction == 6)
	{
		instruction->instruction = 7;
		instruction->f = &rr;
	}
	else if (instruction->instruction == 7)
	{
		instruction->instruction = 8;
		instruction->f = &rra;
	}
	else
		ft_next_instruction3(instruction);
}

void	ft_next_instruction(t_instructions *instruction)
{
	if (instruction == 0)
		return ;
	if (instruction->instruction == 0)
	{
		instruction->instruction = 1;
		instruction->f = &sb;
	}
	else if (instruction->instruction == 1)
	{
		instruction->instruction = 2;
		instruction->f = &ss;
	}
	else if (instruction->instruction == 2)
	{
		instruction->instruction = 3;
		instruction->f = &pa;
	}
	else if (instruction->instruction == 3)
	{
		instruction->instruction = 4;
		instruction->f = &pb;
	}
	else
		ft_next_instruction2(instruction);
}
