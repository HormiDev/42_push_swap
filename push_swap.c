/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:49:23 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/05/06 01:36:27 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *p_push(t_stack *stack_a, t_stack *stack_b)
{
	t_stack *tmp;

	if (stack_a == 0)
		return (stack_b);
	tmp = stack_a->next;
	stack_a->next = stack_b;
	return (tmp);
}

t_stack	*s_swap(t_stack *stack)
{
	t_stack *tmp;

	if (stack == 0 || stack->next == 0)
		return (stack);
	tmp = stack->next;
	stack->next = tmp->next;
	tmp->next = stack;
	return (tmp);
}

void	print_stack(t_stack *stack)
{
	while (stack != 0)
	{
		printf(" %d |", stack->content);
		stack = stack->next;
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

t_stack *add_new_stack(int content, t_stack *stack)
{
	t_stack *new;

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

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	int cont;

	if (argc < 2)
	{
		printf("Error: Faltan argumentos\n");
		return (0);
	}
	cont = 1;
	while (cont < argc)
	{
		printf("%d\n", ft_atoi(argv[cont]));
		a = add_new_stack(ft_atoi(argv[cont]), a);
		cont++;
	}
	b = 0;
	print_stack(a);
	print_stack(b);
	a = s_swap(a);
	print_stack(a);
	print_stack(b);print_stack(a);
	a = p_push(a, b);
	print_stack(a);
	print_stack(b);
	return (0);
}