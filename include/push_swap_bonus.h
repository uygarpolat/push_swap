/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:22:27 by upolat            #+#    #+#             */
/*   Updated: 2024/06/19 08:51:51 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"

typedef struct s_stack
{
	int	*stack_a;
	int	*stack_b;
	int	height_a;
	int	height_b;
	int	argc;
}		t_stack;

typedef struct s_costs
{
	int	cost_ra;
	int	cost_rra;
	int	cost_rb;
	int	cost_rrb;
	int	execute_ra;
	int	execute_rb;
	int	execute_rr;
	int	execute_rra;
	int	execute_rrb;
	int	execute_rrr;
	int	min_cost;
}		t_costs;

// Moves
int		move_sa(t_stack *t, int print_flag);
int		move_sb(t_stack *t, int print_flag);
int		move_ss(t_stack *t, int print_flag);
int		move_pa(t_stack *t, int print_flag);
int		move_pb(t_stack *t, int print_flag);
int		move_ra(t_stack *t, int print_flag);
int		move_rb(t_stack *t, int print_flag);
int		move_rr(t_stack *t, int print_flag);
int		move_rra(t_stack *t, int print_flag);
int		move_rrb(t_stack *t, int print_flag);
int		move_rrr(t_stack *t, int print_flag);

// Move execution
void	execute_group_1(t_stack *t, t_costs *c, int print_flag);
void	execute_group_2(t_stack *t, t_costs *c, int print_flag);
void	execute_group_3(t_stack *t, t_costs *c, int print_flag);
void	execute_group_4(t_stack *t, t_costs *c, int print_flag);
void	calculate_and_execute(t_stack *t, int print_flag);

// Sorters
void	sorter(t_stack *t, int print_flag);
void	sort_two_or_three_ascending(t_stack *t, int print_flag);
int		is_fully_sorted_ascending(t_stack *t, int print_flag);
int		is_two_or_three_pseudo_sorted_ascending(t_stack *t, int i, int flag);
int		index_of_insertion_in_b(t_stack *t, int index);

// Utils
int		max_finder(int a, int b);
int		min_finder(int a, int b, int c, int d);
int		get_min_index(t_stack *t);
int		get_max_index(t_stack *t);
int		check_error(int argc, char **argv, t_stack *t);
void	free_stacks(t_stack *t);
void	free_2d_array(void ***arr);
void	print_stacks(t_stack *t);

#endif
