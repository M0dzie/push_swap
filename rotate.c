/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:35:44 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/18 15:21:17 by thmeyer          ###   ########.fr       */
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
