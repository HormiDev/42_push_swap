/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:49:23 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/03 01:19:31 by ide-dieg         ###   ########.fr       */
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

/*
// algorito de ordenamiento V1
void	ft_push_swap(t_push_swap *push_swap)
{
	t_stack	*min;

	while (push_swap->a != 0)
	{
		min = ft_stack_min_num(push_swap->a);
		if (ft_stack_position(push_swap->a, min) < ft_stack_size(min))
		{
			while (push_swap->a != min)
				ra(push_swap);
		}
		else
		{
			while (push_swap->a != min)
				rra(push_swap);
		}
		pb(push_swap);
	}
	while (push_swap->b != 0)
		pa(push_swap);
}*/

/*
// algorito de ordenamiento V2
void	ft_push_swap(t_push_swap *push_swap)
{
	t_stack	*min;
	t_stack	*max;
	int min_position;
	int min_size;
	int max_position;
	int max_size;
	int min_dintance;

	while (push_swap->a != 0)
	{
		//print_push_swap(push_swap);
		min = ft_stack_min_num(push_swap->a);
		max = ft_stack_max_num(push_swap->a);
		min_position = ft_stack_position(push_swap->a, min);
		min_size = ft_stack_size(min);
		max_position = ft_stack_position(push_swap->a, max) + 2;
		max_size = ft_stack_size(max) + 2;
		min_dintance = ft_get_min_int(4, min_position, min_size, max_position, max_size);
		if (min_dintance == min_position)
		{
			while (push_swap->a != min)
				ra(push_swap);
			pb(push_swap);
		}
		else if (min_dintance == min_size)
		{
			while (push_swap->a != min)
				rra(push_swap);
			pb(push_swap);
		}
		else if (min_dintance == max_position)
		{
			while (push_swap->a != max)
				ra(push_swap);
			pb(push_swap);
			rb(push_swap);
		}
		else
		{
			while (push_swap->a != max)
				rra(push_swap);
			pb(push_swap);
			rb(push_swap);
		}
	}
	//print_push_swap(push_swap);
	max = ft_stack_max_num(push_swap->b);
	if (ft_stack_position(push_swap->b, max) < ft_stack_size(max))
	{
		while (push_swap->b != max)
			rb(push_swap);
	}
	else
	{
		while (push_swap->b != max)
			rrb(push_swap);
	}
	//print_push_swap(push_swap);
	while (push_swap->b != 0)
		pa(push_swap);
}
*/
/*
// algorito de ordenamiento V3
void	ft_push_swap(t_push_swap *push_swap)
{
	while (is_stack_ordered_min_MAX(push_swap->a) == 0)
	{
		if (push_swap->a->content > push_swap->a->next->content && 
		push_swap->a->next != ft_stack_min_num(push_swap->a))
			sa(push_swap);
		else
			ra(push_swap);
	}
}
*/

int main(int argc, char **argv)
{
	t_push_swap *push_swap;
	int cont;

	cont = 1;
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	push_swap = parsig(argc, argv);
	if (push_swap == 0)
		return (0);
	ft_push_swap_fb(push_swap);
	//print_push_swap(push_swap);
	ft_free_push_swap(push_swap);
	return (0);
}
