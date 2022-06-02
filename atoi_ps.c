/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwaldon <vwaldon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:05:47 by vwaldon           #+#    #+#             */
/*   Updated: 2022/03/11 22:52:32 by vwaldon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, int sign)
{
	int					i;
	unsigned long int	nb;

	i = 0;
	nb = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
		ft_error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i++] - '0');
	}
	if (str[i])
		ft_error();
	if ((nb > 2147483647) && (sign == 1))
		ft_error();
	if ((nb > 2147483648) && (sign == -1))
		ft_error();
	return ((int)(nb * sign));
}

int	ft_atoi_ps(const char *str)
{
	int		i;
	int		len;
	int		sign;
	char	*line;

	sign = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	len = ft_strlen(str);
	line = ft_substr(str, i, len - i);
	i = ft_atoi(line, sign);
	free(line);
	return (i);
}
