/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:36:10 by thmeyer           #+#    #+#             */
/*   Updated: 2022/12/29 14:33:52 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "Libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

char	double_reverse_rotate(t_stack *stack_a, t_stack stack_b);
char	double_rotate(t_stack *stack_a, t_stack *stack_b);
char	double_swap(t_stack *stack_a, t_stack *stack_b);
char	push_a(t_stack *stack_a, t_stack *stack_b);
char	push_b(t_stack *stack_b, t_stack *stack_a);
char	reverse_rotate_a(t_stack *stack_a);
char	reverse_rotate_b(t_stack *stack_b);
char	rotate_a(t_stack *stack_a);
char	rotate_b(t_stack *stack_b);
char	swap_a(t_stack *stack_a);
char	swap_b(t_stack *stack_b);

t_stack	*stack_last(t_stack *stack);
t_stack	*stack_new(int arg);

void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **stack);
void	stack_delone(t_stack *stack);

#endif