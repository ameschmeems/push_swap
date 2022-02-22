/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:19:42 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/22 16:24:22 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	throw_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

long	ft_atol(char *str)
{
	long	value;
	int		i;
	int		sign;

	i = 0;
	value = 0;
	sign = 1;
	while (str[i])
	{
		if (str[i] == '-')
			sign = -1;
		else
		{
			value *= 10;
			value += (str[i] - '0');
		}
		i++;
	}
	value *= sign;
	return (value);
}

void	check_size(char **argv)
{
	long	value;
	int		i;

	i = 1;
	while (argv[i])
	{
		value = ft_atol(argv[i]);
		if (value > INT_MAX || value < INT_MIN)
			throw_error();
		i++;
	}
}

void	check_nums(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && !(argv[i][j] == '-' && j == 0))
				throw_error();
			j++;
		}
		i++;
	}
}

void	check_duplicates(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == value)
			throw_error();
		current = current->prev;
	}
}
