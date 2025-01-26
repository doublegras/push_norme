/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions_rr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:37:03 by maambuhl          #+#    #+#             */
/*   Updated: 2025/01/07 21:19:35 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(int *stack, int size, int *b, int print)
{
	int	temp;
	int	i;

	i = *b + 1;
	if ((size - i) >= 2)
	{
		--size;
		while (size > i)
		{
			temp = stack[size];
			stack[size] = stack[size - 1];
			stack[size - 1] = temp;
			size--;
		}
		if (print)
			ft_putstr_fd("rra\n", 1);
	}
}

void	rrb(int *stack, int *b, int print)
{
	int	temp;
	int	i;

	i = 0;
	if (*b >= 1)
	{
		while (i < *b)
		{
			temp = stack[i];
			stack[i] = stack[i + 1];
			stack[i + 1] = temp;
			i++;
		}
		if (print)
			ft_putstr_fd("rrb\n", 1);
	}
}

void	rrr(int *stack, int size, int *b)
{
	rra(stack, size, b, 0);
	rrb(stack, b, 0);
	ft_putstr_fd("rrr\n", 1);
}
