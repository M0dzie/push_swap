/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:36:10 by thmeyer           #+#    #+#             */
/*   Updated: 2023/01/04 09:32:06 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "Libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

char	**parsing_arg(char **argv);

int		check_error(char **all_arg);
int		ps_isdigit(char *str);
int		stack_is_sort(t_stack *stack);

t_stack	*stack_last(t_stack *stack);
t_stack	*stack_new(int value);

void	double_reverse_rotate(t_stack **stack_a, t_stack **stack_b);
void	double_rotate(t_stack **stack_a, t_stack **stack_b);
void	double_swap(t_stack **stack_a, t_stack **stack_b);
void	free_stack(t_stack **stack);
void	free_tab(char **all_arg);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_b, t_stack **stack_a);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	sort_five_arg(t_stack **stack_a, t_stack **stack_b);
void	sort_four_arg(t_stack **stack_a, t_stack **stack_b);
void	sort_small_amount(t_stack **stack_a, t_stack **stack_b, int argc);
void	sort_three_arg(t_stack **stack_a);
void	stack_add_back(t_stack **stack, t_stack *new);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);

#endif