/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:06:02 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/21 19:30:50 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (stack_b->top)
	{
		temp = stack_peek_top(stack_b);
		stack_pop_top(stack_b);
		stack_push_top(stack_a, temp);
	}
	ft_printf("%s\n", __func__);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (stack_a->top)
	{
		temp = stack_peek_top(stack_a);
		stack_pop_top(stack_a);
		stack_push_top(stack_b, temp);
	}
	ft_printf("%s\n", __func__);
}
