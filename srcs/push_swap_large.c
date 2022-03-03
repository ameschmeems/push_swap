/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_large.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 03:35:58 by kpucylo           #+#    #+#             */
/*   Updated: 2022/03/03 02:50:04 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	num_bits(int num)
{
	int	bits;

	bits = 0;
	while ((num >> bits) != 0)
		bits++;
	return (bits);
}

void	sort_large(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	while (!is_sorted(stack_a))
	{
		j = 0;
		while (j < size)
		{
			num = stack_peek_top(stack_a);
			if ((num >> i) & 1 == 1)
				ra(stack_a, 1);
			else
				pb(stack_a, stack_b);
			j++;
		}
		while (stack_b->top)
		{
			pa(stack_a, stack_b);
		}
		i++;
	}
}
