/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:34:07 by atucci            #+#    #+#             */
/*   Updated: 2023/04/28 15:00:52 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "incl/push_swap.h"

// The main function of the program, which takes in command-line arguments and performs actions based on them.
int	main(int ac, char *av[])
{
	// Declare a variable to keep track of the number of elements in the stack.
	int count;

	// Declare a stack variable with a NULL stack_a to begin with.
	t_stack stack;
	stack.stack_a = NULL;

	// If there are less than 2 arguments, print an error message.
	if (ac < 2)
		ft_printf("sei un cojone");

	// If there are exactly 2 arguments, split the numbers in the string argument and store them in the stack.
	if (ac == 2)
	{
		split_num_in_stack(av[1], &stack);
	}
	// If there are more than 2 arguments, fill the stack with numbers from the arguments.
	else if (ac > 2)
		fill_stack(ac, av, &stack);
	// Initialize a count variable to 0.
	count = 0;
	// Iterate through the elements in stack_a and increment the count variable.
	while (count < stack.la)
		 count++;
	// If there are 2 elements in the stack, print a message indicating this.
	if (count == 2)
		sort_due(&stack);
	// If there are 3 elements in the stack, print a message indicating this.
	if (count  == 3)
		sort_tre(&stack);
	else
		sort_stack(&stack);
	print_stack(&stack);
	free(stack.stack_a);
	return (0);
}

