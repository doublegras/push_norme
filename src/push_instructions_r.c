/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions_r.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:37:03 by maambuhl          #+#    #+#             */
/*   Updated: 2025/01/03 21:58:46 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(int *stack, int size, int *b, int print)
{
	int	temp;
	int	i;

	i = *b + 1;
	if ((size - i) >= 2)
	{
		temp = stack[i];
		while (i < (size - 1))
		{
			stack[i] = stack[i + 1];
			i++;
		}
		stack[i] = temp;
		if (print)
			ft_putstr_fd("ra\n", 1);
	}
}

void	rb(int *stack, int *b, int print)
{
	int	temp;
	int	i;

	i = *b;
	if (i >= 1)
	{
		temp = stack[i];
		while (i > 0)
		{
			stack[i] = stack[i - 1];
			i--;
		}
		stack[i] = temp;
		if (print)
			ft_putstr_fd("rb\n", 1);
	}
}

void	rr(int *stack, int size, int *b)
{
	ra(stack, size, b, 0);
	rb(stack, b, 0);
	ft_putstr_fd("rr\n", 1);
}
