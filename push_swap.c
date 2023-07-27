/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:34:07 by atucci            #+#    #+#             */
/*   Updated: 2023/06/26 17:56:04 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_plus/libft.h"
#include "incl/push_swap.h"

/*
** Checks if there are any repetitions in the stack.
** It iterates through the stack to find any duplicate numbers.
** If a duplicate number is found, it prints an error message using 'ft_printf'.
** Returns 1 if there are repetitions, otherwise 0.
*/
int	has_repetitions(t_stack *stack)
{
	t_stack	*current;

	while (stack != NULL)
	{
		current = stack->next;
		while (current != NULL)
		{
			if (stack->nbr == current->nbr)
				return (ft_printf("Error\n")); // Print an error message and return 1 if a repetition is found.
			current = current->next;
		}
		stack = stack->next;
	}
	return (0); // Return 0 if there are no repetitions.
}

/*
** Gets the length of the linked list.
** It iterates through the list to count the number of nodes.
** Returns the length of the linked list.
*/
int	get_list_length(t_stack *head)
{
	int	count; // Counter variable.

	count = 0;
	while (head != NULL)
	{
		count++; // Increment the counter for each node in the linked list.
		head = head->next; // Move to the next node.
	}
	update_indexes(head); // Update the indexes of the list nodes.
	return (count); // Return the length of the linked list.
}

/*
** Prints an error message using 'ft_printf' and exits the program with status 0.
*/
int	print_exit(void)
{
	ft_printf("Error\n"); // Print an error message.
	exit(0); // Exit the program with status 0.
}

/*
** The main function of the program.
** It initializes two stacks 'stack_a' and 'stack_b'.
** Reads the command-line arguments and fills 'stack_a' with the provided numbers.
** Performs various sorting algorithms based on the size of the stack.
** Frees the allocated memory for the stacks and exits the program.
*/
int	main(int ac, char *av[])
{
	t_stack	*stack_a; // Pointer to the head of stack A.
	t_stack	*stack_b; // Pointer to the head of stack B.
	int		len;      // Length of the stack_a.

	stack_a = NULL; // Initialize stack_a as an empty linked list.
	stack_b = NULL; // Initialize stack_b as an empty linked list.

	if (ac < 2)
		return (0); // If there are no arguments (except the program name), exit.

	if (ac == 2)
		stack_a = split_num_in_stack(av[1]); // Fill stack_a with numbers provided as a single string.
	else if (ac > 2)
		stack_a = fill_stack(ac, av); // Fill stack_a with numbers provided as individual arguments.

	if (has_repetitions(stack_a) != 0 || is_sorted(stack_a))
		return (free_lists(stack_a, stack_b)); // If there are repetitions or stack_a is already sorted, free the lists and exit.

	len = get_list_length(stack_a); // Get the length of stack_a.

	// Apply appropriate sorting algorithm based on the size of stack_a.
	if (len == 2)
		sort_due(&stack_a); // If stack_a has 2 elements, use sort_due function.
	else if (len == 3)
		sort_tre(&stack_a); // If stack_a has 3 elements, use sort_tre function.
	else if (len < 10)
		sort_stack(&stack_a, &stack_b); // If stack_a has less than 10 elements, use sort_stack function.
	else
		quick_sort(&stack_a, &stack_b); // Otherwise, use quick_sort function.

	free_lists(stack_a, stack_b); // Free the memory allocated for the stacks.
	return (0); // Exit the program with status 0.
}
