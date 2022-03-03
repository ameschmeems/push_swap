/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:52:46 by kpucylo           #+#    #+#             */
/*   Updated: 2022/03/03 01:44:00 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_pop_top(t_stack *stack)
{
	t_node	*temp;

	if (stack->top == NULL)
		return (-1);
	if (stack->top->next == NULL && stack->top->prev == NULL)
	{
		temp = stack->top;
		stack->top = NULL;
		stack->bottom = NULL;
		free(temp);
		return (0);
	}
	temp = stack->top;
	stack->top = stack->top->prev;
	stack->top->next = NULL;
	free(temp);
	return (0);
}

int	stack_pop_bottom(t_stack *stack)
{
	t_node	*temp;

	if (stack->bottom == NULL)
		return (1);
	if (stack->bottom->next == NULL && stack->bottom->prev == NULL)
	{
		temp = stack->bottom;
		stack->bottom = NULL;
		stack->top = NULL;
		free(temp);
		return (0);
	}
	temp = stack->bottom;
	stack->bottom = stack->bottom->next;
	stack->bottom->prev = NULL;
	free(temp);
	return (0);
}
