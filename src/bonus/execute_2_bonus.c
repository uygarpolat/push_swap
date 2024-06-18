/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:53:16 by upolat            #+#    #+#             */
/*   Updated: 2024/06/18 01:54:18 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	reset_stack_c(t_costs *c)
{
	c->cost_ra = 0;
	c->cost_rra = 0;
	c->cost_rb = 0;
	c->cost_rrb = 0;
	c->execute_ra = 0;
	c->execute_rb = 0;
	c->execute_rr = 0;
	c->execute_rra = 0;
	c->execute_rrb = 0;
	c->execute_rrr = 0;
	c->min_cost = INT_MAX;
}

static void	choose_execution(t_stack *t, t_costs *c, int print_flag)
{
	int	min;

	min = min_finder(max_finder(c->cost_ra, c->cost_rb),
			max_finder(c->cost_rra, c->cost_rrb), c->cost_ra + c->cost_rrb,
			c->cost_rb + c->cost_rra);
	if (min == max_finder(c->cost_ra, c->cost_rb))
		execute_group_1(t, c, print_flag);
	else if (min == max_finder(c->cost_rra, c->cost_rrb))
		execute_group_2(t, c, print_flag);
	else if (min == c->cost_ra + c->cost_rrb)
		execute_group_3(t, c, print_flag);
	else if (min == c->cost_rra + c->cost_rb)
		execute_group_4(t, c, print_flag);
	reset_stack_c(c);
}

void	calculate_and_execute(t_stack *t, int print_flag)
{
	int		i;
	t_costs	c;
	int		best;

	reset_stack_c(&c);
	best = 0;
	i = 0;
	while (i < t->height_a)
	{
		best = min_finder(max_finder(i, index_of_insertion_in_b(t, i)),
				max_finder(t->height_a - i,
					t->height_b - index_of_insertion_in_b(t, i)),
				i + t->height_b - index_of_insertion_in_b(t, i),
				index_of_insertion_in_b(t, i) + t->height_a - i);
		if (best < c.min_cost)
		{
			c.min_cost = best;
			c.cost_ra = i;
			c.cost_rra = t->height_a - i;
			c.cost_rb = index_of_insertion_in_b(t, i);
			c.cost_rrb = t->height_b - index_of_insertion_in_b(t, i);
		}
		i++;
	}
	choose_execution(t, &c, print_flag);
}
