/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:30:24 by upolat            #+#    #+#             */
/*   Updated: 2024/06/13 18:35:06 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_sa(t_stack *t, int print_flag)
{
	int	temp;

	if (t->height_a_temp > 1)
	{
		if (print_flag == 1)
			ft_printf("sa_temp\n");
		temp = t->stack_a_temp[t->argc - t->height_a_temp - 1];
		t->stack_a_temp[t->argc - t->height_a_temp - 1] = t->stack_a_temp[t->argc - t->height_a_temp];
		t->stack_a_temp[t->argc - t->height_a_temp] = temp;
		return (1);
	}
	else
		return (-1);
}

int	move_sb_temp(t_stack *t, int print_flag)
{
	int	temp;

	if (t->height_b_temp > 1)
	{
		if (print_flag == 1)
			ft_printf("sb_temp\n");
		temp = t->stack_b_temp[t->argc - t->height_b_temp - 1];
		t->stack_b_temp[t->argc - t->height_b_temp - 1] = t->stack_b_temp[t->argc - t->height_b_temp];
		t->stack_b_temp[t->argc - t->height_b_temp] = temp;
		return (2);
	}
	else
		return (-2);
}

int	move_ss(t_stack *t, int print_flag)
{
	if (move_sa(t, print_flag) + move_sb(t, print_flag) != 3)
		return(-3);
	else
	{
		if (print_flag == 1)
			ft_printf("(meaning ss)\n");
		return(3);
	}
}

int	move_pa(t_stack *t, int print_flag)
{
	if (t->height_b > 0)
	{
		if (print_flag == 1)
			ft_printf("pa\n");
		t->stack_a[t->argc - t->height_a - 2] = t->stack_b[t->argc - t->height_b - 1];
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
		t->stack_b[t->argc - t->height_b - 2] = t->stack_a[t->argc - t->height_a - 1];
		t->height_a--;
		t->height_b++;
		return (5);
	}
	return (-5);
}

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
			t->stack_a[t->argc - t->height_a - 1 + i] = t->stack_a[t->argc - t->height_a + i];
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
			t->stack_b[t->argc - t->height_b - 1 + i] = t->stack_b[t->argc - t->height_b + i];
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

int	index_of_min_stack_a(t_stack *t)
{
	int	min;
	int	i;

	if (t->height_a > 0)
	{
		min = t->argc - t->height_a - 1;
		i = 0;
		while (i < t->height_a)
		{
			if (t->stack_a[t->argc - t->height_a - 1 + i] < t->stack_a[min])
				min = t->argc - t->height_a - 1 + i;
			i++;
		}
		return (min);
	}
	return (INT_MAX);
}

void	push_min_to_top(t_stack *t, int print_flag)
{
	int	min;
	int	ra_distance;
	int	rra_distance;

	min = index_of_min_stack_a(t);
	ra_distance = min - (t->argc - 1 - t->height_a);
	rra_distance = t->argc - 2 - min + 1;
	if (ra_distance < rra_distance)
	{
		while (ra_distance--)
			move_ra(t, print_flag);
	}
	else
	{
		while(rra_distance--)
			move_rra(t, print_flag);
	}
}

void	naive_sort(t_stack *t, int print_flag)
{
	int	i;

	i = 0;
	while (i < t->argc - 1)
	{
		push_min_to_top(t, print_flag);
		t->stack_a_temp[i] = t->stack_a[t->argc - t->height_a - 1];
		t->height_a_temp++;
		move_pb(t, print_flag);
		i++;
	}
	i = 0;
	while (i < t->argc - 1)
	{
		move_pa(t, print_flag);
		i++;
	}

}
