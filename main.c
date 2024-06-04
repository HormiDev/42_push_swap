/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:49:23 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/04 13:51:39 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
t_stack	*ft_compress_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		min;
	int 	cont;
	
	min = -2147483648;
	cont = ft_stack_size(stack);
	tmp = stack;
	while (cont > 0)
	{
		tmp = ft_min_from_num(stack, min);
		tmp->content = min;
		min++;
		cont--;
	}
	while (stack != 0)
	{
		stack->content = stack->content + 2147483648;
		stack = stack->next;
	}
	return (tmp);
}*/

int main(int argc, char **argv)
{
	t_push_swap *push_swap;

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
		ft_push_swap_v1(push_swap);
	ft_free_push_swap(push_swap);
	return (0);
}
