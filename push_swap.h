/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maambuhl <marcambuehl4@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:56:46 by maambuhl          #+#    #+#             */
/*   Updated: 2025/01/26 22:37:10 by maambuhl         ###   LAUSANNE.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h"
# include <stdio.h>
# include <errno.h>
# include <limits.h>

typedef struct s_stack_info
{
	int	*stack;
	int	*b;
	int	size;
	int	min;
	int	max;
	int	best_index;
	int	place;
	int	min_mv;
	int	nb_mv_a;
	int	nb_mv_b;
	int	best_index_b;
	int	best_index_a;
	int	tmp_mv_b;
	int	tmp_max;
	int	tmp_min;
	int	best_i;
}	t_stack_info;

void	err(char *str);
void	check_input(char **str, int ac);
void	pb(int *b, int size, int print);
void	pa(int *b, int print);
void	sa(int *stack, int size, int *b, int print);
void	sb(int *stack, int *b, int print);
void	ra(int *stack, int size, int *b, int print);
void	rb(int *stack, int *b, int print);
void	rr(int *stack, int size, int *b);
void	rra(int *stack, int size, int *b, int print);
void	rrb(int *stack, int *b, int print);
void	rrr(int *stack, int size, int *b);
int		find_max(int *stack, int b);
int		find_min(int *stack, int b);
int		make_mv_b(int *stack, int *b, int a);
int		find_best_i(t_stack_info *stack_i, int init_min_mv);
int		push_basic(t_stack_info *stack_i);
int		find_place(int *stack, int *b, t_stack_info *stack_i);
void	initiate_mv_a(t_stack_info *stack_i, int index_to_mv, int nb);
void	make_mv_a(t_stack_info *stack_i, int index_to_mv, int nb);
int		offset_b(t_stack_info *stack_i, int place);
void	final_push_to_a(t_stack_info *stack_i);
void	make_rr_rrr(t_stack_info *stack_i, int nb_rr, int nb_rrr);
int		count_mv(int tmp_b, int nb_mv_b, int nb_mv_a, t_stack_info *stack_i);
int		find_place_i(t_stack_info *stack_i, int to_place);
int		is_sorted(t_stack_info *stack_i);
void	last_three(t_stack_info *stack_i);
int		min_stack_a(t_stack_info *stack_i);
int		max_stack_a(t_stack_info *stack_i);
void	more_three(t_stack_info *stack_i);
int		count_mv_rrr_rr(int *nb_mv_b, int *nb_mv_a);

#endif
