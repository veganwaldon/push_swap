/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwaldon <vwaldon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:06:08 by vwaldon           #+#    #+#             */
/*   Updated: 2022/03/09 19:06:11 by vwaldon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sort(t_list *first, int len)
{
	t_list	*temp;

	temp = first;
	while (len - 1 > 0)
	{
		if (temp->num > temp->next->num)
			return (-1);
		len--;
		temp = temp->next;
	}
	return (0);
}

void	find_minmax(int *number, int len, t_info *info)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len - 1)
	{
		j = len - 1;
		while (j > i)
		{
			if (number[j - 1] > number[j])
			{
				temp = number[j - 1];
				number[j - 1] = number[j];
				number[j] = temp;
			}
			j--;
		}
		i++;
	}
	i = 0;
	info->max = number[len - 1];
	info->min = number[0];
	info->med = number[len / 2];
	info->len_a = len;
}

t_list	*int_to_list(int *number, int len)
{
	int		i;
	t_list	*first;
	t_list	*tmp;

	i = len - 1;
	first = NULL;
	while (i >= 0)
	{
		tmp = malloc(sizeof(t_list));
		if (!tmp)
			exit(1);
		tmp->num = number[i];
		tmp->next = first;
		first = tmp;
		i--;
	}
	return (first);
}

t_list	*create_list(int argc, char **argv, t_info *info)
{
	t_list	*list;
	int		*number;
	int		len;

	list = NULL;
	if (argc == 2)
	{
		number = ft_parse_onearg(argv[1]);
		len = count_args(argv[1]);
	}
	if (argc > 2)
	{
		number = ft_parse_multiarg(argv, argc);
		len = argc - 1;
	}
	ft_check_dup(number, len);
	list = int_to_list(number, len);
	if (ft_is_sort(list, len) == 0)
		exit(1);
	find_minmax(number, len, info);
	info->len_b = 0;
	free(number);
	return (list);
}
