/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_instructions4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:59:22 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/09/14 00:24:04 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_equal_instruction_cont(t_instructions *instruction)
{
	char			char_instruction;
	int				cont;
	t_instructions	*tmp;

	if (instruction == 0)
		return (0);
	cont = 1;
	tmp = instruction;
	char_instruction = tmp->instruction;
	while (tmp->next != 0 && tmp->next->instruction == char_instruction)
	{
		cont++;
		tmp = tmp->next;
	}
	tmp = instruction;
	while (tmp->prev != 0 && tmp->prev->instruction == char_instruction)
	{
		cont++;
		tmp = tmp->prev;
	}
	return (cont);
}

void	ft_compress_rotates(t_instructions *instruction1,
			t_instructions *instruction2)
{
	int				len1;
	int				len2;
	t_instructions	*tmp;
	int				rotatate;

	if (instruction1 == 0 || instruction2 == 0)
		return ;
	if (instruction1->instruction == 5 || instruction1->instruction == 6)
		rotatate = 7;
	else
		rotatate = 10;
	len1 = ft_equal_instruction_cont(instruction1);
	len2 = ft_equal_instruction_cont(instruction2);
	tmp = instruction2->next;
	while (len1 > 0 && len2 > 0)
	{
		tmp = instruction2->next;
		ft_change_instruction(instruction1, rotatate);
		instruction1 = instruction1->prev;
		ft_delete_instruction(instruction2);
		instruction2 = tmp;
		len1--;
		len2--;
	}
}

int	ft_len_instructions(t_instructions *instructions)
{
	int	len;

	len = 0;
	while (instructions != 0)
	{
		len++;
		instructions = instructions->next;
	}
	return (len);
}
