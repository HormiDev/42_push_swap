/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 19:52:26 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/26 01:47:35 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	***ft_read_imput(int narg, char **argv)
{
	char	***input;
	int		i;

	i = 0;
	input = malloc(sizeof(char **) * (narg - 1));
	while (i + 1 < narg)
	{
		input[i] = *ft_split(argv[i + 1], ' ');
		i++;
	}
	input[i] = 0;
	return (input);
}

int	ft_check_input(char ***input)
{
	int	i[3];

	if (!input)
		return (0);
	i[0] = 0;
	while (input[i[0]])
	{
		i[1] = 0;
		while (input[i[0]][i[1]])
		{
			i[2] = 0;
			if (input[i[0]][i[1]][i[2]] != '-' && input[i[0]][i[1]][i[2]] != '+'
			&& !ft_isdigit(input[i[0]][i[1]][i[2]]))
				return (0);
			i[2] = 1;
			while (input[i[0]][i[1]][i[2]] != '\0')
			{
				if (!ft_isdigit(input[i[0]][i[1]][i[2]++]))
					return (0);
			}
			i[1]++;
		}
		i[0]++;
	}
	return (1);
}

//revisar leaks de la funcion
void	ft_free_input(char ***input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (input[i][j] != 0)
				free(input[i][j]);
			j++;
		}
		i++;
	}
	if (input != 0)
		free(input);
}

// funcion para comentar
void	print_input(char ***input)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			printf("%s ", input[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
