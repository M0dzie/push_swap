/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:35:41 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/04 17:27:26 by thmeyer          ###   ########.fr       */
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
