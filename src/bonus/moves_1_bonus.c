/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:30:06 by upolat            #+#    #+#             */
/*   Updated: 2024/06/18 01:55:10 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	move_sa(t_stack *t, int print_flag)
{
	int	temp;

	if (t->height_a > 1)
	{
		if (print_flag == 1)
			ft_printf("sa\n");
		temp = t->stack_a[t->argc - t->height_a - 1];
		t->stack_a[t->argc - t->height_a - 1]
			= t->stack_a[t->argc - t->height_a];
		t->stack_a[t->argc - t->height_a] = temp;
		return (1);
	}
	else
		return (0);
}

int	move_sb(t_stack *t, int print_flag)
{
	int	temp;

	if (t->height_b > 1)
	{
		if (print_flag == 1)
			ft_printf("sb\n");
		temp = t->stack_b[t->argc - t->height_b - 1];
		t->stack_b[t->argc - t->height_b - 1]
			= t->stack_b[t->argc - t->height_b];
		t->stack_b[t->argc - t->height_b] = temp;
		return (1);
	}
	else
		return (0);
}

int	move_ss(t_stack *t, int print_flag)
{
	if (move_sa(t, print_flag) + move_sb(t, print_flag) != 3)
		return (0);
	else
	{
		if (print_flag == 1)
			ft_printf("ss\n");
		return (1);
	}
}

int	move_pa(t_stack *t, int print_flag)
{
	if (t->height_b > 0)
	{
		if (print_flag == 1)
			ft_printf("pa\n");
		t->stack_a[t->argc - t->height_a - 2]
			= t->stack_b[t->argc - t->height_b - 1];
		t->height_b--;
		t->height_a++;
		return (4);
	}
	return (-4);
}

int	move_pb(t_stack *t, int print_flag)
{
	if (t->height_a > 0)
	{
		if (print_flag == 1)
			ft_printf("pb\n");
		t->stack_b[t->argc - t->height_b - 2]
			= t->stack_a[t->argc - t->height_a - 1];
		t->height_a--;
		t->height_b++;
		return (5);
	}
	return (-5);
}
