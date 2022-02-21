/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:35:42 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/21 19:07:39 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack	*stack, int is_called)
{
	int	temp;

	if (stack->top && stack->bottom && (stack->top != stack->bottom))
	{
		temp = stack->top->value;
		stack->top->value = stack->top->prev->value;
		stack->top->prev->value = temp;
	}
	if (is_called)
		ft_printf("%s\n", __func__);
}

void	sb(t_stack	*stack, int is_called)
{
	int	temp;

	if (stack->top && stack->bottom && (stack->top != stack->bottom))
	{
		temp = stack->top->value;
		stack->top->value = stack->top->prev->value;
		stack->top->prev->value = temp;
	}
	if (is_called)
		ft_printf("%s\n", __func__);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	ft_printf("%s\n", __func__);
}
