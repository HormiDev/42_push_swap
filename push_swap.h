/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:49:48 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/02 20:05:51 by ide-dieg         ###   ########.fr       */
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

//temporales
void print_push_swap(t_push_swap *push_swap);

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
t_push_swap *parsig(int argc, char **argv);
t_stack *ft_add_new_last_stack(int content, t_stack *stack);
void	ft_free_push_swap(t_push_swap *push_swap);

//algorintms
void ft_push_swap_fb(t_push_swap *push_swap);

//input
char ***ft_read_imput(int narg, char **argv);
int	ft_check_input(char ***input);
void	ft_free_input(char ***input);

//funciones de prueba (comentar)
void print_stack(t_stack *stack);
void print_instructions(t_instructions *instructions);
void print_push_swap(t_push_swap *push_swap);
void print_input(char ***input);

#endif