/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:16:26 by thmeyer           #+#    #+#             */
/*   Updated: 2022/12/30 12:32:08 by thmeyer          ###   ########.fr       */
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

void	free_tab(char **all_arg)
{
	int	i;

	i = -1;
	while (all_arg[++i])
		free(all_arg[i]);
}

void	free_stack(t_stack *stack)
{
	t_stack	*next_stack;

	if (!stack)
		return ;
	while (stack)
	{
		next_stack = stack->next;
		stack->value = 0;
		stack->next = NULL;
		free(stack);
		stack = next_stack;
	}
	stack = NULL;
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
	print_stack(stack_a);
	if (stack_is_sort(stack_a) == -1)
		printf("not sort");
	// sort(stack_a, stack_b);
	free_stack(stack_a);
	free(stack_b);
	return (0);
}

// Faire une fonction pour 3 et 5 nb a sort et une pour les plus grands nbs

// Tout mettre sur la pile B, et check le plus haut et le plus bas de la pile
// puis le mettre sur A : apparemment c'est le moins d'instructions

// Chercher le plus petit élément du tableau, l'échanger avec le premier, 
// recommencer en partant du second élément