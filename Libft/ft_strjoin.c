/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 09:46:39 by thmeyer           #+#    #+#             */
/*   Updated: 2022/12/29 11:13:51 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * @brief allocates with malloc and returns a new string, which is the result 
 * of the concatenation of ’s1’ and ’s2’
 * @param s1 
 * @param s2 
 * @return the new string or NULL if the allocation fails
 */
char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*join;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 2));
	if (!join)
		return (NULL);
	while (s1[i])
	{
		join[i] = ((char *)s1)[i];
		i++;
	}
	join[i++] = ' ';
	while (s2[j])
	{
		join[i] = ((char *)s2)[j];
		i++;
		j++;
	}
	join[i] = '\0';
	return (free(s1), join);
}
