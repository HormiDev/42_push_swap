/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:49:23 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/05/31 20:06:21 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_stack *ft_add_new_last_stack(int content, t_stack *stack);

int ft_min_from_num(t_stack *stack, int num)
{
	int	min;

	min = 2147483647;
	while (stack != 0)
	{
		if (stack->content > num && min < stack->content)
			min = stack->content;
		stack = stack->next;
	}
	return (min);
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

int ft_max_from_num(t_stack *stack, int num)
{
	int	max;

	max = -2147483648;
	while (stack != 0)
	{
		if (stack->content <= num && max < stack->content)
			max = stack->content;
		stack = stack->next;
	}
	return (max);
}
/*
t_stack	*ft_compress_stack(t_stack *stack)
{
	t_stack	*tmp;
	int		min;
	int 	cont;
	
	min = -2147483648;
	cont = ft_stack_size(stack);
	tmp = stack;
	while (cont > 0)
	{
		tmp = ft_min_from_num(stack, min);
		tmp->content = min;
		min++;
		cont--;
	}
	while (stack != 0)
	{
		stack->content = stack->content + 2147483648;
		stack = stack->next;
	}
	return (tmp);
}*/

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

int	is_stack_ordered_min_MAX(t_stack *stack)
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
t_push_swap *ft_duplicate_push_swap(t_push_swap *push_swap)
{
	t_push_swap *new;
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

t_instructions	*ft_new_instruction(char instruction)
{
	t_instructions	*new;

	new = malloc(sizeof(t_instructions));
	if (new == 0)
		return (0);
	new->instruction = instruction;
	new->f = &sa;
	new->next = 0;
	new->prev = 0;
	return (new);
}

void ft_add_last_instruction(t_instructions *instructions, t_instructions *new)
{
	if (instructions == 0)
		return ;
	while (instructions->next != 0)
		instructions = instructions->next;
	instructions->next = new;
	new->prev = instructions;
}

void	ft_next_instruction(t_instructions *instruction)
{
	if (instruction == 0)
		return ;
	if(instruction->instruction == 0)
	{
		instruction->instruction = 1;
		instruction->f = &sb;
	}
	else if(instruction->instruction == 1)
	{
		instruction->instruction = 2;
		instruction->f = &ss;
	}
	else if(instruction->instruction == 2)
	{
		instruction->instruction = 3;
		instruction->f = &pa;
	}
	else if(instruction->instruction == 3)
	{
		instruction->instruction = 4;
		instruction->f = &pb;
	}
	else if(instruction->instruction == 4)
	{
		instruction->instruction = 5;
		instruction->f = &ra;
	}
	else if(instruction->instruction == 5)
	{
		instruction->instruction = 6;
		instruction->f = &rb;
	}
	else if(instruction->instruction == 6)
	{
		instruction->instruction = 7;
		instruction->f = &rr;
	}
	else if(instruction->instruction == 7)
	{
		instruction->instruction = 8;
		instruction->f = &rra;
	}
	else if(instruction->instruction == 8)
	{
		instruction->instruction = 9;
		instruction->f = &rrb;
	}
	else if(instruction->instruction == 9)
	{
		instruction->instruction = 10;
		instruction->f = &rrr;
	}
	else if(instruction->instruction == 10)
	{
		instruction->instruction = 0;
		instruction->f = &sa;
		if (instruction->next != 0)
			ft_next_instruction(instruction->next);
		else
			ft_add_last_instruction(instruction, ft_new_instruction(0));
	}
}

void	ft_execute_instructions(t_push_swap *push_swap, t_instructions *instructions)
{
	while (instructions != 0)
	{
		instructions->f(push_swap);
		instructions = instructions->next;
	}
}

void	print_instructions(t_instructions *instructions)
{
	while (instructions != 0)
	{
		if (instructions->instruction == 0)
			printf("sa\n");
		else if (instructions->instruction == 1)
			printf("sb\n");
		else if (instructions->instruction == 2)
			printf("ss\n");
		else if (instructions->instruction == 3)
			printf("pa\n");
		else if (instructions->instruction == 4)
			printf("pb\n");
		else if (instructions->instruction == 5)
			printf("ra\n");
		else if (instructions->instruction == 6)
			printf("rb\n");
		else if (instructions->instruction == 7)
			printf("rr\n");
		else if (instructions->instruction == 8)
			printf("rra\n");
		else if (instructions->instruction == 9)
			printf("rrb\n");
		else if (instructions->instruction == 10)
			printf("rrr\n");
		instructions = instructions->next;
	}
}

void	ft_free_instructions(t_instructions *instructions)
{
	t_instructions *tmp;

	while (instructions != 0)
	{
		tmp = instructions;
		instructions = instructions->next;
		free(tmp);
	}
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

/*
// algorito de ordenamiento V2
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
*/
/*
// algorito de ordenamiento V3
void	ft_push_swap(t_push_swap *push_swap)
{
	while (is_stack_ordered_min_MAX(push_swap->a) == 0)
	{
		if (push_swap->a->content > push_swap->a->next->content && 
		push_swap->a->next != ft_stack_min_num(push_swap->a))
			sa(push_swap);
		else
			ra(push_swap);
	}
}
*/

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

int main(int argc, char **argv)
{
	t_push_swap *push_swap;
	int cont;

	cont = 1;
	if (argc < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	push_swap = parsig(argc, argv);
	if (push_swap == 0)
		return (0);
	ft_push_swap_fb(push_swap);
	//print_push_swap(push_swap);
	ft_free_push_swap(push_swap);
	return (0);
}
