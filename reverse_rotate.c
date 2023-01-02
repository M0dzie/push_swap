/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:35:41 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/02 11:11:10 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*last_a;
	t_stack	*second_last_a;

	last_a = stack_last((*stack_a));
	second_last_a = (*stack_a);
	while (second_last_a->next != last_a)
		second_last_a = second_last_a->next;
	second_last_a->next = NULL;
	last_a->next = (*stack_a);
	(*stack_a) = last_a;
	ft_putendl_fd("rra", 1);
}

// void	reverse_rotate_b(t_stack **stack_b)
// {
// 	ft_putendl_fd("rrb", 1);
// }

// void	double_reverse_rotate(t_stack **stack_a, t_stack **stack_b)
// {
// 	reverse_rotate_a(stack_a);
// 	reverse_rotate_b(stack_b);
// 	ft_putendl_fd"rrr", 1);
// }
