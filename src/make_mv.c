/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_mv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:53:00 by maambuhl          #+#    #+#             */
/*   Updated: 2025/01/10 14:21:53 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	make_mv_a(t_stack_info *stack_i, int index_to_mv, int nb)
{
	int	head;
	int	size_a;

	size_a = stack_i->size - (*stack_i->b + 1);
	head = stack_i->stack[(*stack_i->b) + 1];
	while (head != nb)
	{
		if (index_to_mv < (size_a / 2))
			ra(stack_i->stack, stack_i->size, stack_i->b, 1);
		else
			rra(stack_i->stack, stack_i->size, stack_i->b, 1);
		head = stack_i->stack[(*stack_i->b) + 1];
	}
}

void	make_rr_rrr(t_stack_info *stack_i, int nb_rr, int nb_rrr)
{
	int	i;

	i = -1;
	while (++i < nb_rr)
	{
		rr(stack_i->stack, stack_i->size, stack_i->b);
		if (stack_i->place == *stack_i->b)
			stack_i->place = 0;
		else
			stack_i->place++;
	}
	i = -1;
	while (++i < nb_rrr)
	{
		rrr(stack_i->stack, stack_i->size, stack_i->b);
		if (stack_i->place == 0)
			stack_i->place = *stack_i->b;
		else
			stack_i->place--;
	}
}

int	make_mv_b(int *stack, int *b, int place)
{
	int	nb;
	int	head;
	int	i;

	nb = stack[place];
	head = stack[*b];
	i = 0;
	while (head != nb)
	{
		if (place < (*b / 2))
			rrb(stack, b, 1);
		else
			rb(stack, b, 1);
		head = stack[*b];
		i++;
	}
	return (i);
}
