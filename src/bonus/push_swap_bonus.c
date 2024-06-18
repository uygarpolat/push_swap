/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: upolat <upolat@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 23:11:59 by upolat            #+#    #+#             */
/*   Updated: 2024/06/18 03:20:10 by upolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	read_from_stdin(t_stack *t)
{
	char *str;
	(void)t;
	while (1)
	{
		//ft_putstr_fd("> ", STDIN_FILENO);
		str = get_next_line(STDIN_FILENO);
		if (str[0] ==  '\n')
			break ;
		//ft_putstr_fd(str, STDOUT_FILENO);
		free(str);
		str = NULL;
	}
	free(str);
	str = NULL;

}

int	main(int argc, char **argv)
{
	t_stack	t;

	if (check_error(argc, argv, &t) < 0)
		return (ft_putstr_fd("Error\n", 2), 1);
	read_from_stdin(&t);
	if (is_fully_sorted_ascending(&t, 0))
	{
		free_stacks(&t);
		return (0);
	}
	if (t.height_a < 4)
		sort_two_or_three_ascending(&t, 1);
	else
		sorter(&t, 0);
	free_stacks(&t);
	return (0);
}
