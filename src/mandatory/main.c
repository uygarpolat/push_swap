/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:11:59 by upolat            #+#    #+#             */
/*   Updated: 2024/06/15 00:44:09 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	reverse_sort_b(t_stack *t, int print_flag);

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

void	print_stacks_temp(t_stack *t)
{
	int	i;

	i = 0;
	ft_printf("Stack temp A: ");
	while (i < t->argc - t->height_a_temp - 1)
	{
		ft_printf("_ ");
		i++;
	}
	while (i < t->argc - 1)
		ft_printf("%d ", t->stack_a_temp[i++]);
	ft_printf("\n");

}

int	move_sa(t_stack *t, int print_flag)
{
	int	temp;

	if (t->height_a > 1)
	{
		if (print_flag == 1)
			ft_printf("sa\n");
		temp = t->stack_a[t->argc - t->height_a - 1];
		t->stack_a[t->argc - t->height_a - 1] = t->stack_a[t->argc - t->height_a];
		t->stack_a[t->argc - t->height_a] = temp;
		return (1);
	}
	else
		return (-1);
}

int	move_sb(t_stack *t, int print_flag)
{
	int	temp;

	if (t->height_b > 1)
	{
		if (print_flag == 1)
			ft_printf("sb\n");
		temp = t->stack_b[t->argc - t->height_b - 1];
		t->stack_b[t->argc - t->height_b - 1] = t->stack_b[t->argc - t->height_b];
		t->stack_b[t->argc - t->height_b] = temp;
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

int smart_sort(t_stack *t, int print_flag)
{
	int	i;
	int	k;
	int	pb_flag;
	int	move_count;

	pb_flag = 0;
	move_count = 0;
	i = 0;
	while (i < t->argc - 1)
	{
		k = 0;
		while (k < t->height_a_temp / 2)
		{
			if (t->stack_a_temp[k] == t->stack_a[t->argc - t->height_a - 1])
			{
				move_pb(t, print_flag);
				move_count++;
				//move_count = move_count + reverse_sort_b(t, print_flag);
				pb_flag = 1;
				break ;
			}
			k++;
		}
		if (pb_flag == 0)
		{
			move_ra(t, print_flag);
			move_count++;
		}
		pb_flag = 0;
		i++;
	}
	ft_printf("smart_sort move count is %d\n", move_count);
	return(move_count);
}

int	is_reverse_sorted(t_stack *t, int *stack, int height)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	if (height < 3)
		return (1);
	while (i < height - 1)
	{
		if (stack[t->argc - height  - 1 + i] < stack[t->argc - height - 1 + i + 1])
			counter++;
		i++;
	}
	if (counter < 2)
		return (1);
	else
		return (0);

}

int	reverse_sort_a(t_stack *t, int print_flag)
{
	int	counter;

	counter = 0;
	while (!is_reverse_sorted(t, t->stack_a, t->height_a))
	{
		if (t->stack_a[t->argc - t->height_a - 1] < t->stack_a[t->argc - t->height_a])
		{
			move_sa(t, print_flag);
			counter++;
		}
		if (t->stack_a[t->argc - 2] < t->stack_a[t->argc - t->height_a - 1])
			move_rra(t, print_flag);
		else
			move_ra(t, print_flag);
		counter++;
	}
	ft_printf("reverse_sort_a ended in %d moves.\n", counter);
	return (counter);
}

int	reverse_sort_b(t_stack *t, int print_flag)
{
	int	counter;

	counter = 0;
	while (!is_reverse_sorted(t, t->stack_b, t->height_b))
	{
		if (t->stack_b[t->argc - t->height_b - 1] < t->stack_b[t->argc - t->height_b])
		{
			move_sb(t, print_flag);
			counter++;
		}
		if (t->stack_b[t->argc - 2] < t->stack_b[t->argc - t->height_b - 1])
			move_rrb(t, print_flag);
		else
			move_rb(t, print_flag);
		counter++;
	}
	ft_printf("reverse_sort_b ended in %d moves.\n", counter);
	return (counter);
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc < 2)
		ft_putstr_fd("Error", 2);
	t_stack t;
	t.argc = argc;
	t.height_a = t.argc - 1;
	t.height_b = 0;
	t.height_a_temp = t.argc - 1;
	t.height_b_temp = 0;

	t.stack_a = malloc(sizeof(int) * t.height_a);
	t.stack_b = malloc(sizeof(int) * t.height_a);
	t.stack_a_temp = malloc(sizeof(int) * t.height_a);
	t.stack_b_temp = malloc(sizeof(int) * t.height_a);

	i = 0;
	while (i < t.argc - 1)
	{
		t.stack_a[i] = ft_atoi(argv[1 + i]);
		i++;
	}
	naive_sort(&t, 0);
	i = 0;
	while (i < t.argc - 1)
	{
		t.stack_a_temp[i] = t.stack_a[i];
		i++;
	}

	i = 0;
	while (i < t.argc - 1)
	{
		t.stack_a[i] = ft_atoi(argv[1 + i]);
		i++;
	}
	
	//print_stacks(&t);

	smart_sort(&t, 1);
	reverse_sort_a(&t, 1);
	//smart_sort(&t, 0);
	//naive_sort(&t, 1);
	print_stacks(&t);
	//test_sort(&t, 0);
	//print_stacks(&t);
	//print_stacks_temp(&t);
	free(t.stack_a);
	free(t.stack_b);
	free(t.stack_a_temp);
	free(t.stack_b_temp);
	return (0);	
}


