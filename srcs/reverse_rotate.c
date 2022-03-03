/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:32:42 by kpucylo           #+#    #+#             */
/*   Updated: 2022/03/03 16:45:56 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *stack, int is_called)
{
	int	temp;

	if (stack->top && stack->bottom && (stack->top != stack->bottom))
	{
		temp = stack_peek_bottom(stack);
		stack_pop_bottom(stack);
		stack_push_top(stack, temp);
	}
	if (is_called)
		ft_printf("%s\n", __func__);
}

void	rrb(t_stack *stack, int is_called)
{
	int	temp;

	if (stack->top && stack->bottom && (stack->top != stack->bottom))
	{
		temp = stack_peek_bottom(stack);
		stack_pop_bottom(stack);
		stack_push_top(stack, temp);
	}
	if (is_called)
		ft_printf("%s\n", __func__);
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int is_called)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	if (is_called)
		ft_printf("%s\n", __func__);
}
