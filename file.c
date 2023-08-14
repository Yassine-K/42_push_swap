/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:44:50 by ykhayri           #+#    #+#             */
/*   Updated: 2023/03/02 17:51:40 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	loop_over(char **tmp, t_info *data, int i[3])
{
	while (tmp[++i[1]])
	{
		if (ft_strlen(tmp[i[1]]) > 11)
			return (0);
		data->arr[i[2]] = (int) ft_atoi(tmp[i[1]]);
		ft_nodeadd_back(&data->s_a, data->arr[i[2]], 0);
		data->arr_sort[i[2]] = data->arr[i[2]];
		free(tmp[i[1]]);
		i[2]++;
	}
	return (1);
}
