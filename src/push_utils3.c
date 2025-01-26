/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:19:42 by maambuhl          #+#    #+#             */
/*   Updated: 2025/01/20 14:31:34 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack_info *stack_i)
{
	int	i;

	i = 0;
	while (i < (stack_i->size - 1))
	{
		if (stack_i->stack[i] < stack_i->stack[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

int	max_stack_a(t_stack_info *stack_i)
{
	int	max;
	int	j;

	j = *stack_i->b + 1;
	max = j;
	while (j < stack_i->size)
	{
		if (stack_i->stack[j] > stack_i->stack[max])
			max = j;
		j++;
	}
	return (max - (*stack_i->b + 1));
}


int	min_stack_a(t_stack_info *stack_i)
{
	int	min;
	int	j;

	j = *stack_i->b + 1;
	min = j;
	while (j < stack_i->size)
	{
		if (stack_i->stack[j] < stack_i->stack[min])
			min = j;
		j++;
	}
	return (min - (*stack_i->b + 1));
}

int	find_place_in_a(int *stack, t_stack_info *stack_i, int to_place)
{
	int	max;
	int	min;
	int	i;

	max = max_stack_a(stack_i) + 1 + *stack_i->b;
	min = min_stack_a(stack_i) + 1 + *stack_i->b;
	i = stack_i->size - 1;
	if (to_place >= stack[max] || to_place <= stack[min])
		return (max);
	while (i)
	{
		if (to_place > stack[i - 1] && to_place < stack[i])
			return (i - 1);
		i--;
	}
	return (i);
}

void	more_three(t_stack_info *stack_i)
{
	int	place;
	int	nb;
	int	size_a;

	size_a = stack_i->size - (*stack_i->b + 1);
	place = find_place_in_a(stack_i->stack, stack_i, stack_i->stack[*stack_i->b]);
	nb = stack_i->stack[place];
	if (place)
	{
		while (stack_i->stack[stack_i->size - 1] != nb)
		{
			if (place < (size_a / 2))
				ra(stack_i->stack, stack_i->size, stack_i->b, 1);
			else
				rra(stack_i->stack, stack_i->size, stack_i->b, 1);
		}
	}
	pa(stack_i->b, 1);
}

void	last_three(t_stack_info *stack_i)
{
	int	max;
	int	min;
	max = max_stack_a(stack_i);
	min = min_stack_a(stack_i);
	if (min == 0 && max == 1)
	{
		sa(stack_i->stack, stack_i->size, stack_i->b, 1);
		ra(stack_i->stack, stack_i->size, stack_i->b, 1);
	}
	else if (min == 1 && max == 2)
		sa(stack_i->stack, stack_i->size, stack_i->b, 1);
	else if (max == 0 && min == 2)
	{
		ra(stack_i->stack, stack_i->size, stack_i->b, 1);
		sa(stack_i->stack, stack_i->size, stack_i->b, 1);
	}
	else if (max == 0)
		ra(stack_i->stack, stack_i->size, stack_i->b, 1);
	else if (min == 2)
		rra(stack_i->stack, stack_i->size, stack_i->b, 1);
}
