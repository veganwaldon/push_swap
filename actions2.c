/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwaldon <vwaldon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:05:22 by vwaldon           #+#    #+#             */
/*   Updated: 2022/03/09 19:05:25 by vwaldon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **stack_a, int flag)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*stack_a) || !((*stack_a)->next))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	last = *stack_a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_list **stack_b, int flag)
{
	t_list	*tmp;
	t_list	*last;

	if (!(*stack_b) || !((*stack_b)->next))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	last = *stack_b;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(t_list **stack_a, t_list **stack_b, int flag)
{
	ft_ra(stack_a, 0);
	ft_rb(stack_b, 0);
	if (flag == 1)
		write(1, "rr\n", 3);
}
