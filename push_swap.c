/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:49:23 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/05/13 13:51:14 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_min_int(int num_arg, ...)
{
	va_list	args;
	int		min;
	int		tmp;
	int		cont;

	va_start(args, num_arg);
	min = va_arg(args, int);
	cont = 1;
	while (cont < num_arg)
	{
		tmp = va_arg(args, int);
		if (tmp < min)
			min = tmp;
		cont++;
	}
	va_end(args);
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

/*
// algorito de ordenamiento V1
void	ft_push_swap(t_push_swap *push_swap)
{
	t_stack	*min;

	while (push_swap->a != 0)
	{
		min = ft_stack_min_num(push_swap->a);
		if (ft_stack_position(push_swap->a, min) < ft_stack_size(min))
		{
			while (push_swap->a != min)
				ra(push_swap);
		}
		else
		{
			while (push_swap->a != min)
				rra(push_swap);
		}
		pb(push_swap);
	}
	while (push_swap->b != 0)
		pa(push_swap);
}*/

void	ft_push_swap(t_push_swap *push_swap)
{
	t_stack	*min;
	t_stack	*max;
	int min_position;
	int min_size;
	int max_position;
	int max_size;
	int min_dintance;

	while (push_swap->a != 0)
	{
		//print_push_swap(push_swap);
		min = ft_stack_min_num(push_swap->a);
		max = ft_stack_max_num(push_swap->a);
		min_position = ft_stack_position(push_swap->a, min);
		min_size = ft_stack_size(min);
		max_position = ft_stack_position(push_swap->a, max) + 2;
		max_size = ft_stack_size(max) + 2;
		min_dintance = ft_get_min_int(4, min_position, min_size, max_position, max_size);
		if (min_dintance == min_position)
		{
			while (push_swap->a != min)
				ra(push_swap);
			pb(push_swap);
		}
		else if (min_dintance == min_size)
		{
			while (push_swap->a != min)
				rra(push_swap);
			pb(push_swap);
		}
		else if (min_dintance == max_position)
		{
			while (push_swap->a != max)
				ra(push_swap);
			pb(push_swap);
			rb(push_swap);
		}
		else
		{
			while (push_swap->a != max)
				rra(push_swap);
			pb(push_swap);
			rb(push_swap);
		}
	}
	//print_push_swap(push_swap);
	max = ft_stack_max_num(push_swap->b);
	if (ft_stack_position(push_swap->b, max) < ft_stack_size(max))
	{
		while (push_swap->b != max)
			rb(push_swap);
	}
	else
	{
		while (push_swap->b != max)
			rrb(push_swap);
	}
	//print_push_swap(push_swap);
	while (push_swap->b != 0)
		pa(push_swap);
}

t_stack	*stack_last(t_stack *stack)
{
	if (stack == 0)
		return (0);
	while (stack->next != 0)
		stack = stack->next;
	return (stack);
}

t_stack *ft_add_new_last_stack(int content, t_stack *stack)
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

t_push_swap *ft_init_push_swap(void)
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
	push_swap = ft_init_push_swap();
	if (push_swap == 0)
	{
		printf("Error: No se pudo inicializar push_swap\n");
		return (0);
	}
	while (cont < argc)
	{
		push_swap->a = ft_add_new_last_stack(ft_atoi(argv[cont]), push_swap->a);
		cont++;
	}
	ft_push_swap(push_swap);
	//print_push_swap(push_swap);
	ft_free_push_swap(push_swap);
	return (0);
}
