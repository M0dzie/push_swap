/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:34:57 by thmeyer           #+#    #+#             */
/*   Updated: 2022/12/29 15:34:23 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief allocates with malloc, 'content' is initialized with the value of 
 * the parameter 'content' and 'next' is initialized to NULL
 * @param content of the new element
 * @return the new node
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		exit(0);
	if (new)
	{
		new->content = content;
		new->next = 0;
	}
	return (new);
}
