/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:36:10 by thmeyer           #+#    #+#             */
/*   Updated: 2022/12/20 17:49:20 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				*value;
	struct s_stack	*next;
	struct s_stack	*previous;
}					t_stack;

void	double_reverse_rotate(t_stack stack_a, t_stack stack_b);
void	double_rotate(t_stack stack_a, t_stack stack_b);
void	double_swap(t_stack stack_a, t_stack stack_b);
void	push_a(t_stack stack_a);
void	push_b(t_stack stack_b);
void	reverse_rotate_a(t_stack stack_a);
void	reverse_rotate_b(t_stack stack_b);
void	rotate_a(t_stack stack_a);
void	rotate_b(t_stack stack_b);
void	swap_a(t_stack stack_a);
void	swap_b(t_stack stack_b);

#endif