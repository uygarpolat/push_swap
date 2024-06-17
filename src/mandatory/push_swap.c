/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:11:59 by upolat            #+#    #+#             */
/*   Updated: 2024/06/17 16:58:43 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	reset_stack_c(t_costs *c)
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

void	choose_execution(t_stack *t, t_costs *c, int print_flag)
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
			c.cost_ra = i; // 0
			c.cost_rra = t->height_a - i; // 5
			c.cost_rb = index_of_insertion_in_b(t, i); // 2
			c.cost_rrb = t->height_b - index_of_insertion_in_b(t, i); // 2
		}
		i++;
	}
/*	ft_printf("Best numbers that won is among these:\n");
	ft_printf("The number chosen to be pushed from A to B is: %d\n", t->stack_a[t->argc - t->height_a - 1 + c.cost_ra]); // c.cost_ra is used because it is always set to "i".
	ft_printf("least number of moves: %d\n", c.min_cost);
	ft_printf("c.cost_ra: %d\n", c.cost_ra);
	ft_printf("c.cost_rra: %d\n", c.cost_rra);
	ft_printf("c.cost_rb: %d\n", c.cost_rb);
	ft_printf("c.cost_rrb: %d\n", c.cost_rrb);*/
	choose_execution(t, &c, print_flag);
}

int	is_two_or_three_pseudo_sorted_ascending(t_stack *t)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	flag = 0;
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
			while (i < t->height_a)
			{
				move_ra(t, 0);
				i++;
			}
			return (1);
		}
		flag = 0;
		move_ra(t, 0);
		i++;
	}
	return (0);
}

int	is_fully_sorted_ascending(t_stack *t)
{
	int	i;
	int	index_of_top_a;

	index_of_top_a = t->argc - t->height_a - 1;
	i = 0;
	while (i < t->height_a - 1)
	{
		if (t->stack_a[index_of_top_a + i] > t->stack_a[index_of_top_a + i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_two_or_three_ascending(t_stack *t, int print_flag)
{
	if (!is_two_or_three_pseudo_sorted_ascending(t))
		move_sa(t, print_flag);
	if (t->height_a == 2)
		return ;
	if (!is_fully_sorted_ascending(t))
	{
		if (t->stack_a[t->argc - t->height_a - 1]
			> t->stack_a[t->argc - t->height_a - 1 + 1])
			move_ra(t, print_flag);
		else
			move_rra(t, print_flag);
	}
}

int	is_reverse_sorted(t_stack *t, int *stack, int height)
{
	int	i;
	int	counter;
	int	flag;

	flag = 0;
	counter = 0;
	i = 0;
	if (height < 3)
		return (1);
	while (i < height - 1)
	{
		if (stack[t->argc - height - 1 + i]
			< stack[t->argc - height - 1 + i + 1])
		{
			counter++;
			flag = i + 1;
		}
		i++;
	}
	if (stack[t->argc - 2] < stack[t->argc - height - 1])
	{
		counter++;
		flag = 0;
	}
	if (counter < 2)
		return (flag);
	else
		return (-1);
}

void	reverse_sort_b(t_stack *t, int print_flag)
{
	int	i;
	int	top_index;
	int	index;
	int	max;

	max = t->stack_b[t->argc - t->height_b - 1];
	top_index = t->argc - t->height_b - 1;
	index = 0;
	i = 0;
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

void	final_push_to_a(t_stack *t, int print_flag)
{
	int	i;
	int	flag;
	int	iteration;

	i = 0;
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
	while (flag-- > 0) // THIS IS ABSOLUTELY SPECULATIVE; FULLY UNDERSTAND THE EDGE CASES!
		move_rra(t, print_flag);
}

void	sorter(t_stack *t, int print_flag)
{
	int	i;

	i = 0;
	while (i < t->argc - 1 - 2)
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
			reverse_sort_b(t, print_flag);
			final_push_to_a(t, print_flag);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	t;

	if (check_error(argc, argv, &t) < 0)
		return (ft_putstr_fd("Error\n", 2), 0);
	if (is_fully_sorted_ascending(&t))
		return (0);
	if (t.height_a < 4)
	{
		sort_two_or_three_ascending(&t, 1);
		return (0);
	}
	sorter(&t, 1);
	//print_stacks(&t);
	free_stacks(&t);
	return (0);
}
