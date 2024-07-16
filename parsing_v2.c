/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_v2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:00:49 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/07/16 23:48:59 by ide-dieg         ###   ########.fr       */
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

static t_push_swap	*parsing2(t_push_swap *ps, t_strlst *input)
{
	t_strlst	*tmp;

	tmp = input;
	while (tmp)
	{
		if (ft_is_repeat(ft_atoi(tmp->content), ps->a) ||
			ft_atol(tmp->content) > 2147483647 ||
			ft_atol(tmp->content) < -2147483648)
		{
			ft_strlst_clear(input);
			ft_free_push_swap(ps);
			write(2, "Error\n", 6);
			return (0);
		}
		ps->a = ft_add_new_last_stack(ft_atoi(tmp->content), ps->a);
		tmp = tmp->next;
		
	}
	ft_strlst_clear(input);
	return (ps);
}

t_push_swap	*parsing(int narg, char **argv)
{
	t_push_swap	*ps;
	t_strlst	*input;

	input = ft_read_imput(narg, argv);
	if (!ft_check_input(input))
	{
		ft_strlst_clear(input);
		write(2, "Error\n", 6);
		return (0);
	}
	ps = ft_init_push_swap();
	if (!ps)
	{
		ft_strlst_clear(input);
		return (0);
	}
	return (parsing2(ps, input));
}
