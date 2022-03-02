/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplify_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 17:22:03 by kpucylo           #+#    #+#             */
/*   Updated: 2022/03/02 20:10:34 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	stack_len(t_node *top)
{
	int	len;

	len = 0;
	while (top)
	{
		len++;
		top = top->prev;
	}
	return (len);
}

int	*bubble_sort(int *array, int len)
{
	int	i;
	int	temp;
	int	biggest;

	while (len)
	{
		i = 0;
		biggest = array[i];
		while (i < len - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
			i++;
		}
		len--;
	}
	return (array);
}

int	*stack_to_sorted_array(t_node *top)
{
	int		len;
	int		i;
	int		*array;

	len = stack_len(top);
	i = 0;
	array = malloc(sizeof(int) * len);
	while (top)
	{
		array[i] = top->value;
		i++;
		top = top->prev;
	}
	array = bubble_sort(array, len);
	i = 0;
	return (array);
}

void	simplify(t_stack *stack, int argc)
{
	int		*array;
	int		i;
	t_node	*node;

	array = stack_to_sorted_array(stack->top);
	node = stack->top;
	while (node)
	{
		i = 0;
		while (array[i])
		{
			if (array[i] == node->value)
			{
				node->value = i;
				break ;
			}
			i++;
		}
		node = node->prev;
	}
	free(array);
}
