/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:19:36 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/05/22 18:25:55 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	***ft_read_imput(int argc, char **argv)
{
	char ***input;
	int i;

	i = 0;
	input = malloc(sizeof(char **) * argc);
	while (i < argc)
	{
		input[i] = ft_split(argv[i], ' ');
		i++;
	}
	return (input);
}

int	ft_check_input(char ***input)
{
	int i;
	int j;
	int k;

	if (!input)
		return (0);
	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if(input[i][j][k] != '-' && input[i][j][k] != '+' && !ft_isdigit(input[i][j][k]))
				return (0);
			k = 1;
			while (input[i][j][k])
			{
				if (!ft_isdigit(input[i][j][k]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_free_input(char ***input)
{
	int i;
	int j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			free(input[i][j]);
			j++;
		}
		free(input[i]);
		i++;
	}
	free(input);
}

t_push_swap *parsig(int argc, char **argv)
{
	t_push_swap	*ps;
	int			i;
	int			j;
	char		***input; 

	i = 0;
	ps = malloc(sizeof(t_push_swap));
	input = read_imput(argc, argv);
	if (!check_input(input))
	{
		ft_free_input(input);
		write(1, "Error\n", 6);
		return (0);
	}
	ps = ft_init_push_swap();
	if (!ps)
	{
		ft_free_input(input);
		return (0);
	}
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			ps->a = ft_stack_add_back(ps->a, ft_atoi(input[i][j]));
			j++;
		}
		i++;
	}
}
