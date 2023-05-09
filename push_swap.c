/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:34:07 by atucci            #+#    #+#             */
/*   Updated: 2023/05/09 15:41:17 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "incl/push_swap.h"
/*int	is_B_sorted(t_stack *stk)
{
	int	i;

	i = 0;
	while (i < stk->lb - 1)
	{
		if (stk->stack_b[i] < stk->stack_b[i + 1])
			return (0);
		i++;
	}
	return (1);
}*/
// The main function of the program, which takes in command-line arguments and performs actions based on them.
int	main(int ac, char *av[])
{
	// Declare a stack variable, I am working  with node of list.
	t_stack *stack_a = malloc(sizeof(t_stack));
	stack_a->nbr = 0;
	stack_a->index = 0;
	stack_a->next = NULL;
	stack_a->prev = NULL;



	// If there are less than 2 arguments, print an error message.
	if (ac < 2)
		return(ft_printf("\tsei\tun\tcojone\n"));
	// If there are exactly 2 arguments, split the numbers in the string argument and store them in the stack.
	if (ac == 2)
	{
		split_num_in_stack(av[1], stack_a);
	}
	// If there are more than 2 arguments, fill the stack with numbers from the arguments.
	else if (ac > 2)
	{
		fill_stack(ac, av, stack_a);
	}
// follia pura 

// TAGLIARE LA TESTA AL  TORO
	testa_toro(&stack_a);

// // follia pura
	// If there are 2 elements in the stack, print a message indicating this.
	if (stack_a->index == 2)
		sort_due(stack_a);
	// If there are 3 elements in the stack, print a message indicating this.
	if (stack_a->index == 3)
		sort_tre(stack_a);
	else if (stack_a->index  > 3)
		sort_stack(stack_a);
	ft_printf("\nAfter the sorting the stack is indeed in order as you can see\n");
	print_stack(stack_a);
	free(stack_a);
	return (0);
}

