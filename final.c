/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhayri <ykhayri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:26:40 by ykhayri           #+#    #+#             */
/*   Updated: 2023/03/02 17:50:45 by ykhayri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	count_check(char *str, int *sum)
{
	char	**arr;
	int		i;
	long	k;

	i = -1;
	if (!str[0])
		return (0);
	arr = ft_split(str, ' ');
	while (arr[++i])
	{
		*sum += 1;
		k = ft_atoi(arr[i]);
		if (k > INT_MAX || k < INT_MIN)
			return (0);
		free(arr[i]);
	}
	free (arr);
	return (1);
}

int	check1(int ac, char **av, int *s)
{
	int		i;
	char	*tmp;

	i = 0;
	while (++i < ac)
	{
		tmp = ft_strdup(av[i]);
		if (!count_check(tmp, s))
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}

int	format_arr(t_info *data, int s)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < s)
	{
		j = i + 1;
		while (j < s)
		{
			if (data->arr[i] == data->arr[j])
				return (0);
			if (data->arr_sort[i] > data->arr_sort[j])
			{
				k = data->arr_sort[i];
				data->arr_sort[i] = data->arr_sort[j];
				data->arr_sort[j] = k;
			}
			j++;
		}
		ft_lstiter(data->s_a, data->arr_sort[i], i);
	}
	return (1);
}

int	fill_arr(char **av, t_info *data, int ac, int s)
{
	int		i[3];
	char	**tmp;

	i[0] = 0;
	i[2] = 0;
	data->arr_sort = malloc(s * sizeof(int));
	if (!data->arr_sort)
		return (0);
	while (++i[0] < ac)
	{
		i[1] = -1;
		tmp = ft_split(ft_strdup(av[i[0]]), ' ');
		if (!tmp[0])
			return (0);
		if (!loop_over(tmp, data, i))
			return (0);
		free(tmp);
	}
	return (format_arr(data, s));
}

int	main(int ac, char **av)
{
	t_info	data;

	data.s = 0;
	if (ac > 1)
	{
		if (!check1(ac, av, &data.s))
			return (2);
		data.arr = malloc(data.s * sizeof(int));
		if (!data.arr || !fill_arr(av, &data, ac, data.s))
		{
			if (data.arr)
			{
				ft_lstclear(&data.s_a);
				free(data.arr);
			}
			if (data.arr_sort)
				free(data.arr_sort);
			write(2, "Error\n", 6);
			return (2);
		}
		if (!output_it(&data))
			return (2);
	}
	return (0);
}
