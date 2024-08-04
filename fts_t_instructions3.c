/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_instructions3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 13:55:48 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/07/27 14:07:20 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
