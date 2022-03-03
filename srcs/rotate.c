/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:24:35 by kpucylo           #+#    #+#             */
/*   Updated: 2022/03/03 16:45:51 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack, int is_called)
{
	int	temp;

	if (stack->top && stack->bottom && (stack->top != stack->bottom))
	{
		temp = stack_peek_top(stack);
		stack_pop_top(stack);
		stack_push_bottom(stack, temp);
	}
	if (is_called)
		ft_printf("%s\n", __func__);
}

void	rb(t_stack *stack, int is_called)
{
	int	temp;

	if (stack->top && stack->bottom && (stack->top != stack->bottom))
	{
		temp = stack_peek_top(stack);
		stack_pop_top(stack);
		stack_push_bottom(stack, temp);
	}
	if (is_called)
		ft_printf("%s\n", __func__);
}

void	rr(t_stack *stack_a, t_stack *stack_b, int is_called)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	if (is_called)
		ft_printf("%s\n", __func__);
}
