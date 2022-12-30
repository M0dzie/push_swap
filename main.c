/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:16:26 by thmeyer           #+#    #+#             */
/*   Updated: 2022/12/30 09:58:46 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_list *stack)
{
	int		i;
	t_list	*tmp;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		printf("stack %de : %s\n", i, tmp->content);
		i++;
		tmp = tmp->next;
	}
}

// int	stack_is_sort(t_list *stack)
// {
// 	return (0);
// }

int	main(int argc, char **argv)
{
	int		j;
	char	**all_arg;
	t_list	*stack_a;
	t_list	*stack_b;

	j = -1;
	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (ft_putstr_fd("Error\n", 2), 0);
	all_arg = parsing_arg(argv);
	while (all_arg[++j])
		ft_lstadd_back(&stack_a, ft_lstnew(all_arg[j]));
	if (!stack_a)
		return (free(all_arg), 0);
	print_stack(stack_a);
	// if (!stack_is_sort(stack_a))
	// 	sort(stack_a, stack_b);
	return (0);
}

// Faire une fonction si tout est déjà dans le bon ordre, du genre already_sort
// Faire une fonction pour 3 et 5 nb a sort et une pour les plus grands nbs

// Tout mettre sur la pile B, et check le plus haut et le plus bas de la pile
// puis le mettre sur A : apparemment c'est le moins d'instructions