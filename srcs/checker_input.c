/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 17:05:28 by kpucylo           #+#    #+#             */
/*   Updated: 2022/03/03 20:14:33 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

char	**get_instructions(void)
{
	int		i;
	char	*operation;
	char	**instructions;

	i = 0;
	instructions = malloc(sizeof(char *) * 9999);
	operation = get_next_line(0);
	while (operation)
	{
		instructions[i] = operation;
		operation = get_next_line(0);
		i++;
	}
	instructions[i] = 0;
	return (instructions);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	wrong_operation(char **instructions, t_stack *stack_a, t_stack *stack_b)
{
	free_array(instructions);
	throw_error(stack_a, stack_b);
}

void	check_operation(char *operation, char **instructions, \
	t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strncmp(operation, "sa\n", 3))
		sa(stack_a, 0);
	else if (!ft_strncmp(operation, "sb\n", 3))
		sb(stack_b, 0);
	else if (!ft_strncmp(operation, "ss\n", 3))
		ss(stack_a, stack_b, 0);
	else if (!ft_strncmp(operation, "pa\n", 3))
		pa(stack_a, stack_b, 0);
	else if (!ft_strncmp(operation, "pb\n", 3))
		pb(stack_a, stack_b, 0);
	else if (!ft_strncmp(operation, "ra\n", 3))
		ra(stack_a, 0);
	else if (!ft_strncmp(operation, "rb\n", 3))
		rb(stack_b, 0);
	else if (!ft_strncmp(operation, "rr\n", 3))
		rr(stack_a, stack_b, 0);
	else if (!ft_strncmp(operation, "rra\n", 4))
		rra(stack_a, 0);
	else if (!ft_strncmp(operation, "rrb\n", 4))
		rrb(stack_b, 0);
	else if (!ft_strncmp(operation, "rrr\n", 4))
		rrr(stack_a, stack_b, 0);
	else
		wrong_operation(instructions, stack_a, stack_b);
}

void	apply_operations(t_stack *stack_a, t_stack *stack_b, \
	char **instructions)
{
	int	i;

	i = 0;
	while (instructions[i])
	{
		check_operation(instructions[i], instructions, stack_a, stack_b);
		i++;
	}
	free_array(instructions);
}
