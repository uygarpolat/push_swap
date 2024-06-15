/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:11:59 by upolat            #+#    #+#             */
/*   Updated: 2024/06/15 18:43:41 by upolat           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	t;

	if (check_error(argc, argv, &t) < 0)
		return (ft_putstr_fd("Error\n", 2), 0);
	print_stacks(&t);
	free_stacks(&t);
	return (0);
}
