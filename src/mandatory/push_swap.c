/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:11:59 by upolat            #+#    #+#             */
/*   Updated: 2024/06/16 01:40:31 by upolat           ###   ########.fr       */
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

int	index_of_insertion_in_b(t_stack *t)
{
	int	i;

	i = 0;
	while (i < t->height_b - 1)
	{
		if ((t->stack_b[t->argc - t->height_b - 1 + i] > t->stack_a[t->argc - t->height_a - 1]) && (t->stack_b[t->argc - t->height_b - 1 + i + 1] < t->stack_a[t->argc - t->height_a - 1]))
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
	int arr[4];
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

void	execute_moves(t_stack *t, t_costs *c, int print_flag)
{
	(void)t;
	(void)c;
	(void)print_flag;
}

void calculate_and_execute(t_stack *t, int print_flag)
{
	int		i;
	t_costs	c;
	int		min_cost ;

	min_cost = INT_MAX;
	i = 0;
	while (i < t->height_a)
	{
		if (min_finder(max_finder(i, index_of_insertion_in_b(t)), max_finder(t->height_a - i, t->height_b - index_of_insertion_in_b(t)), i + t->height_b - index_of_insertion_in_b(t),
					index_of_insertion_in_b(t) + t->height_a - i) < min_cost)
			min_cost = min_finder(max_finder(i, index_of_insertion_in_b(t)), max_finder(t->height_a - i, t->height_b - index_of_insertion_in_b(t)), i + t->height_b - index_of_insertion_in_b(t),
					index_of_insertion_in_b(t) + t->height_a - i);
			c.cost_ra = i; // 0
			c.cost_rra = t->height_a - i; // 5
			c.cost_rb = index_of_insertion_in_b(t); // 2
			c.cost_rrb = t->height_b - index_of_insertion_in_b(t); // 2
			// Compare these:
			// 1) maximum of ra and rb
			// 2) maximum of rra and rrb
			// 3) ra + rrb
			// 4) rb + rra
		i++;
	}
	execute_moves(t, &c, print_flag);
}

void sorter(t_stack *t, int print_flag)
{
	int	i;

	i = 0;
	while (i < t->argc - 1 - 3)
	{
		if (i < 2)
			move_pb(t, print_flag);
		else
			calculate_and_execute(t, print_flag);
		i++;
	}
}
/*
/
// Stack B: - - - - - 1 7 5 2
// Stack A: - - - - 6 3 9 4 8

4 3 11 8 6 5
insert 7


For 6:
cost_sa = 2
*/

int	main(int argc, char **argv)
{
	t_stack	t;

	if (check_error(argc, argv, &t) < 0)
		return (ft_putstr_fd("Error\n", 2), 0);
	//sorter(&t, 0);
	int i = 7;
	move_pb(&t, 0);
	move_pb(&t, 0);
	while (i--)
	{
		ft_printf("----------------------\n");
		print_stacks(&t);
		ft_printf("insertion index in stack B is: %d\n", index_of_insertion_in_b(&t));
		move_pb(&t, 0);
		ft_printf("----------------------\n");
	}
	free_stacks(&t);
	return (0);
}
