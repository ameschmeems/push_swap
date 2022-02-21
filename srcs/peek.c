/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:19:42 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/21 18:28:53 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_peek_top(t_stack *stack)
{
	if (!stack->top)
	{
		if (!stack->bottom)
			return (-1);
		return (0);
	}
	return (stack->top->value);
}

int	stack_peek_bottom(t_stack *stack)
{
	if (!stack->bottom)
	{
		if (!stack->top)
			return (-1);
		return (0);
	}
	return (stack->bottom->value);
}
