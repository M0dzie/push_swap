/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:54:08 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/02 15:16:01 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sort(t_stack *stack)
{
	t_stack	*tmp;

	while (stack->next != NULL)
	{
		tmp = stack->next;
		if (stack->value > tmp->value)
			return (-1);
		stack = stack->next;
	}
	return (0);
}

void	sort_three_arg(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		rotate_a(&(*stack_a));
		if (stack_is_sort((*stack_a)) == -1)
			swap_a(&(*stack_a));
		if (stack_is_sort((*stack_a)) == -1)
			rotate_a(&(*stack_a));
		return ;
	}
	else if ((*stack_a)->value < (*stack_a)->next->value)
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
	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		swap_a(&(*stack_a));
		if ((*stack_a)->value > last_stack->value)
			reverse_rotate_a(&(*stack_a));
	}
	if ((*stack_a)->value < (*stack_a)->next->value)
	{
		if ((*stack_a)->value > last_stack->value)
		{
			reverse_rotate_a(&(*stack_a));
			sort_four_arg(&(*stack_a), &(*stack_b));
		}
	}
	if (stack_is_sort((*stack_a)) == -1)
	{
		push_b(&(*stack_b), &(*stack_a));
		sort_three_arg(&(*stack_a));
		push_a(&(*stack_a), &(*stack_b));
		sort_four_arg(&(*stack_a), &(*stack_b));
	}
}

void	sort_small_amount(t_stack **stack_a, t_stack **stack_b, int argc)
{
	print_stack_a((*stack_a));
	if (argc == 2)
		swap_a(&(*stack_a));
	if (argc == 3)
		sort_three_arg(&(*stack_a));
	if (argc == 4)
		sort_four_arg(&(*stack_a), &(*stack_b));
	// if (argc == 3=5)
	// 	dude;
}

// void	sort_large_amount(t_stack **stack_a, t_stack **stack_b)
// {
// }