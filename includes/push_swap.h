/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:25:27 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/22 20:44:48 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "../ft_printf/includes/ft_printf.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
}	t_stack;

//create structs
t_node	*node_init(int value);
t_stack	*stack_init(void);

//stack operations
int		stack_push_top(t_stack *stack, int value);
int		stack_push_bottom(t_stack *stack, int value);
int		stack_pop_top(t_stack *stack);
int		stack_pop_bottom(t_stack *stack);
int		stack_peek_top(t_stack *stack);
int		stack_peek_bottom(t_stack *stack);

//algorithm operations
void	sa(t_stack	*stack, int is_called);
void	sb(t_stack	*stack, int is_called);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack, int is_called);
void	rb(t_stack *stack, int is_called);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack, int is_called);
void	rrb(t_stack *stack, int is_called);
void	rrr(t_stack *stack_a, t_stack *stack_b);

//error management
void	check_nums(char **argv);
void	check_size(char **argv);
void	check_duplicates(t_stack *stack, int value);

//sorting
void	sort_small(t_stack *stack_a, int argc);

#endif
