/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:31:49 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/23 03:39:07 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	program_init(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	int		temp;

	i = 1;
	check_nums(argv);
	check_size(argv);
	while (i < argc)
	{
		temp = atoi(argv[i]);
		check_duplicates(stack_a, temp);
		stack_push_bottom(stack_a, temp);
		i++;
	}
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;
	int		previous;

	current = stack->top;
	while (current->prev)
	{
		previous = current->value;
		current = current->prev;
		if (previous > current->value)
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = stack_init();
	stack_b = stack_init();
	if (argc > 1)
	{
		program_init(argc, argv, stack_a);
		if (argc < 5 && !is_sorted(stack_a))
			sort_small(stack_a, argc);
		else if ((argc == 5 || argc == 6) && !is_sorted(stack_a))
			sort_mid(stack_a, stack_b, argc);
		else if (!is_sorted(stack_a))
			sort_large(stack_a, stack_b);
	}
	return (0);
}
