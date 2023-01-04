/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:16:26 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/04 17:37:23 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (stack->index > tmp->index)
			return (-1);
		stack = stack->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		n_arg;
	char	**all_arg;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	if (argc == 2 && !argv[1][0])
		return (ft_putstr_fd("Error\n", 2), 0);
	all_arg = parsing_arg(argv);
	n_arg = fill_stack_a(&stack_a, all_arg);
	if (stack_is_sort(stack_a) == -1)
	{
		if (n_arg <= 5)
			sort_small_amount(&stack_a, &stack_b, n_arg);
		else
			sort_large_amount(&stack_a, &stack_b, n_arg);
	}
	return (free_stack(&stack_a), free(stack_b), 0);
}
