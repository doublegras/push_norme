/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:33:59 by maambuhl          #+#    #+#             */
/*   Updated: 2025/01/26 22:26:25 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_place(int *stack, int *b, t_stack_info *stack_i)
{
	int	to_place;
	int	i;

	i = *b;
	to_place = stack[(*b) + 1];
	if (to_place >= stack[stack_i->max] || to_place <= stack[stack_i->min])
		return (stack_i->max);
	while (i)
	{
		if (to_place > stack[i - 1] && to_place < stack[i])
			return (i - 1);
		if (to_place > stack[*b] && stack[(*b) + 1] < stack[0])
			return (*b);
		i--;
	}
	return (i);
}

int	find_place_i(t_stack_info *stack_i, int to_place)
{
	int	i;
	int	*stack;
	int	*b;
	
	stack = stack_i->stack;
	b = stack_i->b;
	i = *b;
	if (to_place > stack[stack_i->max] || to_place < stack[stack_i->min])
		return (stack_i->max);
	while (i)
	{
		if (to_place > stack[i - 1] && to_place < stack[i])
			return (i - 1);
		if (to_place > stack[*b] && to_place < stack[0])
			return (*b);
		i--;
	}
	return (i);
}

int	offset_a(t_stack_info *stack_i, int tmp_b)
{
	int	size_a;
	
	tmp_b = tmp_b - (*stack_i->b + 1);
	size_a = stack_i->size - (*stack_i->b + 1);
	if (tmp_b < (size_a / 2))
		return (tmp_b);
	else
		return (size_a - tmp_b);
}

int	offset_b(t_stack_info *stack_i, int place)
{
	if (place < ((*stack_i->b) / 2))
		return (place + 1);
	else
		return (*stack_i->b - place);
}

int	count(t_stack_info *stack_i, int tmp_b, int *nb_mv_b, int *nb_mv_a)
{
	int	place;
	int	size_a;
	int	nb_mv;

	place = find_place_i(stack_i, stack_i->stack[tmp_b]);
	size_a = stack_i->size - (*stack_i->b + 1);
	*nb_mv_b = offset_b(stack_i, place);
	if (place < (*stack_i->b / 2))
	{
		if (tmp_b - (*stack_i->b + 1) > (size_a / 2))
			nb_mv = count_mv_rrr_rr(nb_mv_b, nb_mv_a);
		else
			nb_mv = (*nb_mv_b + *nb_mv_a);
	}
	else
	{
		if (tmp_b - (*stack_i->b + 1) < (size_a / 2))
			nb_mv = count_mv_rrr_rr(nb_mv_b, nb_mv_a);
		else
			nb_mv = (*nb_mv_b + *nb_mv_a);
	}
	return (nb_mv);
}

int	find_best_i(t_stack_info *stack_i, int init_min_mv)
{
	int	nb_mv;
	int	nb_mv_a;
	int	tmp_b;
	int	nb_mv_b;
	
	tmp_b = *stack_i->b;
	stack_i->best_i = 0;
	while (++tmp_b < stack_i->size)
	{
		nb_mv_b = 0;
		nb_mv_a = offset_a(stack_i, tmp_b);
		nb_mv = count(stack_i, tmp_b, &nb_mv_b, &nb_mv_a);
		if (nb_mv < init_min_mv)
		{
			init_min_mv = nb_mv;
			stack_i->best_i = tmp_b;
			stack_i->nb_mv_b = nb_mv_b;
			stack_i->nb_mv_a = nb_mv_a;
			stack_i->min_mv = nb_mv;
			stack_i->place = find_place_i(stack_i, stack_i->stack[tmp_b]);
		}
	}
	stack_i->best_index = stack_i->best_i;
	stack_i->best_index_a = stack_i->best_i;
	return (stack_i->best_i);
}

int	initiate_mv_a(t_stack_info *stack_i, int index_to_mv, int nb)
{
	int	size_a;
	int	nb_rr;
	int	nb_rrr;
	int	i;
	
	nb_rr = 0;
	nb_rrr = 0;
	i = 0;
	size_a = stack_i->size - (*stack_i->b + 1);
	index_to_mv = index_to_mv - (*stack_i->b + 1);
	if (stack_i->place > (*stack_i->b / 2) && index_to_mv < (size_a / 2))
	{
		i = 1;
		if (stack_i->nb_mv_a > stack_i->nb_mv_b)
			nb_rr = stack_i->nb_mv_b;
		else
			nb_rr = stack_i->nb_mv_a;
	}
	else if (stack_i->place < (*stack_i->b / 2) && index_to_mv > (size_a / 2))
	{
		i = 1;
		if (stack_i->nb_mv_a > stack_i->nb_mv_b)
			nb_rrr = stack_i->nb_mv_b;
		else
			nb_rrr = stack_i->nb_mv_a;
	}
	make_rr_rrr(stack_i, nb_rr, nb_rrr);
	make_mv_a(stack_i, index_to_mv, nb);
	return (i);
}
