/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:30:41 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/03 19:01:37 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*rotate(t_stack *stack)
{
	t_stack	*tmp;

	if (stack == 0 || stack->next == 0)
		return (stack);
	tmp = stack_last(stack);
	tmp->next = stack;
	stack = stack->next;
	tmp->next->next = 0;
	return (stack);
}

void	ra(t_push_swap *push_swap)
{
	push_swap->a = rotate(push_swap->a);
}

void	rb(t_push_swap *push_swap)
{
	push_swap->b = rotate(push_swap->b);
}

void	rr(t_push_swap *push_swap)
{
	push_swap->a = rotate(push_swap->a);
	push_swap->b = rotate(push_swap->b);
}
