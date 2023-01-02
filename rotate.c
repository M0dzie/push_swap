/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:35:44 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/02 10:27:11 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **stack_a)
{
	t_stack	*first_a;
	t_stack	*second_a;

	if (!(*stack_a) || !(*stack_a)->next)
		return ;
	first_a = (*stack_a);
	second_a = (*stack_a)->next;
	stack_add_back(&second_a, first_a);
	(*stack_a) = second_a;
	first_a->next = NULL;
	ft_putendl_fd("ra", 1);
}

void	rotate_b(t_stack **stack_b)
{
	t_stack	*first_b;
	t_stack	*second_b;

	if (!(*stack_b) || !(*stack_b)->next)
		return ;
	first_b = (*stack_b);
	second_b = (*stack_b)->next;
	stack_add_back(&second_b, first_b);
	(*stack_b) = second_b;
	first_b->next = NULL;
	ft_putendl_fd("rb", 1);
}

void	double_rotate(t_stack **stack_a, t_stack **stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
	ft_putendl_fd("rr", 1);
}
