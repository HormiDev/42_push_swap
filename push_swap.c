/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:49:23 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/05/07 23:57:26 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int stack_size(t_stack *stack)
{
	int size;

	size = 0;
	while (stack != 0)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack	*min_num(t_stack *stack)
{
	t_stack *min;

	min = stack;
	while (stack != 0)
	{
		if (stack->content < min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void print_push_swap(t_push_swap *push_swap)
{
	t_stack *tmp;

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

t_stack	*stack_last(t_stack *stack)
{
	if (stack == 0)
		return (0);
	while (stack->next != 0)
		stack = stack->next;
	return (stack);
}

t_stack *add_front_new_stack(int content, t_stack *stack)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (new == 0)
		return (0);
	new->content = content;
	new->next = stack;
	return (new);
}

t_push_swap *init_push_swap(void)
{
	t_push_swap *push_swap;

	push_swap = malloc(sizeof(t_push_swap));
	if (push_swap == 0)
		return (0);
	push_swap->a = 0;
	push_swap->b = 0;
	return (push_swap);
}

int main(int argc, char **argv)
{
	t_push_swap *push_swap;
	int cont;

	cont = 1;
	if (argc < 2)
	{
		printf("Error: Faltan argumentos\n");
		return (0);
	}
	push_swap = init_push_swap();
	if (push_swap == 0)
	{
		printf("Error: No se pudo inicializar push_swap\n");
		return (0);
	}
	while (cont < argc)
	{
		push_swap->a = add_front_new_stack(ft_atoi(argv[cont]), push_swap->a);
		cont++;
	}
	printf("inicio\n");
	push_swap->b = add_front_new_stack(5, push_swap->b);
	print_push_swap(push_swap);
	printf("sa\n");
	sa(push_swap);
	print_push_swap(push_swap);
	printf("pa\n");
	pa(push_swap);
	print_push_swap(push_swap);
	printf("ra\n");
	ra(push_swap);
	print_push_swap(push_swap);
	printf("rra\n");
	rra(push_swap);
	print_push_swap(push_swap);
	return (0);
}