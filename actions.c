/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwaldon <vwaldon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:05:15 by vwaldon           #+#    #+#             */
/*   Updated: 2022/03/09 19:05:18 by vwaldon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list *stack_a, int flag)
{
	int	temp;

	if (stack_a && stack_a != stack_a->next)
	{
		temp = stack_a->num;
		stack_a->num = stack_a->next->num;
		stack_a->next->num = temp;
	}
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_list *stack_b, int flag)
{
	int	temp;

	if (stack_b && stack_b != stack_b->next)
	{
		temp = stack_b->num;
		stack_b->num = stack_b->next->num;
		stack_b->next->num = temp;
	}
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_list *stack_a, t_list *stack_b, int flag)
{
	ft_sa(stack_a, 0);
	ft_sb(stack_b, 0);
	if (flag == 1)
		write(1, "ss\n", 3);
}
