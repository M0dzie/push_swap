/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:09:17 by thmeyer           #+#    #+#             */
/*   Updated: 2022/12/30 11:16:27 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*stack_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		exit(0);
	if (new)
	{
		new->value = value;
		new->next = 0;
	}
	return (new);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last_stack;

	if (!(*stack))
		(*stack) = new;
	else
	{
		last_stack = stack_last((*stack));
		last_stack->next = new;
	}
}

t_stack	*stack_last(t_stack *stack)
{
	t_stack	*last_stack;

	if (!stack)
		return (0);
	while (stack)
	{
		last_stack = stack;
		stack = stack->next;
	}
	return (last_stack);
}
