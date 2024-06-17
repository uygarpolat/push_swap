/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 00:03:41 by upolat            #+#    #+#             */
/*   Updated: 2024/06/18 00:17:30 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_fully_sorted_ascending(t_stack *t, int print_flag)
{
	int	i;
	int	index_of_top_a;

	index_of_top_a = t->argc - t->height_a - 1;
	i = 0;
	while (i < t->height_a - 1)
	{
		if (t->stack_a[index_of_top_a + i] > t->stack_a[index_of_top_a + i + 1])
		{
			if (t->height_a == 2)
			{
				move_sa(t, print_flag);
				return (1);
			}
			else
				return (0);
		}
		i++;
	}
	return (1);
}

void	sort_two_or_three_ascending(t_stack *t, int print_flag)
{
	if (t->height_a == 2)
	{
		is_fully_sorted_ascending(t, print_flag);
		return ;
	}
	if (!is_two_or_three_pseudo_sorted_ascending(t, 0, 0))
		move_sa(t, print_flag);
	if (!is_fully_sorted_ascending(t, print_flag))
	{
		if (t->stack_a[t->argc - t->height_a - 1]
			> t->stack_a[t->argc - t->height_a - 1 + 1])
			move_ra(t, print_flag);
		else
			move_rra(t, print_flag);
	}
}

static void	reverse_sort_b(t_stack *t, int print_flag, int i, int index)
{
	int	top_index;
	int	max;

	max = t->stack_b[t->argc - t->height_b - 1];
	top_index = t->argc - t->height_b - 1;
	while (i < t->height_b)
	{
		if (t->stack_b[top_index + i] > max)
		{
			max = t->stack_b[top_index + i];
			index = i;
		}
		i++;
	}
	if (index < t->height_b / 2)
	{
		while (index--)
			move_rb(t, print_flag);
	}
	else
	{
		index = t->height_b - index;
		while (index--)
			move_rrb(t, print_flag);
	}
}

static void	final_push_to_a(t_stack *t, int print_flag, int i)
{
	int	flag;
	int	iteration;

	if (t->argc == 5)
		flag = 1;
	else
		flag = 0;
	iteration = t->height_b;
	while (i < iteration)
	{
		if (t->stack_b[t->argc - t->height_b - 1]
			< t->stack_a[t->argc - 2] && flag < 3)
		{
			move_rra(t, print_flag);
			flag++;
		}
		else
		{
			move_pa(t, print_flag);
			i++;
		}
	}
	flag = 3 - flag;
	while (flag-- > 0)
		move_rra(t, print_flag);
}

void	sorter(t_stack *t, int print_flag)
{
	int	i;

	i = 0;
	while (i < t->argc - 1 - 1)
	{
		if (t->height_b < 2)
			move_pb(t, print_flag);
		else if (t->height_a > 3)
		{
			calculate_and_execute(t, print_flag);
			move_pb(t, print_flag);
		}
		else
		{
			sort_two_or_three_ascending(t, print_flag);
			reverse_sort_b(t, print_flag, 0, 0);
			final_push_to_a(t, print_flag, 0);
			break ;
		}
		i++;
	}
}
