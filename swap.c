/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 19:57:45 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/02 20:38:03 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*swap(t_stack *stack)
{
	t_stack	*tmp;

	if (stack == 0 || stack->next == 0)
		return (stack);
	tmp = stack->next;
	stack->next = tmp->next;
	tmp->next = stack;
	return (tmp);
}

void	sa(t_push_swap *push_swap)
{
	push_swap->a = swap(push_swap->a);
	//printf("sa\n");
}

void	sb(t_push_swap *push_swap)
{
	push_swap->b = swap(push_swap->b);
	//printf("sb\n");
}

void	ss(t_push_swap *push_swap)
{
	push_swap->a = swap(push_swap->a);
	push_swap->b = swap(push_swap->b);
	//printf("ss\n");
}
