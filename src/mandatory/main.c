/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:11:59 by upolat            #+#    #+#             */
/*   Updated: 2024/06/12 01:15:37 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		printf("%d ", t->stack_a[i++]);
	printf("\n");
	i = 0;
	ft_printf("Stack B is: ");
	while (i < t->argc - t->height_b - 1)
	{
		ft_printf("_ ");
		i++;
	}	
	while (i < t->argc - 1)
		printf("%d ", t->stack_b[i++]);
	printf("\n");

}

int	move_sa(t_stack *t)
{
	int	temp;

	if (t->height_a > 1)
	{
		temp = t->stack_a[t->argc - t->height_a - 1];
		t->stack_a[t->argc - t->height_a - 1] = t->stack_a[t->argc - t->height_a];
		t->stack_a[t->argc - t->height_a] = temp;
		return (1);
	}
	else
		return (-1);
}

int	move_sb(t_stack *t)
{
	int	temp;

	if (t->height_b > 1)
	{
		temp = t->stack_b[t->argc - t->height_b - 1];
		t->stack_b[t->argc - t->height_b - 1] = t->stack_b[t->argc - t->height_b];
		t->stack_b[t->argc - t->height_b] = temp;
		return (2);
	}
	else
		return (-2);
}

int	move_ss(t_stack *t)
{
	if (move_sa(t) + move_sb(t) != 3)
		return(3);
	else
		return (-3);
}

int	move_pa(t_stack *t)
{
	if (t->height_b > 0)
	{
		t->stack_a[t->argc - t->height_a - 2] = t->stack_b[t->argc - t->height_b - 1];
		t->height_b--;
		t->height_a++;
		return (4);
	}
	return (-4);
}

int	move_pb(t_stack *t)
{
	if (t->height_a > 0)
	{
		t->stack_b[t->argc - t->height_b - 2] = t->stack_a[t->argc - t->height_a - 1];
		t->height_a--;
		t->height_b++;
		return (5);
	}
	return (-5);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 2)
		ft_putstr_fd("Error", 2);
	t_stack t;
	t.height_a = argc - 1;
	t.height_b = 0;
	t.argc = argc;
	t.stack_a = malloc(sizeof(int) * t.height_a);
	t.stack_b = malloc(sizeof(int) * t.height_a);

	i = 0;
	while (i < argc - 1)
	{
		t.stack_a[i] = ft_atoi(argv[1 + i]);
		i++;
	}
	print_stacks(&t);
	move_pb(&t);
	print_stacks(&t);
	move_pb(&t);
	print_stacks(&t);
	move_pb(&t);
	print_stacks(&t);
	move_pb(&t);
	print_stacks(&t);
	move_pb(&t);
	print_stacks(&t);
	move_pa(&t);
	print_stacks(&t);
	move_pa(&t);
	print_stacks(&t);
	move_pa(&t);
	print_stacks(&t);
	move_pa(&t);
	print_stacks(&t);
	move_pa(&t);
	print_stacks(&t);
	move_pa(&t);
	print_stacks(&t);
	free(t.stack_a);
	free(t.stack_b);
	return (0);	
}


