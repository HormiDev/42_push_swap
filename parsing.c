/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:19:36 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/05/31 20:42:12 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int ft_is_repeat(int n, t_stack *a)
{
	while (a)
	{
		if (a->content == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	print_input(char ***input)
{
	int i;
	int j;

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

char	***ft_read_imput(int narg, char **argv)
{
	char ***input;
	int i;

	i = 0;
	input = malloc(sizeof(char **) * (narg - 1));
	while (i + 1 < narg)
	{
		input[i] = ft_split(argv[i + 1], ' ');
		i++;
	}
	//print_input(input);
	input[i] = 0;
	//printf("input[%d] narg[%d]\n", i, narg - 1);
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
			k = 0;
			if(input[i][j][k] != '-' && input[i][j][k] != '+' && !ft_isdigit(input[i][j][k]))
				return (0);
			k = 1;
			while (input[i][j][k] != '\0')
			{
				if (!ft_isdigit(input[i][j][k]))
					return (0);
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

//revisar leaks de la funcion
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
			if (input[i][j] != 0)
				free(input[i][j]);
			j++;
		}
		i++;
	}
	if (input != 0)
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
	input = ft_read_imput(argc, argv);
	if (!ft_check_input(input))
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
			if (ft_is_repeat(ft_atoi(input[i][j]), ps->a))
			{
				ft_free_input(input);
				ft_free_push_swap(ps);
				write(1, "Error\n", 6);
				return (0);
			}
			ps->a = ft_add_new_last_stack(ft_atoi(input[i][j]), ps->a);
			j++;
		}
		i++;
	}
	ft_free_input(input);
	return (ps);
}