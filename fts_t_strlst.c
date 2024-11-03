/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_strlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ide-dieg <ide-dieg@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:07:47 by ide-dieg          #+#    #+#             */
/*   Updated: 2024/11/03 02:10:54 by ide-dieg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlst_size(t_strlst *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_strlst	*ft_strlst_last(t_strlst *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_strlst	*ft_strlst_add_new(char *content, t_strlst *lst)
{
	t_strlst	*new;

	new = (t_strlst *)malloc(sizeof(t_strlst));
	if (!new)
	{
		ft_strlst_clear(lst);
		return (0);
	}
	if (!lst)
	{
		new->content = content;
		new->next = 0;
		return (new);
	}
	new->content = content;
	new->next = 0;
	ft_strlst_last(lst)->next = new;
	return (lst);
}

void	ft_strlst_clear(t_strlst *lst)
{
	t_strlst	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
}

void	print_strlst(t_strlst *lst)
{
	while (lst)
	{
		printf("%s\n", lst->content);
		lst = lst->next;
	}
}
