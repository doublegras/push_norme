/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:31:34 by maambuhl          #+#    #+#             */
/*   Updated: 2025/01/26 22:57:25 by maambuhl         ###   LAUSANNE.ch       */
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

void	initiate_mv_a(t_stack_info *stack_i, int index_to_mv, int nb)
{
	int	size_a;
	int	nb_rr;
	int	nb_rrr;

	nb_rr = 0;
	nb_rrr = 0;
	size_a = stack_i->size - (*stack_i->b + 1);
	index_to_mv = index_to_mv - (*stack_i->b + 1);
	if (stack_i->place > (*stack_i->b / 2) && index_to_mv < (size_a / 2))
	{
		if (stack_i->nb_mv_a > stack_i->nb_mv_b)
			nb_rr = stack_i->nb_mv_b;
		else
			nb_rr = stack_i->nb_mv_a;
	}
	else if (stack_i->place < (*stack_i->b / 2) && index_to_mv > (size_a / 2))
	{
		if (stack_i->nb_mv_a > stack_i->nb_mv_b)
			nb_rrr = stack_i->nb_mv_b;
		else
			nb_rrr = stack_i->nb_mv_a;
	}
	make_rr_rrr(stack_i, nb_rr, nb_rrr);
	make_mv_a(stack_i, index_to_mv, nb);
}
