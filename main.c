/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:16:26 by thmeyer           #+#    #+#             */
/*   Updated: 2022/12/30 11:29:11 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		printf("stack %de : %d\n", i, tmp->value);
		i++;
		tmp = tmp->next;
	}
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
	if (!stack_a)
		return (free(all_arg), 0);
	print_stack(stack_a);
	if (stack_is_sort(stack_a) == -1)
	{
		printf("not sort");
		// sort(stack_a, stack_b);
	}
	return (0);
}

// Faire une fonction pour 3 et 5 nb a sort et une pour les plus grands nbs

// Tout mettre sur la pile B, et check le plus haut et le plus bas de la pile
// puis le mettre sur A : apparemment c'est le moins d'instructions

// Chercher le plus petit élément du tableau, l'échanger avec le premier, 
// recommencer en partant du second élément