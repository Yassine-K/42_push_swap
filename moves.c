/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:50:53 by ykhayri           #+#    #+#             */
/*   Updated: 2023/02/24 19:01:39 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	s_move(t_info *data, char c, char *s)
{
	if (c == 'a' && data->s_a && data->s_a->next)
	{
		ft_swap(&data->s_a->val, &data->s_a->next->val);
		ft_swap(&data->s_a->index, &data->s_a->next->index);
		ft_print(s, M, c);
	}
	else if (c == 'b' && data->s_b && data->s_b->next)
	{
		ft_swap(&data->s_b->val, &data->s_b->next->val);
		ft_swap(&data->s_b->index, &data->s_b->next->index);
		ft_print(s, M, c);
	}
	else if (c == 's')
	{
		s_move(data, 'a', s);
		s_move(data, 'b', s);
		ft_print(s, M, c);
	}
}

void	p_move(t_info *data, char c)
{
	t_list	*tmp;

	if (c == 'a' && data->s_b)
	{
		tmp = data->s_b;
		data->s_b = data->s_b->next;
		ft_lstadd_front(&data->s_a, tmp);
		ft_print("pa\n", M, c);
	}
	else if (c == 'b' && data->s_a)
	{
		tmp = data->s_a;
		data->s_a = data->s_a->next;
		ft_lstadd_front(&data->s_b, tmp);
		ft_print("pb\n", M, c);
	}
}

void	apply_all(t_info *data, char c, char *s)
{
	if (c == 'r')
	{
		if (ft_strlen(s) == 3)
		{
			r_move(data, 'a', s);
			r_move(data, 'b', s);
			ft_print(s, M, c);
		}
		if (ft_strlen(s) == 4)
		{
			rr_move(data, 'a', s);
			rr_move(data, 'b', s);
			ft_print(s, M, c);
		}
	}
}

void	r_move(t_info *data, char c, char *s)
{
	t_list	*tmp;

	if (c == 'a' && data->s_a && data->s_a->next)
	{
		tmp = data->s_a;
		ft_nodeadd_back(&data->s_a, data->s_a->val,
			data->s_a->index);
		data->s_a = data->s_a->next;
		free(tmp);
		ft_print(s, M, c);
	}
	else if (c == 'b' && data->s_b && data->s_b->next)
	{
		tmp = data->s_b;
		ft_nodeadd_back(&data->s_b, data->s_b->val,
			data->s_b->index);
		data->s_b = data->s_b->next;
		free(tmp);
		ft_print(s, M, c);
	}
	else if (c == 'r')
		apply_all(data, c, s);
}

void	rr_move(t_info *data, char c, char *s)
{
	t_list	*tmp;

	if (c == 'a' && data->s_a && data->s_a->next)
	{
		tmp = ft_lstnew(ft_lstlast(data->s_a)->val,
				ft_lstlast(data->s_a)->index);
		ft_lstadd_front(&data->s_a, tmp);
		ft_close_list(data->s_a->next, tmp->val);
		free(ft_lstlast(data->s_a)->next);
		ft_print(s, M, c);
	}
	else if (c == 'b' && data->s_b && data->s_b->next)
	{
		tmp = ft_lstnew(ft_lstlast(data->s_b)->val,
				ft_lstlast(data->s_b)->index);
		ft_lstadd_front(&data->s_b, tmp);
		ft_close_list(data->s_b->next, tmp->val);
		free(ft_lstlast(data->s_b)->next);
		ft_print(s, M, c);
	}
	else if (c == 'r')
		apply_all(data, c, s);
}
