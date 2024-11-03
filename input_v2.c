/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_v2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:04:49 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/11/03 02:10:04 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_strlst	*ft_read_imput(int narg, char **argv)
{
	t_strlst	*input;
	int			i;
	int			j;
	char		**arg;

	i = 1;
	input = 0;
	while (i < narg)
	{
		j = 0;
		arg = ft_split(argv[i], ' ');
		while (arg[j])
		{
			input = ft_strlst_add_new(arg[j], input);
			j++;
		}
		i++;
		free(arg);
	}
	return (input);
}

int	ft_check_input(t_strlst *input)
{
	t_strlst	*tmp;
	int			i;

	if (!input)
		return (0);
	tmp = input;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i])
		{
			if (tmp->content[i] != '-' && tmp->content[i] != '+'
				&& !ft_isdigit(tmp->content[i]) && tmp->content[i] != 0)
				return (0);
			i++;
			while (tmp->content[i] != '\0')
			{
				if (!ft_isdigit(tmp->content[i++]))
					return (0);
			}
		}
		tmp = tmp->next;
	}
	return (1);
}
