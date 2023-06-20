/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:34:07 by atucci            #+#    #+#             */
/*   Updated: 2023/06/20 10:51:02 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "incl/push_swap.h"

int	has_repetitions(t_stack *stack)
{
	while (stack != NULL)
	{
		t_stack *current = stack->next;
		while (current != NULL)
		{
			if (stack->nbr == current->nbr)
				return (ft_printf("Repetition found\n"));
			current = current->next;
		}
		stack = stack->next;
	}
	return (0); // No repetitions found
}

int get_list_length(t_stack *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// The main function of the program, which takes in command-line arguments and performs actions based on them.
int	main(int ac, char *av[])
{
	// Declare a stack variable, I am working  with node of list.
	t_stack *stack_a = NULL; // = malloc(sizeof(t_stack));
/*	stack_a->nbr = 0;
	stack_a->index = 0;
	stack_a->next = NULL;
	stack_a->prev = NULL;*/

	int	len;
	// If there are less than 2 arguments, print an error message.
	if (ac < 2)
		return(ft_printf("\033[0;31msei\tun cojone!\t\033[0m\n"));
	// If there are exactly 2 arguments, split the numbers in the string argument and store them in the stack.
	if (ac == 2)
		stack_a = split_num_in_stack(av[1]);
	// If there are more than 2 arguments, fill the stack with numbers from the arguments.
	else if (ac > 2)
		stack_a = fill_stack(ac, av);
	if (has_repetitions(stack_a) != 0)
		return (0);
	if (is_sorted(stack_a))
		return (0);
	update_indexes(stack_a);
	//print_stack(&stack_a);
	len = get_list_length(stack_a);
// If there are 2 elements in the stack, print a message indicating this.
	if (len == 2)
		sort_due(&stack_a);
// If there are 3 elements in the stack, print a message indicating this.
	if (len == 3)
		sort_tre(&stack_a);
  //  else if (len > 3)
		//sort_stack(&stack_a);
		
		// lets create a copy of the list;
   
		// lets sort the copy of the list;
	
		// find the mid point in the copy;
		
		//exit(1);
	t_stack *stack_b = (t_stack *)malloc(sizeof(t_stack));
	stack_b = NULL;
    quick_sort(&stack_a, &stack_b);
   
	// for testing puprpse only
	//ft_printf("\nAfter the sorting the stack is indeed in order as you can see\n");
	update_indexes(stack_a);
    //print_stack(&stack_a);
	free(stack_a);
	return (0);
}

