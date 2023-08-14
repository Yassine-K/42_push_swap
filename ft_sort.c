/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:19:29 by ykhayri           #+#    #+#             */
/*   Updated: 2023/02/24 19:04:59 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_sorted(int *arr, int lim)
{
	int	i;

	i = -1;
	while (++i < lim)
	{
		if (i + 1 < lim && arr[i] > arr[i + 1])
			return (0);
	}
	return (1);
}

int	ft_index_of(t_list **head, int index)
{
	t_list	*tmp;
	int		i;

	tmp = *head;
	i = 0;
	while (tmp && tmp->index != index)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	fix_ten(t_info *d)
{
	int	i;

	i = 0;
	while (ft_lstsize(d->s_a) > 2)
	{
		while (d->s_a->index != i)
		{
			if (ft_index_of(&d->s_a, i) >= (ft_lstsize(d->s_a)) / 2)
				rr_move(d, 'a', "rra\n");
			else
				r_move(d, 'a', "ra\n");
		}
		p_move(d, 'b');
		i++;
	}
	fix_three(d);
	while (d->s_b)
		p_move(d, 'a');
}

void	clear_b(t_info *d)
{
	int	i;

	i = ft_lstsize(d->s_b);
	while (d->s_b)
	{
		while (d->s_b->index != i)
		{
			if (ft_index_of(&d->s_b, i) >= i / 2)
				rr_move(d, 'b', "rrb\n");
			else
				r_move(d, 'b', "rb\n");
		}
		p_move(d, 'a');
		i--;
	}
}

void	fix_ten_sq(t_info *d, int r)
{
	int	i;

	i = 0;
	while (d->s_a)
	{
		if (d->s_a->index <= i)
		{
			p_move(d, 'b');
			r_move(d, 'b', "rb\n");
			i++;
		}
		else if (d->s_a->index <= i + r)
		{
			p_move(d, 'b');
			i++;
		}
		else
			r_move(d, 'a', "ra\n");
	}
	clear_b(d);
}
