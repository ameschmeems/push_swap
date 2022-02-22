/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_upto3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:17:32 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/22 20:55:38 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack *stack_a)
{
	if (stack_peek_top(stack_a) > stack_a->top->prev->value && \
		stack_a->top->prev->value > stack_peek_bottom(stack_a) && \
		stack_peek_top(stack_a) > stack_peek_bottom(stack_a))
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (stack_peek_top(stack_a) > stack_a->top->prev->value && \
		stack_a->top->prev->value < stack_peek_bottom(stack_a) && \
		stack_peek_top(stack_a) > stack_peek_bottom(stack_a))
		ra(stack_a, 1);
	else if (stack_peek_top(stack_a) > stack_a->top->prev->value && \
		stack_a->top->prev->value < stack_peek_bottom(stack_a) && \
		stack_peek_top(stack_a) < stack_peek_bottom(stack_a))
		sa(stack_a, 1);
	else if (stack_peek_top(stack_a) < stack_a->top->prev->value && \
		stack_a->top->prev->value > stack_peek_bottom(stack_a) && \
		stack_peek_top(stack_a) < stack_peek_bottom(stack_a))
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (stack_peek_top(stack_a) < stack_a->top->prev->value && \
		stack_a->top->prev->value > stack_peek_bottom(stack_a))
		rra(stack_a, 1);
}

void	sort_small(t_stack *stack_a, int argc)
{
	if (argc == 3)
	{
		if (stack_peek_top(stack_a) > stack_peek_bottom(stack_a))
			sa(stack_a, 1);
	}
	else if (argc == 4)
	{
		sort_three(stack_a);
	}
}
