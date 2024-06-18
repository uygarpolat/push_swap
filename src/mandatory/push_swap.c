/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:11:59 by upolat            #+#    #+#             */
/*   Updated: 2024/06/18 16:30:57 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	t;

	if (argc == 1)
		return (0);
	if (check_error(argc, argv, &t) < 0)
		return (ft_putstr_fd("Error\n", 2), 1);
	if (is_fully_sorted_ascending(&t, 1))
	{
		free_stacks(&t);
		return (0);
	}
	if (t.height_a < 4)
		sort_two_or_three_ascending(&t, 1);
	else
		sorter(&t, 1);
	free_stacks(&t);
	return (0);
}
