/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_stack2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:09:20 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/15 23:12:03 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_min_num(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack != 0)
	{
		if (stack->content < min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*ft_stack_max_num(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack != 0)
	{
		if (stack->content > max->content)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*ft_min_stack_from_num(t_stack *stack, int num)
{
	t_stack	*min;

	min = ft_stack_max_num(stack);
	while (stack != 0)
	{
		if (stack->content >= num && stack->content < min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*ft_max_stack_from_num(t_stack *stack, int num)
{
	t_stack	*max;

	max = ft_stack_min_num(stack);
	while (stack != 0)
	{
		if (stack->content <= num && stack->content > max->content)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*ft_compress_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		min;
	int		cont;

	min = -2147483648;
	cont = ft_stack_size(stack);
	while (cont > 0)
	{
		tmp = ft_min_stack_from_num(stack, min);
		tmp->content = min;
		min++;
		cont--;
	}
	return (tmp);
}
