/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:16:26 by thmeyer           #+#    #+#             */
/*   Updated: 2022/12/30 09:15:17 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ps_isdigit(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (!str[i])
		return (1);
	return (0);
}

int	check_error(char **all_arg)
{
	int				i;
	long long int	int_arg;

	i = 0;
	while (all_arg[i])
	{
		if (!ps_isdigit(all_arg[i]))
			return (1);
		int_arg = ft_atoi(all_arg[i]);
		if (int_arg > INT_MAX || int_arg < INT_MIN)
			return (1);
		if (int_arg == ft_atoi(all_arg[i + 1]))
			return (1);
		i++;
	}
	return (0);
}

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

char	**parsing_arg(char **argv)
{
	int		i;
	char	*arg;
	char	**all_arg;

	i = 0;
	arg = malloc(sizeof(char));
	if (!arg)
		return (0);
	while (argv[++i])
	{
		arg = ft_strjoin(arg, argv[i]);
		if (!arg)
			exit(0);
	}
	printf("argument(s) en string : %s\n", arg);
	all_arg = ft_split(arg, ' ');
	if (!all_arg || check_error(all_arg) != 0)
	{
		ft_putstr_fd("Error", 2);
		exit(0);
	}
	for (int h = 0; all_arg[h]; h++)
		printf ("%de argument : %s\n", h, all_arg[h]);
	return (all_arg);
}

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
		return (ft_putstr_fd("Error", 2), 0);
	all_arg = parsing_arg(argv);
	while (all_arg[++j])
		ft_lstadd_back(&stack_a, ft_lstnew(all_arg[j]));
	if (!stack_a)
		return (free(all_arg), 0);
	print_stack(stack_a);
	return (0);
}

// Faire une fonction si tout est déjà dans le bon ordre, du genre already_sort
// Faire une fonction pour 3 et 5 nb a sort et une pour les plus grands nbs

// Tout mettre sur la pile B, et check le plus haut et le plus bas de la pile
// puis le mettre sur A : apparemment c'est le moins d'instructions

// Faire une fonction check pour les doublons et int max int min via la str