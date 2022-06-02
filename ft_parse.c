/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwaldon <vwaldon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:06:15 by vwaldon           #+#    #+#             */
/*   Updated: 2022/03/09 19:06:18 by vwaldon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_args(char *argv)
{
	int		i;
	int		len;
	int		length;
	char	**str;

	i = 0;
	len = 0;
	str = ft_split(argv, ' ');
	if (!str)
		ft_error();
	while (str[i++])
		len++;
	length = len;
	while (length >= 0)
		free(str[length--]);
	free(str);
	return (len);
}

int	*ft_parse_onearg(char *argv)
{
	int		i;
	int		len;
	int		length;
	int		*number;
	char	**str;

	i = 0;
	len = 0;
	str = ft_split(argv, ' ');
	if (!str)
		ft_error();
	while (str[i++])
		len++;
	number = malloc(sizeof(number) * (len));
	if (!number)
		exit(1);
	len = len -1;
	i = len;
	length = len;
	while (len >= 0)
		number[i--] = ft_atoi_ps(str[len--]);
	while (length >= 0)
		free(str[length--]);
	free(str);
	return (number);
}

int	*ft_parse_multiarg(char **argv, int argc)
{
	int	*number;
	int	i;
	int	len;

	number = malloc(sizeof(number) * (argc - 1));
	if (!number)
		exit(1);
	i = 0;
	len = 1;
	while (i < argc - 1)
		number[i++] = ft_atoi_ps(argv[len++]);
	return (number);
}

void	ft_check_dup(int *number, int len)
{
	int	i;
	int	j;

	i = -1;
	while (i++ < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (number[i] == number[j])
				ft_error();
			j++;
		}
	}
}
