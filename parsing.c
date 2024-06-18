/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:19:36 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/18 23:42:34 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_repeat(int n, t_stack *a)
{
	while (a)
	{
		if (a->content == n)
			return (1);
		a = a->next;
	}
	return (0);
}

static t_push_swap	*parsing2(int i, t_push_swap *ps, char ***input)
{
	int		j;

	while (input[i])
	{
		j = 0;
		while (input[i][j])
		{
			if (ft_is_repeat(ft_atoi(input[i][j]), ps->a) ||
				ft_atol(input[i][j]) > 2147483647 ||
				ft_atol(input[i][j]) < -2147483648)
			{
				ft_free_input(input);
				ft_free_push_swap(ps);
				write(2, "Error\n", 6);
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

t_push_swap	*parsig(int argc, char **argv)
{
	t_push_swap	*ps;
	int			i;
	char		***input;

	i = 0;
	ps = malloc(sizeof(t_push_swap));
	input = ft_read_imput(argc, argv);
	if (!ft_check_input(input))
	{
		ft_free_input(input);
		write(2, "Error\n", 6);
		return (0);
	}
	ps = ft_init_push_swap();
	if (!ps)
	{
		ft_free_input(input);
		return (0);
	}
	return (parsing2(i, ps, input));
}
