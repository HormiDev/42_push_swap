/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:13:47 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/07/15 00:19:50 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*ft_init_push_swap(void)
{
	t_push_swap	*push_swap;

	push_swap = malloc(sizeof(t_push_swap));
	if (push_swap == 0)
		return (0);
	push_swap->a = 0;
	push_swap->b = 0;
	return (push_swap);
}

t_push_swap	*ft_duplicate_push_swap(t_push_swap *push_swap)
{
	t_push_swap	*new;
	t_stack		*tmp;

	new = malloc(sizeof(t_push_swap));
	if (new == 0)
		return (0);
	tmp = push_swap->a;
	new->a = 0;
	while (tmp != 0)
	{
		new->a = ft_add_new_last_stack(tmp->content, new->a);
		if (new->a == 0)
		{
			free(new);
			return (0);
		}
		tmp = tmp->next;
	}
	tmp = push_swap->b;
	new->b = 0;
	return (new);
}

void	ft_free_push_swap(t_push_swap *push_swap)
{
	t_stack	*tmp;

	while (push_swap->a != 0)
	{
		tmp = push_swap->a;
		push_swap->a = push_swap->a->next;
		free(tmp);
	}
	while (push_swap->b != 0)
	{
		tmp = push_swap->b;
		push_swap->b = push_swap->b->next;
		free(tmp);
	}
	free(push_swap);
}

// borrar esta funcion
void	print_push_swap(t_push_swap *push_swap)
{
	t_stack	*tmp;

	tmp = push_swap->a;
	printf("Stack A:|");
	while (tmp != 0)
	{
		printf(" %d |", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
	tmp = push_swap->b;
	printf("Stack B:|");
	while (tmp != 0)
	{
		printf(" %d |", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}
