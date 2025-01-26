/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:35:44 by maambuhl          #+#    #+#             */
/*   Updated: 2024/12/19 22:12:18 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(int *b, int size, int print)
{
	if (*b == (size - 1))
		return ;
	(*b)++;
	if (print)
		ft_putstr_fd("pb\n", 1);
}

void	pa(int *b, int print)
{
	if (*b < 0)
		return ;
	(*b)--;
	if (print)
		ft_putstr_fd("pa\n", 1);
}

void	sa(int *stack, int size, int *b, int print)
{
	int	temp;

	if (*b <= (size - 3))
	{
		temp = stack[*b + 1];
		stack[*b + 1] = stack[*b + 2];
		stack[*b + 2] = temp;
		if (print)
			ft_putstr_fd("sa\n", 1);
	}
}

void	sb(int *stack, int *b, int print)
{
	int	temp;

	if (*b > 0)
	{
		temp = stack[*b];
		stack[*b] = stack[*b - 1];
		stack[*b - 1] = temp;
		if (print)
			ft_putstr_fd("sb\n", 1);
	}
}

void	ss(int *stack, int size, int *b)
{
	sa(stack, size, b, 0);
	sb(stack, b, 0);
	ft_putstr_fd("ss", 1);
}
