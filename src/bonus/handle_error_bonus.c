/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 18:02:22 by upolat            #+#    #+#             */
/*   Updated: 2024/06/18 19:40:48 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '-' && str[i] != '+' && (str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

int	number_validity_check(int argc, char **argv)
{
	int		i;
	int		j;
	int		counter;
	char	**arr;

	counter = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		arr = ft_split(argv[i++], ' ');
		if (arr == NULL)
			return (-1);
		while (arr[j])
		{
			if (ft_isnum(arr[j]) && (ft_strlen(arr[j]) < 3
					|| ft_atoi(arr[j]) != 0))
				counter++;
			else
				return (free_2d_array((void ***)&arr), -1);
			j++;
		}
		free_2d_array((void ***)&arr);
	}
	return (counter);
}

int	initialize_stacks(int argc, char **argv, t_stack *t, int number_count)
{
	int		i;
	int		j;
	int		k;
	char	**arr;

	t->stack_a = malloc(sizeof(int) * (number_count));
	t->stack_b = malloc(sizeof(int) * (number_count));
	if (t->stack_a == NULL || t->stack_b == NULL)
		return (-1);
	k = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		arr = ft_split(argv[i++], ' ');
		if (arr == NULL)
			return (-1);
		while (arr[j])
			t->stack_a[k++] = ft_atoi(arr[j++]);
		free_2d_array((void ***)&arr);
	}
	t->argc = number_count + 1;
	t->height_a = t->argc - 1;
	t->height_b = 0;
	return (0);
}

int	number_recurrence_check(t_stack *t)
{
	int	i;
	int	j;

	i = 0;
	while (i < t->height_a)
	{
		j = i + 1;
		while (j < t->height_a)
		{
			if (t->stack_a[i] == t->stack_a[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_error(int argc, char **argv, t_stack *t)
{
	int	number_count;
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i++]) == 0)
			return (-1);
	}
	number_count = number_validity_check(argc, argv);
	if (number_count == -1)
		return (-1);
	if (initialize_stacks(argc, argv, t, number_count) == -1)
	{
		free_stacks(t);
		return (-2);
	}
	if (number_recurrence_check(t) == -1)
	{
		free_stacks(t);
		return (-3);
	}
	return (0);
}
