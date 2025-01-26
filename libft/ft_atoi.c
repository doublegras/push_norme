/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:23:48 by maambuhl          #+#    #+#             */
/*   Updated: 2024/12/05 15:27:51 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *s)
{
	long	i;
	long	neg;
	long	res;

	i = 0;
	neg = 1;
	res = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'
		|| s[i] == '\v' || s[i] == '\r' || s[i] == '\f')
		i++;
	if (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (ft_isdigit(s[i]))
	{
		res += s[i] - '0';
		i++;
		if (ft_isdigit(s[i]) && s[i] != 0)
			res *= 10;
	}
	return (res * neg);
}
