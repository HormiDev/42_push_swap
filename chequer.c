/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chequer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 04:14:21 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/09/18 19:19:26 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_line_to_instruction(char *line)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		return (0);
	if (ft_strncmp(line, "sb", 2) == 0)
		return (1);
	if (ft_strncmp(line, "ss", 2) == 0)
		return (2);
	if (ft_strncmp(line, "pa", 2) == 0)
		return (3);
	if (ft_strncmp(line, "pb", 2) == 0)
		return (4);
	if (ft_strncmp(line, "ra", 2) == 0)
		return (5);
	if (ft_strncmp(line, "rb", 2) == 0)
		return (6);
	if (ft_strncmp(line, "rr", 2) == 0)
		return (7);
	if (ft_strncmp(line, "rra", 3) == 0)
		return (8);
	if (ft_strncmp(line, "rrb", 3) == 0)
		return (9);
	if (ft_strncmp(line, "rrr", 3) == 0)
		return (10);
	return (-1);
}

t_instructions	*ft_parsing_instructions()
{
	char			*line;
	t_instructions	*instructions;

	instructions = 0;
	line = get_next_line(0);
	while (line != 0)
	{
		ft_add_last_instruction(&instructions, ft_new_instruction(ft_line_to_instruction(line)));
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (instructions);
}

int	main(int narg, char **argv)
{
	t_push_swap		*push_swap;
	t_instructions	*instructions;

	if (narg < 2)
	{
		return (0);
	}
	push_swap = parsing(narg, argv);
	if (push_swap == 0)
		return (0);
	instructions = ft_parsing_instructions();
	print_instructions(instructions);
	printf("%d\n", STDIN_FILENO);
	ft_execute_instructions(push_swap, instructions);
	if (is_stack_ordered_min_max(push_swap->a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free_instructions(instructions);
	ft_free_push_swap(push_swap);
	return (0);
}
