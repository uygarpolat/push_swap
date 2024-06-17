/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:34:31 by upolat            #+#    #+#             */
/*   Updated: 2024/06/18 00:36:01 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_index(t_stack *t)
{
	int	i;
	int	min;
	int	top_of_b;
	int	index;

	i = 0;
	top_of_b = t->argc - t->height_b - 1;
	min = t->stack_b[top_of_b];
	index = 0;
	while (i < t->height_b)
	{
		if (t->stack_b[top_of_b + i] < min)
		{
			min = t->stack_b[top_of_b + i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	get_max_index(t_stack *t)
{
	int	i;
	int	max;
	int	top_of_b;
	int	index;

	i = 0;
	top_of_b = t->argc - t->height_b - 1;
	max = t->stack_b[top_of_b];
	index = 0;
	while (i < t->height_b)
	{
		if (t->stack_b[top_of_b + i] > max)
		{
			max = t->stack_b[top_of_b + i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	max_finder(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	min_finder(int a, int b, int c, int d)
{
	int	i;
	int	arr[4];
	int	min;

	i = 0;
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	arr[3] = d;
	min = arr[0];
	while (i < 4)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}
