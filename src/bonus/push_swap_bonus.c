/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:11:59 by upolat            #+#    #+#             */
/*   Updated: 2024/06/18 16:30:50 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	error_handler(char *str, t_stack *t, int standard)
{
	ft_putstr_fd(str, standard);
	free_stacks(t);
	exit (0);
}

void	input_checker(t_stack *t, char *str, int print_flag)
{
	if (!ft_strncmp(str, "sa\n", 3))
		move_sa(t, print_flag);
	else if (!ft_strncmp(str, "sb\n", 3))
		move_sb(t, print_flag);
	else if (!ft_strncmp(str, "ss\n", 3))
		move_ss(t, print_flag);
	else if (!ft_strncmp(str, "pa\n", 3))
		move_pa(t, print_flag);
	else if (!ft_strncmp(str, "pb\n", 3))
		move_pb(t, print_flag);
	else if (!ft_strncmp(str, "ra\n", 3))
		move_ra(t, print_flag);
	else if (!ft_strncmp(str, "rb\n", 3))
		move_rb(t, print_flag);
	else if (!ft_strncmp(str, "rr\n", 3))
		move_rr(t, print_flag);
	else if (!ft_strncmp(str, "rra\n", 4))
		move_rra(t, print_flag);
	else if (!ft_strncmp(str, "rrb\n", 4))
		move_rrb(t, print_flag);
	else if (!ft_strncmp(str, "rrr\n", 4))
		move_rrr(t, print_flag);
	else
		error_handler("Error\n", t, 2);
}

void	read_from_stdin(t_stack *t, int print_flag)
{
	char	*str;

	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (!str)
			break ;
		input_checker(t, str, print_flag);
		free(str);
		str = NULL;
	}
}

int	main(int argc, char **argv)
{
	t_stack	t;

	if (argc == 1)
		return (0);
	if (check_error(argc, argv, &t) < 0)
		return (ft_putstr_fd("Error\n", 2), 1);
	read_from_stdin(&t, 0);
	if (is_fully_sorted_ascending(&t, 0) && t.height_b == 0)
		error_handler("OK\n", &t, 1);
	else
		error_handler("KO\n", &t, 1);
	return (0);
}
