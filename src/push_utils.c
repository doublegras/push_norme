/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:02:16 by maambuhl          #+#    #+#             */
/*   Updated: 2025/01/10 13:21:55 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	err(char *str)
{
	if (str && errno)
		perror(str);
	else if (str)
		ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}

void	check_max_int(char *str)
{
	if (str[0] == '-' || str[0] == '=')
	{
		if (ft_strlen(str) > ft_strlen("-2147483647"))
			err("Error\nProvide number that fit 32bit integer");
	}
	else
	{
		if (ft_strlen(str) > ft_strlen("2147483647"))
			err("Error\nProvide number that fit 32bit integer");
	}
}

void	input_cleaner(char **str)
{
	if (*str[0] == '+')
		++(*str);
	if ((*str)[0] == '0' && (*str)[1] == '0')
	{
		while ((*str)[1] == '0')
			++(*str);
	}
}

void	check_double(char **strs, int size)
{
	int	i;
	int	y;
	int	c;

	i = 0;
	while (i < size)
	{
		y = 0;
		c = 0;
		while (y < size)
		{
			if (!ft_strcmp(strs[i], strs[y]))
				c++;
			if (c > 1)
				err("Error\nA number should occur only one time in the list");
			y++;
		}
		i++;
	}
}

void	check_input(char **str, int ac)
{
	int	i;
	int	y;

	i = 0;
	while (i < ac)
	{
		y = 0;
		while (str[i][y])
		{
			input_cleaner(&str[i]);
			if ((str[i][y] == '-' || str[i][y] == '+')
				&& !ft_isdigit(str[i][y + 1]))
				err("Error\nProvide valide numbers: 2, -2, +2");
			if (str[i][y] == '-' && str[i][y + 1] == '0')
				err("Error\n-0 is not a valid number");
			if (!ft_isdigit(str[i][y]) && str[i][y] != '-' && str[i][y] != '+')
				err("Error\nProvide valide numbers: 2, -2, +2");
			y++;
		}
		check_max_int(str[i]);
		i++;
	}
	check_double(str, ac);
}
