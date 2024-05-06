/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 21:28:51 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/05/06 23:28:45 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *tmp;

	if (*stack_b == 0)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
}

void	pa(t_push_swap *push_swap)
{
	push(&push_swap->a, &push_swap->b);
}

void	pb(t_push_swap *push_swap)
{
	push(&push_swap->b, &push_swap->a);
}