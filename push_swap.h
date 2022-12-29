/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:36:10 by thmeyer           #+#    #+#             */
/*   Updated: 2022/12/29 15:39:19 by thmeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "Libft/libft.h"

char	double_reverse_rotate(t_list *stack_a, t_list stack_b);
char	double_rotate(t_list *stack_a, t_list *stack_b);
char	double_swap(t_list *stack_a, t_list *stack_b);
char	push_a(t_list *stack_a, t_list *stack_b);
char	push_b(t_list *stack_b, t_list *stack_a);
char	reverse_rotate_a(t_list *stack_a);
char	reverse_rotate_b(t_list *stack_b);
char	rotate_a(t_list *stack_a);
char	rotate_b(t_list *stack_b);
char	swap_a(t_list *stack_a);
char	swap_b(t_list *stack_b);

#endif