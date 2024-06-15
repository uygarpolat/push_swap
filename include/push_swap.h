/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:22:27 by upolat            #+#    #+#             */
/*   Updated: 2024/06/15 18:10:57 by upolat           ###   ########.fr       */
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

void	free_stacks(t_stack *t);
int		check_error(int argc, char **argv, t_stack *t);
void	free_2d_array(void ***arr);

#endif
