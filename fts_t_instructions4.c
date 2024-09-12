/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_instructions4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 18:59:22 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/09/12 19:23:28 by ide-dieg         ###   ########.fr       */
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
