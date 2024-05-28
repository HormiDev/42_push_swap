/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:49:48 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/05/24 20:46:19 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "42_Libft/libft.h"

typedef struct stack
{
	int				content;
	struct stack	*next;
}	t_stack;

typedef struct push_swap
{
	t_stack	*a;
	t_stack	*b;
}	t_push_swap;

typedef struct instructions
{
	char	instruction;
	void	(*f)(t_push_swap *push_swap);
	struct instructions	*next;
	struct instructions	*prev;
}	t_instructions;

//utils
int		ft_isdigit(int c);
int		ft_atoi(const char *str);

//push_swap_utils
t_stack	*stack_last(t_stack *stack);

//swap
void	sa(t_push_swap *push_swap);
void	sb(t_push_swap *push_swap);
void	ss(t_push_swap *push_swap);

//push
void	pa(t_push_swap *push_swap);
void	pb(t_push_swap *push_swap);

//rotate
void	ra(t_push_swap *push_swap);
void	rb(t_push_swap *push_swap);
void	rr(t_push_swap *push_swap);

//reverse_rotate
void	rra(t_push_swap *push_swap);
void	rrb(t_push_swap *push_swap);
void	rrr(t_push_swap *push_swap);

//push_swap
t_push_swap *ft_init_push_swap(void);

#endif