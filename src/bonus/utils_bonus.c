/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:42:22 by upolat            #+#    #+#             */
/*   Updated: 2024/06/18 01:56:18 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_2d_array(void ***arr)
{
	int	i;

	i = 0;
	if (arr == NULL || *arr == NULL)
		return ;
	while ((*arr)[i])
	{
		free((*arr)[i]);
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}

void	print_stacks(t_stack *t)
{
	int	i;

	i = 0;
	ft_printf("Stack A is: ");
	while (i < t->argc - t->height_a - 1)
	{
		ft_printf("_ ");
		i++;
	}
	while (i < t->argc - 1)
		ft_printf("%d ", t->stack_a[i++]);
	ft_printf("\n");
	i = 0;
	ft_printf("Stack B is: ");
	while (i < t->argc - t->height_b - 1)
	{
		ft_printf("_ ");
		i++;
	}
	while (i < t->argc - 1)
		ft_printf("%d ", t->stack_b[i++]);
	ft_printf("\n");
}

void	free_stacks(t_stack *t)
{
	if (t->stack_a)
	{
		free(t->stack_a);
		t->stack_a = NULL;
	}
	if (t->stack_b)
	{
		free(t->stack_b);
		t->stack_b = NULL;
	}
}

int	index_of_insertion_in_b(t_stack *t, int index)
{
	int	i;
	int	target;
	int	top_of_b;
	int	min_index_of_b;
	int	max_index_of_b;

	target = t->stack_a[t->argc - t->height_a - 1 + index];
	top_of_b = t->argc - t->height_b - 1;
	min_index_of_b = get_min_index(t);
	max_index_of_b = get_max_index(t);
	if (target < t->stack_b[top_of_b + min_index_of_b])
		return ((min_index_of_b + 1) % t->height_b);
	else if (target > t->stack_b[top_of_b + max_index_of_b])
		return ((max_index_of_b) % t->height_b);
	i = 0;
	while (i < t->height_b - 1)
	{
		if ((t->stack_b[top_of_b + i] > target)
			&& (t->stack_b[top_of_b + i + 1] < target))
			return (i + 1);
		i++;
	}
	return (0);
}

int	is_two_or_three_pseudo_sorted_ascending(t_stack *t, int i, int flag)
{
	int	j;

	while (i < t->height_a)
	{
		j = 0;
		while (j < t->height_a - 1)
		{
			if (t->stack_a[t->argc - t->height_a - 1 + j]
				< t->stack_a[t->argc - t->height_a - 1 + j + 1])
				flag++;
			j++;
		}
		if (flag == t->height_a - 1)
		{
			while (i++ < t->height_a)
				move_ra(t, 0);
			return (1);
		}
		flag = 0;
		move_ra(t, 0);
		i++;
	}
	return (0);
}
