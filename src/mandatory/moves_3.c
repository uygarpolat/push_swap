/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:36:32 by upolat            #+#    #+#             */
/*   Updated: 2024/06/15 18:37:14 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_rra(t_stack *t, int print_flag)
{
	int	temp;
	int	i;

	if (t->height_a > 0)
	{
		if (print_flag == 1)
			ft_printf("rra\n");
		temp = t->stack_a[t->argc - 2];
		i = 0;
		while (i < t->height_a - 1)
		{
			t->stack_a[t->argc - 2 - i] = t->stack_a[t->argc - 3 - i];
			i++;
		}
		t->stack_a[t->argc - 2 - i] = temp;
		return (8);
	}
	return (-8);
}

int	move_rrb(t_stack *t, int print_flag)
{
	int	temp;
	int	i;

	if (t->height_b > 0)
	{
		if (print_flag == 1)
			ft_printf("rrb\n");
		temp = t->stack_b[t->argc - 2];
		i = 0;
		while (i < t->height_b - 1)
		{
			t->stack_b[t->argc - 2 - i] = t->stack_b[t->argc - 3 - i];
			i++;
		}
		t->stack_b[t->argc - 2 - i] = temp;
		return (9);
	}
	return (-9);
}

int	move_rrr(t_stack *t, int print_flag)
{
	if (move_rra(t, print_flag) + move_rrb(t, print_flag) != 17)
		return (-17);
	else
	{
		if (print_flag == 1)
			ft_printf("(meaning rrr)\n");
		return (17);
	}
}
