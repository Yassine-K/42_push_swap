/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:48:03 by ykhayri           #+#    #+#             */
/*   Updated: 2023/02/24 19:19:07 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	start_sort(t_info *d)
{
	if (d->s == 2 && d->s_a->val > d->s_a->next->val)
		r_move(d, 'a', "ra\n");
	else if (d->s == 3 && !is_sorted(d->arr, d->s))
		fix_three(d);
	else if (d->s < 11 && !is_sorted(d->arr, d->s))
		fix_ten(d);
	else if (d->s < 101 && !is_sorted(d->arr, d->s))
		fix_ten_sq(d, 15);
	else if (d->s < 501 && !is_sorted(d->arr, d->s))
		fix_ten_sq(d, 35);
	else if (!is_sorted(d->arr, d->s))
		fix_ten_sq(d, 45);
}

int	is_valid(char *s, t_info *d)
{
	if (!ft_strncmp("rra\n", s, 5))
		rr_move(d, 'a', s);
	else if (!ft_strncmp("rrb\n", s, 5))
		rr_move(d, 'b', s);
	else if (!ft_strncmp("rrr\n", s, 5))
		rr_move(d, 'r', s);
	else if (!ft_strncmp("ra\n", s, 5))
		r_move(d, 'a', s);
	else if (!ft_strncmp("rb\n", s, 5))
		r_move(d, 'b', s);
	else if (!ft_strncmp("rr\n", s, 5))
		r_move(d, 'r', s);
	else if (!ft_strncmp("sa\n", s, 5))
		s_move(d, 'a', s);
	else if (!ft_strncmp("sb\n", s, 5))
		s_move(d, 'b', s);
	else if (!ft_strncmp("ss\n", s, 5))
		s_move(d, 's', s);
	else if (!ft_strncmp("pa\n", s, 5))
		p_move(d, 'a');
	else if (!ft_strncmp("pb\n", s, 5))
		p_move(d, 'b');
	else
		return (0);
	return (1);
}

int	node_sort(t_list *tmp)
{
	while (tmp->next)
	{
		if (tmp->index > tmp->next->index)
			break ;
		tmp = tmp->next;
	}
	if (tmp->next)
		return (0);
	return (1);
}

int	start_comm(t_info *d)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (!is_valid(str, d))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		free (str);
	}
	if (d->s_b || !node_sort(d->s_a))
	{
		write(2, "KO\n", 3);
		return (0);
	}
	write(2, "OK\n", 3);
	return (1);
}

int	output_it(t_info *d)
{
	int	i;

	i = 1;
	if (d->s > 1 && M)
		start_sort(d);
	if (!M)
		if (!start_comm(d))
			i--;
	if (d->s_a)
		ft_lstclear(&d->s_a);
	if (d->s_b)
		ft_lstclear(&d->s_b);
	free(d->arr);
	free(d->arr_sort);
	if (!i)
		return (0);
	return (1);
}
