/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:32:28 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/21 17:51:09 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_push_top(t_stack *stack, int value)
{
	t_node	*node;

	node = node_init(value);
	if (!node)
		return (-1);
	node->prev = stack->top;
	stack->top = node;
	if (!node->prev)
	{
		if (stack->bottom != NULL)
			return (-1);
		stack->bottom = node;
	}
	else
		node->prev->next = node;
	return (0);
}

int	stack_push_bottom(t_stack *stack, int value)
{
	t_node	*node;

	node = node_init(value);
	if (!node)
		return (-1);
	node->next = stack->bottom;
	stack->bottom = node;
	if (!node->next)
	{
		if (stack->top != NULL)
			return (-1);
		stack->top = node;
	}
	else
		node->next->prev = node;
	return (0);
}
