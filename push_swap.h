/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:49:48 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/04 22:58:31 by ide-dieg         ###   ########.fr       */
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
	char				instruction;
	void				(*f)(t_push_swap *push_swap);
	struct instructions	*next;
	struct instructions	*prev;
}	t_instructions;

//swap
void			sa(t_push_swap *push_swap);
void			sb(t_push_swap *push_swap);
void			ss(t_push_swap *push_swap);

//push
void			pa(t_push_swap *push_swap);
void			pb(t_push_swap *push_swap);

//rotate
void			ra(t_push_swap *push_swap);
void			rb(t_push_swap *push_swap);
void			rr(t_push_swap *push_swap);

//reverse_rotate
void			rra(t_push_swap *push_swap);
void			rrb(t_push_swap *push_swap);
void			rrr(t_push_swap *push_swap);

//push_swap
t_push_swap		*ft_init_push_swap(void);
t_push_swap		*ft_duplicate_push_swap(t_push_swap *push_swap);
t_push_swap		*parsig(int argc, char **argv);
t_stack			*ft_add_new_last_stack(int content, t_stack *stack);
void			ft_free_push_swap(t_push_swap *push_swap);
int				ft_get_min_int(int num_arg, ...);

//input
char			***ft_read_imput(int narg, char **argv);
int				ft_check_input(char ***input);
void			ft_free_input(char ***input);

//funciones de prueba (comentar funciones)
void			print_push_swap(t_push_swap *push_swap);
void			print_input(char ***input);

//algoritmos de ordenamiento
void			ft_push_swap_fb(t_push_swap *push_swap);
void			ft_push_swap_v1(t_push_swap *push_swap);
void			ft_push_swap_v2(t_push_swap *push_swap);
void			ft_push_swap_v3(t_push_swap *push_swap);

//t_instructions
t_instructions	*ft_new_instruction(char instruction);
void			ft_add_last_instruction(t_instructions **instructions,
					t_instructions *new);
void			ft_free_instructions(t_instructions *instructions);
void			ft_execute_instructions(t_push_swap *push_swap,
					t_instructions *instructions);
void			print_instructions(t_instructions *instructions);
void			ft_next_instruction(t_instructions *instruction);
void			*select_function_for_instruction(char instruction);

//t_stack
t_stack			*ft_add_new_last_stack(int content, t_stack *stack);
t_stack			*stack_last(t_stack *stack);
int				ft_stack_size(t_stack *stack);
int				is_stack_ordered_min_max(t_stack *stack);
int				ft_stack_position(t_stack *stack, t_stack *element);
t_stack			*ft_stack_min_num(t_stack *stack);
t_stack			*ft_stack_max_num(t_stack *stack);
int				ft_min_from_num(t_stack *stack, int num);
int				ft_max_from_num(t_stack *stack, int num);

#endif