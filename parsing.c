/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 09:54:59 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/02 12:16:34 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_isdigit(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]))
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
	int				j;
	long long int	int_arg;

	i = 0;
	while (all_arg[i])
	{
		if (!ps_isdigit(all_arg[i]))
			return (1);
		int_arg = ft_atoi(all_arg[i]);
		if (int_arg > INT_MAX || int_arg < INT_MIN)
			return (1);
		j = i + 1;
		while (all_arg[j])
		{
			if (int_arg == ft_atoi(all_arg[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

char	**parsing_arg(char **argv)
{
	int		i;
	char	*arg;
	char	**all_arg;

	i = 0;
	arg = malloc(sizeof(char));
	if (!arg)
		exit(0);
	while (argv[++i])
	{
		arg = ft_strjoin(arg, argv[i]);
		if (!arg)
			exit(0);
	}
	all_arg = ft_split(arg, ' ');
	if (!all_arg || check_error(all_arg) != 0)
	{
		ft_putstr_fd("Error\n", 2);
		free_tab(all_arg);
		exit(0);
	}
	return (free(arg), all_arg);
}
