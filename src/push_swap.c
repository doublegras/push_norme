/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:33:41 by maambuhl          #+#    #+#             */
/*   Updated: 2025/01/28 14:18:07 by maambuhl         ###   LAUSANNE.ch       */
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

int	*create_stack(char **strs, int size)
{
	int		i;
	int		*stack;
	long	temp;

	stack = malloc(sizeof(int) * size);
	if (!stack)
		err("Error\nCannot malloc stack");
	i = 0;
	while (i < size)
	{
		temp = ft_atoi(strs[i]);
		if (temp > INT_MAX || temp < INT_MIN)
		{
			free(stack);
			err("Error\nProvide number that fit 32bit integer");
		}
		stack[i] = temp;
		i++;
	}
	return (stack);
}

// void	print_a(int *b, int *stack, int size)
// {
// 	int	i;
//
// 	i = *b + 1;
// 	printf("A = [ ");
// 	while (i < size)
// 		printf("%d ", stack[i++]);
// 	printf("]\n");
// }
//
// void	print_b(int *b, int *stack)
// {
// 	int	i;
//
// 	i = *b;
// 	printf("B = [ ");
// 	if (i >= 0)
// 	{
// 		while (i >= 0)
// 			printf("%d  ", stack[i--]);
// 	}
// 	printf("]\n");
// }
//
// void	print_s(int *b, int *stack, int size)
// {
// 	print_a(b, stack, size);
// 	print_b(b, stack);
// }

void	algo(t_stack_info *stack_i)
{
	int	place;
	int	best_index;
	int	init_min_mv;

	pb(stack_i->b, stack_i->size, 1);
	pb(stack_i->b, stack_i->size, 1);
	while ((*stack_i->b + 1) < stack_i->size)
	{
		best_index = 0;
		stack_i->min = find_min(stack_i->stack, *stack_i->b);
		stack_i->max = find_max(stack_i->stack, *stack_i->b);
		place = find_place_i(stack_i, stack_i->stack[(*stack_i->b) + 1]);
		stack_i->best_index_b = place;
		init_min_mv = offset_b(stack_i, place);
		best_index = find_best_i(stack_i, init_min_mv);
		if (best_index)
		{
			initiate_mv_a(stack_i, best_index, stack_i->stack[best_index]);
			place = stack_i->place;
		}
		make_mv_b(stack_i->stack, stack_i->b, place);
		pb(stack_i->b, stack_i->size, 1);
	}
	final_push_to_a(stack_i);
}

void	init_struct(t_stack_info *stack_i, char **av, int ac)
{
	int				*stack;

	check_input(av + 1, ac - 1);
	stack = create_stack(av + 1, ac - 1);
	stack_i->size = ac - 1;
	stack_i->stack = stack;
	stack_i->max = 0;
	stack_i->min = 0;
	stack_i->nb_mv_b = 0;
	stack_i->nb_mv_a = 0;
}

int	main(int ac, char **av)
{
	int				b;
	t_stack_info	stack_i;

	if (ac < 2)
		return (0);
	init_struct(&stack_i, av, ac);
	b = -1;
	stack_i.b = &b;
	if (is_sorted(&stack_i))
	{
		if (ac <= 4)
			last_three(&stack_i);
		else if (ac <= 6)
		{
			while (--ac > 3)
				pb(stack_i.b, stack_i.size, 1);
			last_three(&stack_i);
			while (--ac)
				more_three(&stack_i);
			final_push_to_a(&stack_i);
		}
		else
			algo(&stack_i);
	}
	free(stack_i.stack);
}
