/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:35:37 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/11 17:18:25 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_b;
	t_stack	*second_b;

	if (!(*stack_b))
		return ;
	first_b = (*stack_b);
	if ((*stack_b)->next)
		second_b = (*stack_b)->next;
	else
		second_b = NULL;
	(*stack_b) = second_b;
	first_b->next = (*stack_a);
	(*stack_a) = first_b;
	ft_putendl_fd("pa", 1);
}

void	push_b(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*first_a;
	t_stack	*second_a;

	if (!(*stack_a))
		return ;
	first_a = (*stack_a);
	if ((*stack_a)->next)
		second_a = (*stack_a)->next;
	else
		second_a = NULL;
	(*stack_a) = second_a;
	first_a->next = (*stack_b);
	(*stack_b) = first_a;
	ft_putendl_fd("pb", 1);
}
