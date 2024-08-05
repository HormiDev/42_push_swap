/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:49:23 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/08/05 10:52:28 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int narg, char **argv)
{
	t_push_swap	*push_swap;

	if (narg < 2)
	{
		return (0);
	}
	push_swap = parsing(narg, argv);
	if (push_swap == 0)
		return (0);
	ft_compress_stack(push_swap->a);
	if (is_stack_ordered_min_max(push_swap->a))
	{
		ft_free_push_swap(push_swap);
		return (0);
	}
	if (ft_stack_size(push_swap->a) < 6)
		ft_push_swap_fb(push_swap);
	else
		ft_push_swap_v7(push_swap);
	ft_free_push_swap(push_swap);
	return (0);
}
/*
int main(int argc, char **argv)
{
	t_strlst	*input = 0;
	int cont = 0; 

	while (cont < argc)
	{
		input = ft_strlst_add_new(ft_strdup(argv[cont]), input);
		cont++;
	}
	printf("Input:\n");
	print_strlst(input);
	ft_strlst_clear(input);
	return (0);
}
*/