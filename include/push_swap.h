/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:22:27 by upolat            #+#    #+#             */
/*   Updated: 2024/06/16 00:31:32 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
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

void	free_stacks(t_stack *t);
int		check_error(int argc, char **argv, t_stack *t);
void	free_2d_array(void ***arr);

#endif
