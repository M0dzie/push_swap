/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:36:10 by thmeyer           #+#    #+#             */
/*   Updated: 2022/12/30 11:20:07 by thmeyer          ###   ########.fr       */
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

char	double_reverse_rotate(t_list *stack_a, t_list stack_b);
char	double_rotate(t_list *stack_a, t_list *stack_b);
char	double_swap(t_list *stack_a, t_list *stack_b);
char	**parsing_arg(char **argv);
char	push_a(t_list *stack_a, t_list *stack_b);
char	push_b(t_list *stack_b, t_list *stack_a);
char	reverse_rotate_a(t_list *stack_a);
char	reverse_rotate_b(t_list *stack_b);
char	rotate_a(t_list *stack_a);
char	rotate_b(t_list *stack_b);
int		stack_is_sort(t_stack *stack);
char	swap_a(t_list *stack_a);
char	swap_b(t_list *stack_b);

int		check_error(char **all_arg);
int		ps_isdigit(char *str);

t_stack	*stack_last(t_stack *stack);
t_stack	*stack_new(int value);

void	stack_add_back(t_stack **stack, t_stack *new);

#endif