/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small_amount.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:54:08 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/04 17:37:23 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_b(t_stack **stack_b)
{
	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	if ((*stack_b)->index < (*stack_b)->next->index)
		swap_b(&(*stack_b));
}

void	sort_three_arg(t_stack **stack_a)
{
	if ((*stack_a)->index > (*stack_a)->next->index)
	{
		rotate_a(&(*stack_a));
		if (stack_is_sort((*stack_a)) == -1)
			swap_a(&(*stack_a));
		if (stack_is_sort((*stack_a)) == -1)
			rotate_a(&(*stack_a));
		return ;
	}
	else if ((*stack_a)->index < (*stack_a)->next->index)
	{
		swap_a(&(*stack_a));
		if (stack_is_sort((*stack_a)) == -1)
			rotate_a(&(*stack_a));
		if (stack_is_sort((*stack_a)) == -1)
			swap_a(&(*stack_a));
		return ;
	}
}

void	sort_four_arg(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *last_stack;

	last_stack = stack_last((*stack_a));
	if ((*stack_a)->index > (*stack_a)->next->index)
	{
		swap_a(&(*stack_a));
		if ((*stack_a)->index > last_stack->index)
			reverse_rotate_a(&(*stack_a));
	}
	if ((*stack_a)->index < (*stack_a)->next->index)
	{
		if ((*stack_a)->index > last_stack->index)
		{
			reverse_rotate_a(&(*stack_a));
			sort_four_arg(&(*stack_a), &(*stack_b));
		}
	}
	if (stack_is_sort((*stack_a)) == -1)
	{
		push_b(&(*stack_b), &(*stack_a));
		sort_three_arg(&(*stack_a));
		sort_stack_b(&(*stack_b));
		push_a(&(*stack_a), &(*stack_b));
		sort_four_arg(&(*stack_a), &(*stack_b));
	}
}

void	sort_five_arg(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *last_stack;

	last_stack = stack_last((*stack_a));
	if ((*stack_a)->index > (*stack_a)->next->index)
	{
		swap_a(&(*stack_a));
		if ((*stack_a)->index > last_stack->index)
			reverse_rotate_a(&(*stack_a));
	}
	if ((*stack_a)->index < (*stack_a)->next->index)
	{
		if ((*stack_a)->index > last_stack->index)
		{
			reverse_rotate_a(&(*stack_a));
			sort_five_arg(&(*stack_a), &(*stack_b));
		}
	}
	if (stack_is_sort((*stack_a)) == -1)
	{
		push_b(&(*stack_b), &(*stack_a));
		sort_four_arg(&(*stack_a), &(*stack_b));
		push_a(&(*stack_a), &(*stack_b));
		sort_five_arg(&(*stack_a), &(*stack_b));
	}
}

void	sort_small_amount(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (argc == 2)
		swap_a(&(*stack_a));
	if (argc == 3)
		sort_three_arg(&(*stack_a));
	if (argc == 4)
		sort_four_arg(&(*stack_a), &(*stack_b));
	if (argc == 5)
		sort_five_arg(&(*stack_a), &(*stack_b));
}
