/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_v5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:40:58 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/06/19 22:52:18 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_to_a_v5(t_push_swap *push_swap, t_instructions *instructions)
{
	t_stack	*min;
	t_stack	*max;
	int		min_position;
	int		min_size;
	int		max_position;
	int		max_size;
	int		min_dintance;
	while (push_swap->b != 0)
	{
		min = ft_stack_min_num(push_swap->b);
		max = ft_stack_max_num(push_swap->b);
		min_position = ft_stack_position(push_swap->b, min) + 2;
		min_size = ft_stack_size(min) + 2;
		max_position = ft_stack_position(push_swap->b, max);
		max_size = ft_stack_size(max);
		min_dintance = ft_get_min_int(4, min_position, min_size, max_position, max_size);
		//si la distancaia minima es la posicion del maximo, rotar hasta que el maximo este en la primera posicion
		if (min_dintance == max_position)
		{
			while (push_swap->b != max)
			{
				rb(push_swap);
				ft_add_last_instruction(&instructions, ft_new_instruction(6));
			}
			pa(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(3));
		}
		//si la distancia minima es el tamaño del maximo, rotar hasta que el maximo este en la ultima posicion
		else if (min_dintance == max_size)
		{
			while (push_swap->b != max)
			{
				rrb(push_swap);
				ft_add_last_instruction(&instructions, ft_new_instruction(9));
			}
			pa(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(3));
		}
		//si la distancia minima es la posicion del minimo, rotar hasta que el minimo este en la primera posicion
		else if (min_dintance == min_position)
		{
			while (push_swap->b != min)
			{
				rb(push_swap);
				ft_add_last_instruction(&instructions, ft_new_instruction(6));
			}
			pa(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(3));
			ra(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(5));
		}
		//si la distancia minima es el tamaño del minimo, rotar hasta que el minimo este en la ultima posicion
		else
		{
			while (push_swap->b != min)
			{
				rrb(push_swap);
				ft_add_last_instruction(&instructions, ft_new_instruction(9));
			}
			pa(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(3));
			ra(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(5));
		}
	}
	//si la posicion del minimo no es la primera, rotar hasta que sea la primera en la direccion mas corta
	min = ft_stack_min_num(push_swap->a);
	if (ft_stack_position(push_swap->a, min) < ft_stack_size(min))
	{
		while (push_swap->a != min)
		{
			ra(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(5));
		}
	}
	else
	{
		while (push_swap->a != min)
		{
			rra(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(8));
		}
	}
	
}

t_instructions	*ft_move_to_b_v5(t_push_swap *push_swap, int range)
{
	t_instructions	*instructions;
	int				min;

	instructions = 0;
	while(push_swap->a != 0)
	{
		min = ft_stack_min_num(push_swap->a)->content;
		if (push_swap->a->content <= min + range)
		{
			pb(push_swap);
			ft_add_last_instruction(&instructions, ft_new_instruction(4));
			//si la diferencia entre el primer y segundo es mayor que la diferencia entre el primer y el ultimo mueve el el primero al final
			if (ft_diference(push_swap->b->content, min) > range / 2)
			{
				rb(push_swap);
				ft_add_last_instruction(&instructions, ft_new_instruction(6));
			}
		}
		else
		{
			if (ft_stack_position(push_swap->a ,ft_first_stack_in_range(push_swap->a, min, min + range)) < ft_stack_size(ft_last_stack_in_range(push_swap->a, min, min + range)))
			{
				ra(push_swap);
				ft_add_last_instruction(&instructions, ft_new_instruction(5));
			}
			else
			{
				rra(push_swap);
				ft_add_last_instruction(&instructions, ft_new_instruction(8));
			}
		}
	}
	return (instructions);
}

// algorito de ordenamiento V5
void	ft_push_swap_v5(t_push_swap *push_swap)
{
	t_instructions	*instructions;
	int				range;
	
	range = ft_stack_size(push_swap->a) / 7;
	instructions = ft_move_to_b_v5(push_swap, range);
	ft_move_to_a_v5(push_swap, instructions);
	print_instructions(instructions);
	ft_free_instructions(instructions);
}