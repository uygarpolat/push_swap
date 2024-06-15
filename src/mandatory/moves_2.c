/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:33:12 by upolat            #+#    #+#             */
/*   Updated: 2024/06/15 18:41:33 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_ra(t_stack *t, int print_flag)
{
	int	temp;
	int	i;

	if (t->height_a > 0)
	{
		if (print_flag == 1)
			ft_printf("ra\n");
		temp = t->stack_a[t->argc - t->height_a - 1];
		i = 0;
		while (i < t->height_a - 1)
		{
			t->stack_a[t->argc - t->height_a - 1 + i]
				= t->stack_a[t->argc - t->height_a + i];
			i++;
		}
		t->stack_a[t->argc - t->height_a - 1 + i] = temp;
		return (6);
	}
	return (-6);
}

int	move_rb(t_stack *t, int print_flag)
{
	int	temp;
	int	i;

	if (t->height_b > 0)
	{
		if (print_flag == 1)
			ft_printf("rb\n");
		temp = t->stack_b[t->argc - t->height_b - 1];
		i = 0;
		while (i < t->height_b - 1)
		{
			t->stack_b[t->argc - t->height_b - 1 + i]
				= t->stack_b[t->argc - t->height_b + i];
			i++;
		}
		t->stack_b[t->argc - t->height_b - 1 + i] = temp;
		return (7);
	}
	return (-7);
}

int	move_rr(t_stack *t, int print_flag)
{
	if (move_ra(t, print_flag) + move_rb(t, print_flag) != 13)
		return (-13);
	else
	{
		if (print_flag == 1)
			ft_printf("(meaning rr)\n");
		return (13);
	}
}
