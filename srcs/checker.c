/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 16:49:33 by kpucylo           #+#    #+#             */
/*   Updated: 2022/03/03 17:54:32 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	program_init(int argc, char **argv, t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		temp;

	i = 1;
	check_nums(argv, stack_a, stack_b);
	check_size(argv, stack_a, stack_b);
	while (i < argc)
	{
		temp = atoi(argv[i]);
		check_duplicates(stack_a, stack_b, temp);
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
	char	**instructions;

	stack_a = stack_init();
	stack_b = stack_init();
	if (argc > 1)
	{
		program_init(argc, argv, stack_a, stack_b);
		instructions = get_instructions();
		apply_operations(stack_a, stack_b, instructions);
		if (is_sorted(stack_a) && !stack_b->top)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	stack_destroy(stack_a);
	stack_destroy(stack_b);
	return (0);
}
