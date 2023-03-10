/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:09:17 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/10 16:38:17 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		exit(0);
	if (new)
	{
		new->index = index;
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

int	fill_stack_a(t_stack **stack_a, char **all_arg)
{
	int	n_arg;
	int	i;
	int	index;

	n_arg = -1;
	while (all_arg[++n_arg])
	{
		i = 0;
		index = 1;
		while (all_arg[i])
		{
			if (ft_atoi(all_arg[n_arg]) > ft_atoi(all_arg[i]))
				index++;
			i++;
		}
		stack_add_back(&(*stack_a), stack_new(index));
	}
	return (free_tab(all_arg), n_arg);
}
