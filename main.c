/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:49:23 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/12 02:30:45 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	*push_swap;

	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	push_swap = parsig(argc, argv);
	if (push_swap == 0)
		return (0);
	if (ft_stack_size(push_swap->a) < 6)
		ft_push_swap_fb(push_swap);
	else
		ft_push_swap_v4(push_swap);
	ft_free_push_swap(push_swap);
	return (0);
}
