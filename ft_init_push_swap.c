/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_push_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:06:01 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/05/31 20:06:44 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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