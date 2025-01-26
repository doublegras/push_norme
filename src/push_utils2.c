/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:31:34 by maambuhl          #+#    #+#             */
/*   Updated: 2025/01/26 22:23:43 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_mv_rrr_rr(int *nb_mv_b, int *nb_mv_a)
{
	int	nb_mv;

	if (*nb_mv_a > *nb_mv_b)
		nb_mv = *nb_mv_a;
	else
		nb_mv = *nb_mv_b;
	return (nb_mv);
}

int	find_max(int *stack, int b)
{
	int	max;
	int	i;

	i = b;
	max = stack[b--];
	while (b >= 0)
	{
		if (stack[b] > max)
		{
			max = stack[b];
			i = b;
		}
		b--;
	}
	return (i);
}

int	find_min(int *stack, int b)
{
	int	min;
	int	i;

	i = b;
	min = stack[b--];
	while (b >= 0)
	{
		if (stack[b] < min)
		{
			min = stack[b];
			i = b;
		}
		b--;
	}
	return (i);
}

int	count_mv(int tmp_b, int nb_mv_b, int nb_mv_a, t_stack_info *stack_i)
{
	int	size_a;
	int	nb_mv;
	int	to_place;
	int	place;

	nb_mv = 0;
	size_a = stack_i->size - (*stack_i->b + 1);
	to_place = stack_i->stack[tmp_b];
	place = find_place_i(stack_i, to_place);
	if (place < (*stack_i->b / 2))
	{
		//rrb
		stack_i->tmp_mv_b = place + 1;
		if (tmp_b - (*stack_i->b + 1) > (size_a / 2))
		{ // rra
			if (nb_mv_a > nb_mv_b)
				nb_mv = nb_mv_a;
			else
				nb_mv = nb_mv_b;
		}
		else
			nb_mv += (nb_mv_b + nb_mv_a);
		return (nb_mv);
	}
	stack_i->tmp_mv_b = *stack_i->b - place;
	if (tmp_b - (*stack_i->b + 1) < (size_a / 2))
	{ // ra
		if (nb_mv_a > nb_mv_b)
			nb_mv = nb_mv_a;
		else
			nb_mv = nb_mv_b;
	}
	else
		nb_mv += (nb_mv_b + nb_mv_a);
	return (nb_mv);
}

void	final_push_to_a(t_stack_info *stack_i)
{
	int	i;
	int	min;
	int	min_i;

	i = 0;
	while (i < stack_i->size)
	{
		pa(stack_i->b, 1);
		i++;
	}
	i = 0;
	min_i = find_min(stack_i->stack, stack_i->size - 1);
	min = stack_i->stack[min_i];
	if (min_i <= (stack_i->size / 2))
	{
		while (*stack_i->stack != min)
			ra(stack_i->stack, stack_i->size, stack_i->b, 1);
	}
	else
	{
		while (*stack_i->stack != min)
			rra(stack_i->stack, stack_i->size, stack_i->b, 1);
	}
}
