/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:16:26 by thmeyer           #+#    #+#             */
/*   Updated: 2022/12/29 13:09:21 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_stack	*stack_new(int arg)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		new->value = arg;
		new->next = 0;
	}
	return (new);
}

t_stack	*stack_last(t_stack *lst)
{
	t_stack	*last_lst;

	if (!lst)
		return (0);
	while (lst)
	{
		last_lst = lst;
		lst = lst->next;
	}
	return (last_lst);
}

void	stack_add_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_lst;

	if (!(*lst))
		(*lst) = new;
	else
	{
		last_lst = stack_last((*lst));
		last_lst->next = new;
	}
}

void	print_stack(t_stack *stack)
{
	int		i;
	t_stack	*tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		printf("stack %ie : %i\n", i, stack->value);
		i++;
		tmp = tmp->next;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*arg;
	char	**all_arg;
	t_stack	*stack_a;
	t_stack	*stack_b;

	i = 0;
	j = -1;
	stack_a = NULL;
	stack_b = NULL;
	arg = malloc(sizeof(char));
	if (!arg)
		return (0);
	if (argc <= 1)
		return (0);
	if (argc > 1)
	{
		while (argv[++i])
		{
			arg = ft_strjoin(arg, argv[i]);
			if (!arg)
				return (free(arg), 0);
		}
	}
	printf("argument(s) en string : %s\n", arg);
	all_arg = ft_split(arg, ' ');
	for (int h = 0; all_arg[h]; h++)
		printf ("%ie argument : %s\n", h, all_arg[h]);
	while (all_arg[++j])
		stack_add_back(&stack_a, stack_new(ft_atoi(all_arg[j])));
	print_stack(stack_a);
	return (0);
}

// Faire une fonction si tout est déjà dans le bon ordre, du genre already_sort
// Faire une fonction pour 3 et 5 nb a sort et une pour les plus grands nbs

// Tout mettre sur la pile B, et check le plus haut et le plus bas de la pile
// puis le mettre sur A : apparemment c'est le moins d'instructions

// Faire une fonction check pour les doublons et int max int min via la str