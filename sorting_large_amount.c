/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_large_amount.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:21:27 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/30 14:11:02 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_large_amount(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int	i;
	int	i_arg;
	int	index;

	i = 0;
	while (stack_is_sort((*stack_a)) == -1)
	{
		i_arg = 0;
		while (i_arg < argc)
		{
			index = (*stack_a)->index;
			if (index >> i & 1)
				rotate_a(&(*stack_a));
			else
				push_b(&(*stack_b), &(*stack_a));
			i_arg++;
		}
		while ((*stack_b))
			push_a(&(*stack_a), &(*stack_b));
		i++;
	}
}

// void	sort_large_amount(t_stack **stack_a, t_stack **stack_b, int argc)
// {
// 	int	i_arg;
// 	int	i;
// 	int	index;

// (void) stack_b;
// 	i = 0;
// 	// while (stack_is_sort((*stack_a)) == -1)
// 	// {
// 		i_arg = 0;
// 		while (i_arg < argc)
// 		{
// 			index = (*stack_a)->index;
// 			if ((index >> (i * 2) & 3) == 0)
// 				// push_b(stack_b, stack_a);
// 				ft_printf("0\n");
// 			else if ((index >> (i * 2) & 3) == 1)
// 				// rotate_a(stack_a);
// 				ft_printf("1\n");
// 			else if ((index >> (i * 2) & 3) == 2)
// 				// push_b(stack_b, stack_a);
// 				ft_printf("2\n");
// 			else if ((index >> (i * 2) & 3) == 3)
// 				ft_printf("3\n");
// 				// rotate_a(stack_a);
// 			i_arg++;
// 		}
// 	// 	while (*stack_b)
// 	// 		push_a(stack_a, stack_b);
// 	// 	i++;
// 	// }
// }
