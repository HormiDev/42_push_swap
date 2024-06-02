/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:50:31 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/02 20:38:13 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*reverse_rotate(t_stack *stack)
{
	t_stack	*tmp;

	if (stack == 0 || stack->next == 0)
		return (stack);
	tmp = stack_last(stack);
	tmp->next = stack;
	while (stack->next != tmp)
	{
		stack = stack->next;
	}
	stack->next = 0;
	return (tmp);
}

void	rra(t_push_swap *push_swap)
{
	push_swap->a = reverse_rotate(push_swap->a);
	//printf("rra\n");
}

void	rrb(t_push_swap *push_swap)
{
	push_swap->b = reverse_rotate(push_swap->b);
	//printf("rrb\n");
}

void	rrr(t_push_swap *push_swap)
{
	push_swap->a = reverse_rotate(push_swap->a);
	push_swap->b = reverse_rotate(push_swap->b);
	//printf("rrr\n");
}
