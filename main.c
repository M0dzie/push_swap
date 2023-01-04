/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:16:26 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/04 13:40:13 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	free_tab(char **all_arg)
{
	int	i;

	i = -1;
	while (all_arg[++i])
		free(all_arg[i]);
	free(all_arg);
}

void	free_stack(t_stack **stack)
{
	t_stack	*next_stack;

	while ((*stack))
	{
		next_stack = (*stack)->next;
		free((*stack));
		(*stack) = next_stack;
	}
	(*stack) = NULL;
}

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

void	sorting_global(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (argc <= 5)
		sort_small_amount(&(*stack_a), &(*stack_b), argc);
	// else
	// 	sort_large_amount(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	int		j;
	char	**all_arg;
	t_stack	*stack_a;
	t_stack	*stack_b;

	j = -1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	all_arg = parsing_arg(argv);
	while (all_arg[++j])
		stack_add_back(&stack_a, stack_new(ft_atoi(all_arg[j])));
	free_tab(all_arg);
	if (!stack_a)
		return (0);
	if (stack_is_sort(stack_a) == -1)
		sorting_global(&stack_a, &stack_b, j);
	free_stack(&stack_a);
	free(stack_b);
	return (0);
}
