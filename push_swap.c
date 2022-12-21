/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:16:26 by thmeyer           #+#    #+#             */
/*   Updated: 2022/12/21 13:32:18 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*list;
	t_stack	*new;

	list = NULL;
	i = 1;
	if (argc < 2)
		return (ft_putendl_fd("Error", 2), 0);
	while (argc > i)
	{
		new = ft_lstnew(argv[i]);
		printf("%s", argv[i]);
		ft_lstadd_back(&list, new);
		i++;
	}
	return (0);
}

// Parsing les arguments rentrés en paramètre -> les mettre dans des nodes
// Parsing selon deux méthodes : soit argc == 2 et c'est une string, ou
// c'est que des int solo
// Gérer les cas d'erreurs : doublons, lettres, aucun arg
// Faire une fonction si tout est déjà dans le bon ordre, du genre already_sort
// Faire une fonction pour 3 et 5 nb a sort et une pour les plus grands nbs