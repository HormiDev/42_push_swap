/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 23:49:48 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/09/13 22:29:19 by ide-dieg         ###   ########.fr       */
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

typedef struct strlst
{
	char			*content;
	struct strlst	*next;
}	t_strlst;

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
t_push_swap		*parsing(int narg, char **argv);
t_stack			*ft_add_new_last_stack(int content, t_stack *stack);
void			ft_free_push_swap(t_push_swap *push_swap);
int				ft_get_min_int(int num_arg, ...);
int				ft_diference(int a, int b);
long			ft_atol(const char *str);

//input
t_strlst		*ft_read_imput(int narg, char **argv);
int				ft_check_input(t_strlst *input);

//funciones de prueba (comentar funciones)
void			print_push_swap(t_push_swap *push_swap);
void			print_input(char ***input);

//algoritmos de ordenamiento
void			ft_push_swap_fb(t_push_swap *push_swap);
void			ft_push_swap_v1(t_push_swap *push_swap);
void			ft_push_swap_v2(t_push_swap *push_swap);
void			ft_push_swap_v3(t_push_swap *push_swap);
void			ft_push_swap_v4(t_push_swap *push_swap);
void			ft_push_swap_v5(t_push_swap *push_swap);
void			ft_push_swap_v6(t_push_swap *push_swap);
void			ft_push_swap_v7(t_push_swap *push_swap);
void			ft_push_swap_rg(t_push_swap *push_swap);
t_instructions	*ft_push_swap_v7_rg(t_push_swap *push_swap,
					int range, int return_range);

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
t_instructions	*ft_last_instruction(t_instructions *instructions);
void			ft_change_instruction(t_instructions *instruction, char new);
void			ft_delete_instruction(t_instructions *instruction);
void			ft_compress_instructions(t_instructions *instructions);
int				ft_equal_instruction_cont(t_instructions *instruction);
void			ft_compress_rotates(t_instructions *instruction1,
					t_instructions *instruction2);
int				ft_len_instructions(t_instructions *instructions);

//t_stack
t_stack			*ft_add_new_last_stack(int content, t_stack *stack);
t_stack			*stack_last(t_stack *stack);
int				ft_stack_size(t_stack *stack);
int				is_stack_ordered_min_max(t_stack *stack);
int				ft_stack_position(t_stack *stack, t_stack *element);
t_stack			*ft_stack_min_num(t_stack *stack);
t_stack			*ft_stack_max_num(t_stack *stack);
t_stack			*ft_min_stack_from_num(t_stack *stack, int num);
t_stack			*ft_max_stack_from_num(t_stack *stack, int num);
t_stack			*ft_compress_stack(t_stack *stack);
t_stack			*ft_first_stack_in_range(t_stack *stack, int min, int max);
t_stack			*ft_last_stack_in_range(t_stack *stack, int min, int max);
t_stack			*ft_copy_stack(t_stack *stack);

//t_strlst
int				ft_strlst_size(t_strlst *lst);
t_strlst		*ft_strlst_add_new(char *content, t_strlst *lst);
void			ft_strlst_clear(t_strlst *lst);
t_strlst		*ft_strlst_last(t_strlst *lst);
void			print_strlst(t_strlst *lst);

#endif