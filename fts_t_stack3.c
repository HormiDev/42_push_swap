/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_stack3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:03:25 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/12 13:12:59 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_first_stack_in_range(t_stack *stack, int min, int max)
{
	t_stack	*first;

	first = stack;
	while (first != 0)
	{
		if (first->content >= min && first->content <= max)
			return (first);
		first = first->next;
	}
	return (stack);
}

t_stack	*ft_last_stack_in_range(t_stack *stack, int min, int max)
{
	t_stack	*last;

	last = stack;
	while (last != 0)
	{
		if (last->content >= min && last->content <= max)
			stack = last;
		last = last->next;
	}
	return (stack);
}
