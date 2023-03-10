/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:46:12 by thmeyer           #+#    #+#             */
/*   Updated: 2022/12/29 15:33:44 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief takes as a parameter a node and frees the memory of the node’s content 
 * using the function ’del’ given as a parameter and free the node.ss
 * @param lst the node to free
 * @param del the address of the function used to delete the content
 */
void	ft_lstdelone(t_list *lst)
{
	if (!lst)
		return ;
	lst->content = NULL;
	lst->next = NULL;
	free(lst);
}
