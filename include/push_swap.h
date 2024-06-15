/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:22:27 by upolat            #+#    #+#             */
/*   Updated: 2024/06/15 19:02:15 by upolat           ###   ########.fr       */
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
	int	*stack_a_temp;
	int	*stack_b_temp;
	int	height_a;
	int	height_b;
	int	height_a_temp;
	int	height_b_temp;
	int	argc;
}		t_stack;

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
