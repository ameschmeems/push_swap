/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_upto5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 01:39:01 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/23 03:21:46 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = current->value;
	while (current)
	{
		if (i > current->value)
			i = current->value;
		current = current->prev;
	}
	return (i);
}

int	find_max(t_stack *stack)
{
	t_node	*current;
	int		i;

	current = stack->top;
	i = current->value;
	while (current)
	{
		if (i < current->value)
			i = current->value;
		current = current->prev;
	}
	return (i);
}

int	closest_above(t_stack *stack, int n)
{
	int		i;
	t_node	*current;

	current = stack->bottom;
	i = find_max(stack);
	while (current)
	{
		if (current->value < i && current->value > n)
			i = current->value;
		current = current->next;
	}
	if (n > i)
		return (find_min(stack));
	return (i);
}

void	smart_rotate(t_stack *stack, int n)
{
	int		i;
	t_node	*current;

	current = stack->top;
	i = current->value;
	if (i == n || current->prev->value == n)
	{
		while (i != n)
		{
			ra(stack, 1);
			current = stack->top;
			i = current->value;
		}
	}
	else
	{
		while (i != n)
		{
			rra(stack, 1);
			current = stack->top;
			i = current->value;
		}
	}
}

void	sort_mid(t_stack *stack_a, t_stack *stack_b, int argc)
{
	int	top;

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	if (argc == 5)
		sort_small(stack_a, 3);
	else if (argc == 6)
		sort_small(stack_a, 4);
	while (stack_b->top)
	{
		top = closest_above(stack_a, stack_peek_top(stack_b));
		smart_rotate(stack_a, top);
		pa(stack_a, stack_b);
	}
	smart_rotate(stack_a, find_min(stack_a));
}
