/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_stack2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 01:09:20 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/03 01:14:50 by ide-dieg         ###   ########.fr       */
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

int	ft_min_from_num(t_stack *stack, int num)
{
	int	min;

	min = 2147483647;
	while (stack != 0)
	{
		if (stack->content > num && min < stack->content)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
}

int	ft_max_from_num(t_stack *stack, int num)
{
	int	max;

	max = -2147483648;
	while (stack != 0)
	{
		if (stack->content <= num && max < stack->content)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}
