/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpucylo <kpucylo@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:31:49 by kpucylo           #+#    #+#             */
/*   Updated: 2022/02/22 16:27:50 by kpucylo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		temp;

	if (argc > 1)
	{
		stack_a = stack_init();
		stack_b = stack_init();
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
	return (0);
}
