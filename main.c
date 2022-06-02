/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwaldon <vwaldon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:06:22 by vwaldon           #+#    #+#             */
/*   Updated: 2022/03/13 15:05:33 by vwaldon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write (1, "Error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*tmp;
	t_info	info;

	if (argc < 2)
		exit(1);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = create_list(argc, argv, &info);
	solve(&stack_a, &stack_b, &info);
	tmp = NULL;
	while (stack_a)
	{
		tmp = stack_a;
		stack_a = stack_a->next;
		free(tmp);
	}
	return (0);
}
