/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:31:49 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/21 19:21:28 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_elements(t_stack *stack)
{
	t_node	*previous;

	previous = stack->top;
	while (previous)
	{
		ft_printf("%i\n", previous->value);
		previous = previous->prev;
	}
}

int	main(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack_init();
	stack_b = stack_init();
	stack_push_top(stack_a, 1);
	stack_push_top(stack_a, 2);
	stack_push_top(stack_a, 3);
	stack_push_top(stack_a, 4);
	stack_push_top(stack_b, 4);
	stack_push_top(stack_b, 3);
	stack_push_top(stack_b, 2);
	stack_push_top(stack_b, 1);
	print_elements(stack_a);
	print_elements(stack_b);
	pa(stack_a, stack_b, 1);
	print_elements(stack_a);
	pb(stack_a, stack_b, 1);
	print_elements(stack_b);
	print_elements(stack_a);
	return (0);
}
