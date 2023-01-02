/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:35:47 by thmeyer           #+#    #+#             */
/*   Updated: 2022/12/30 15:00:18 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	switch_pos(t_stack **first, t_stack **second)
{
	t_stack	*tmp;

	tmp = (*first);
	(*first) = (*second);
	(*second) = tmp;
}

void	swap_a(t_stack **stack_a)
{
	t_stack	**first_a;
	t_stack	**second_a;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	first_a = stack_a;
	second_a = &(*stack_a)->next;
	switch_pos(first_a, second_a);
	switch_pos(&(*first_a)->next, &(*second_a)->next);
	ft_putendl_fd("sa", 1);
}

void	swap_b(t_stack **stack_b)
{
	t_stack	**first_b;
	t_stack	**second_b;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	first_b = stack_b;
	second_b = &(*stack_b)->next;
	switch_pos(first_b, second_b);
	switch_pos(&(*first_b)->next, &(*second_b)->next);
	ft_putendl_fd("sb", 1);
}

void	double_swap(t_stack **stack_a, t_stack **stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	ft_putendl_fd("ss", 1);
}
