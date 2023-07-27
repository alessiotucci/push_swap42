/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:18:35 by atucci            #+#    #+#             */
/*   Updated: 2023/06/26 17:55:43 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft_plus/libft.h"
#include "../incl/push_swap.h"

/*
** Sorts the stack using the push-swap algorithm.
** It moves numbers from stack_a to stack_b and sorts them in stack_b.
** The numbers are then moved back from stack_b to stack_a in the sorted order.
** The algorithm aims to sort the stack with the minimum number of moves.
*/
void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int		pos;    // Position of the smallest element in stack_a.
	int		nb;     // Value of the smallest element in stack_a.
	int		moves;  // Number of rotations needed to bring the smallest element to the top.
	int		count;  // Counter variable.
	int		conto;  // Length of the stack_a.

	conto = update_indexes_and_get_length(*stack_a); // Get the length of stack_a and update its indexes.
	while (conto > 3) // Loop until there are more than 3 elements in stack_a.
	{
		nb = find_small(stack_a, &pos); // Find the smallest element in stack_a and its position.
		moves = get_moves_to_top(*stack_a, pos); // Get the number of rotations needed to bring the smallest element to the top.

		count = -1;
		while (++count < moves) // Rotate stack_a the required number of times to bring the smallest element to the top.
		{
			if (pos <= get_list_length(*stack_a) / 2)
				ra(stack_a, 0); // Rotate stack_a clockwise if the smallest element is closer to the bottom.
			else
				rra(stack_a, 0); // Rotate stack_a counter-clockwise if the smallest element is closer to the top.

			update_indexes(*stack_a); // Update the indexes of stack_a after each rotation.
		}

		pb(stack_a, stack_b, 0); // Push the smallest element from stack_a to stack_b.

		conto = update_indexes_and_get_length(*stack_a); // Get the updated length of stack_a and update its indexes.
	}

	process_stack_b(stack_a, stack_b); // Sort the remaining elements in stack_a and stack_b.
}

/*
** Checks if the stack is sorted in ascending order.
** It traverses the stack and compares adjacent elements.
** Returns 1 if the stack is sorted, 0 otherwise.
*/
int	is_sorted(t_stack *stack_a)
{
	t_stack	*current; // Pointer to traverse the stack.

	current = stack_a;
	while (current != NULL && current->next != NULL)
	{
		// If an element is greater than its next element, the stack is not sorted.
		if (current->nbr > current->next->nbr)
			return (0);

		current = current->next; // Move to the next node in the stack.
	}
	return (1); // If all elements are in ascending order, the stack is sorted.
}

/*
** Finds the largest element in the stack_b and its position.
** It traverses the stack_b to find the largest element and its position (index).
** Returns the value of the largest element.
*/
int	find_big(t_stack **stack_b, int *pos)
{
	int		big;           // Value of the largest element in stack_b.
	t_stack	*current_node; // Pointer to traverse the stack_b.

	*pos = 0;
	big = (*stack_b)->nbr; // Initialize 'big' with the value of the first element in stack_b.
	current_node = *stack_b;

	// Loop through stack_b to find the largest element and its position.
	while (current_node != NULL)
	{
		if (current_node->nbr > big)
		{
			big = current_node->nbr; // Update 'big' with the value of the current element if it is larger.
			*pos = current_node->index; // Update 'pos' with the position of the largest element.
		}
		current_node = current_node->next; // Move to the next node in stack_b.
	}
	return (big); // Return the value of the largest element in stack_b.
}

/*
** Calculates the number of moves needed to bring an element to the top of the stack.
** It calculates the minimum number of clockwise and counter-clockwise rotations
** needed to bring the element with the given 'index' to the top of the 'stack'.
** Returns the number of moves required.
*/
int	get_moves_to_top(t_stack *stack, int index)
{
	int	size;  // Length of the stack.
	int	moves; // Number of moves needed to bring the element to the top.

	moves = 0;
	size = get_list_length(stack); // Get the length of the stack.

	if (index == 0) // If the element is already at the top, no moves are needed.
		return (0);

	if (index <= size / 2) // If the element is closer to the bottom of the stack.
		moves = index; // The number of moves needed is the index itself.
	else // If the element is closer to the top of the stack.
		moves = size - index; // The number of moves needed is the distance from the top.

	return (moves); // Return the number of moves needed to bring the element to the top.
}

/*
** Checks if the stack is empty (contains no elements).
** Returns 0 if the stack is empty, 1 otherwise.
*/
int	is_empty(t_stack **stack)
{
	if ((*stack) == NULL) // If the stack pointer is NULL, the stack is empty.
		return (0); // Return 0 to indicate an empty stack.
	else // If the stack pointer is not NULL, the stack is not empty.
		return (1); // Return 1 to indicate a non-empty stack.
}
