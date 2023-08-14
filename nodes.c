/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 23:29:01 by ykhayri           #+#    #+#             */
/*   Updated: 2023/02/24 19:02:41 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_nodeadd_back(t_list **lst, int val, int ind)
{
	t_list	*new;

	new = ft_lstnew(val, ind);
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)-> next = new;
}

void	ft_close_list(t_list *lst, int v)
{
	while (lst)
	{
		if (lst->next->val == v)
		{
			free(lst->next);
			lst->next = NULL;
		}
		lst = lst->next;
	}
}

void	fix_three(t_info *d)
{
	if (d->s_a->val < d->s_a->next->val && d->s_a->next->val
		> d->s_a->next->next->val && d->s_a->next->next->val > d->s_a->val)
		rr_move(d, 'a', "rra\n");
	if (d->s_a->val > d->s_a->next->val && d->s_a->next->val
		> d->s_a->next->next->val && d->s_a->next->next->val < d->s_a->val)
		s_move(d, 'a', "sa\n");
	if (d->s_a->val < d->s_a->next->val && d->s_a->next->val
		> d->s_a->next->next->val && d->s_a->next->next->val < d->s_a->val)
		rr_move(d, 'a', "rra\n");
	if (d->s_a->val > d->s_a->next->val && d->s_a->next->val
		< d->s_a->next->next->val && d->s_a->next->next->val < d->s_a->val)
		r_move(d, 'a', "ra\n");
	if (d->s_a->val > d->s_a->next->val && d->s_a->next->val
		< d->s_a->next->next->val && d->s_a->next->next->val > d->s_a->val)
		s_move(d, 'a', "sa\n");
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_print(char *s, int mode, char c)
{
	if (mode && s[ft_strlen(s) - 2] == c)
		write(1, s, ft_strlen(s));
}
