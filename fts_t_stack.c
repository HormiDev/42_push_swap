/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 00:28:47 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/03 01:05:53 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_add_new_last_stack(int content, t_stack *stack)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == 0)
		return (0);
	new->content = content;
	new->next = 0;
	if (stack == 0)
		return (new);
	stack_last(stack)->next = new;
	return (stack);
}

t_stack	*stack_last(t_stack *stack)
{
	if (stack == 0)
		return (0);
	while (stack->next != 0)
		stack = stack->next;
	return (stack);
}

int	ft_stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack != 0)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

int	is_stack_ordered_min_max(t_stack *stack)
{
	if (stack == 0)
		return (1);
	if (stack->next == 0)
		return (0);
	while (stack->content < stack->next->content)
	{
		stack = stack->next;
		if (stack->next == 0)
			return (1);
	}
	return (0);
}

int	ft_stack_position(t_stack *stack, t_stack *element)
{
	int	position;

	position = 0;
	if (stack == 0 || element == 0)
		return (0);
	while (stack != 0)
	{
		if (stack == element)
			return (position);
		position++;
		stack = stack->next;
	}
	return (0);
}
