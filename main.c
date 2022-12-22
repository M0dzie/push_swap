/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin42@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:16:26 by thmeyer           #+#    #+#             */
/*   Updated: 2022/12/22 17:35:27 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	count_arg_str(char *argv)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) && !ft_isdigit(argv[i - 1]))
			count++;
// a la place de count++ faudrait mettre le chiffre dans une node
		if (ft_isalpha(argv[i]))
			exit(0);
// free les nodes qui ont deja ete implementees (ft_lstclear ?)
		i++;
	}
	printf("arg_count = %zu\n", count);
	return (count);
} 

int	main(int argc, char **argv)
{
	int		i;
	int		arg_count;
	t_stack	*list;
	t_stack	*new;

	list = NULL;
	i = 2;
	if (argc == 1)
		exit(0);
	if (argc == 2)
	{
		arg_count = count_arg_str(argv[1]);
		// if (check_double_digit(argv[1], arg_count) == 1)
		// 	exit(0);
	}
	// while (argc > i)
	// {
	// 	new = ft_lstnew(argv[i]);
	// 	printf("%s", argv[i]);
	// 	ft_lstadd_back(&list, new);
	// 	i++;
	// }
	return (0);
}

// Parsing les arguments rentrés en paramètre -> les mettre dans des nodes
// Parsing selon deux méthodes : soit argc == 2 et c'est une string (split), ou
// c'est que des int solo
// Gérer les cas d'erreurs : doublons, lettres, aucun arg
// Faire une fonction si tout est déjà dans le bon ordre, du genre already_sort
// Faire une fonction pour 3 et 5 nb a sort et une pour les plus grands nbs