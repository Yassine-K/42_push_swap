/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:27:31 by ykhayri           #+#    #+#             */
/*   Updated: 2023/03/02 17:49:26 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "Libft/libft.h"
# include "getNext/get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_info
{
	t_list	*s_a;
	t_list	*s_b;
	int		*arr_sort;
	int		*arr;
	int		s;
}				t_info;

void	ft_nodeadd_back(t_list **lst, int val, int ind);
void	s_move(t_info *data, char c, char *s);
void	p_move(t_info *data, char c);
void	r_move(t_info *data, char c, char *s);
void	rr_move(t_info *data, char c, char *s);
void	ft_close_list(t_list *lst, int v);
void	start_sort(t_info *data);
int		is_sorted(int *arr, int lim);
void	ft_swap(int *a, int *b);
void	ft_print(char *s, int mode, char c);
void	fix_three(t_info *d);
void	fix_ten(t_info *d);
void	fix_ten_sq(t_info *d, int r);
int		output_it(t_info *d);
int		loop_over(char **tmp, t_info *data, int i[3]);

#endif
