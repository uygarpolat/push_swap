/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:46:10 by upolat            #+#    #+#             */
/*   Updated: 2024/06/18 01:53:57 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	execute_group_1(t_stack *t, t_costs *c, int print_flag)
{
	if (c->cost_ra < c->cost_rb)
	{
		c->execute_rr = c->cost_ra;
		c->execute_rb = c->cost_rb - c->cost_ra;
		c->execute_ra = c->cost_ra - c->cost_ra;
	}
	else if (c->cost_ra > c->cost_rb)
	{
		c->execute_rr = c->cost_rb;
		c->execute_rb = c->cost_rb - c->cost_rb;
		c->execute_ra = c->cost_ra - c->cost_rb;
	}
	else
	{
		c->execute_rr = c->cost_ra;
		c->execute_rb = c->cost_rb - c->cost_rb;
		c->execute_ra = c->cost_ra - c->cost_ra;
	}
	while (c->execute_rb--)
		move_rb(t, print_flag);
	while (c->execute_ra--)
		move_ra(t, print_flag);
	while (c->execute_rr--)
		move_rr(t, print_flag);
}

void	execute_group_2(t_stack *t, t_costs *c, int print_flag)
{
	if (c->cost_rra < c->cost_rrb)
	{
		c->execute_rrr = c->cost_rra;
		c->execute_rrb = c->cost_rrb - c->cost_rra;
		c->execute_rra = c->cost_rra - c->cost_rra;
	}
	else if (c->cost_rra > c->cost_rrb)
	{
		c->execute_rrr = c->cost_rrb;
		c->execute_rrb = c->cost_rrb - c->cost_rrb;
		c->execute_rra = c->cost_rra - c->cost_rrb;
	}
	else
	{
		c->execute_rrr = c->cost_rra;
		c->execute_rrb = c->cost_rrb - c->cost_rrb;
		c->execute_rra = c->cost_rra - c->cost_rra;
	}
	while (c->execute_rrb--)
		move_rrb(t, print_flag);
	while (c->execute_rra--)
		move_rra(t, print_flag);
	while (c->execute_rrr--)
		move_rrr(t, print_flag);
}

void	execute_group_3(t_stack *t, t_costs *c, int print_flag)
{
	c->execute_ra = c->cost_ra;
	c->execute_rrb = c->cost_rrb;
	while (c->execute_rrb--)
		move_rrb(t, print_flag);
	while (c->execute_ra--)
		move_ra(t, print_flag);
}

void	execute_group_4(t_stack *t, t_costs *c, int print_flag)
{
	c->execute_rb = c->cost_rb;
	c->execute_rra = c->cost_rra;
	while (c->execute_rb--)
		move_rb(t, print_flag);
	while (c->execute_rra--)
		move_rra(t, print_flag);
}
